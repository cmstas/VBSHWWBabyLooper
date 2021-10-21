def make_table_1D(hist, bin_edges, func_name="table", x_name="x", x_abs=False, 
                  x_type="float", overflow=False):
    
    n_bins, = hist.shape
    if n_bins != len(bin_edges) - 1:
        print("ERROR: hist dimensions do not match given bin edges")
        return None
    cpp = f"\nfloat {func_name}({x_type} {x_name}) {{\n"
    for i in range(n_bins):
        edges = []
        x = x_name if not x_abs else f"abs({x_name})"
        # Low x bin
        edges.append(f"{x} >= {bin_edges[i]:g}")
        if i < n_bins-1 or not overflow:
            # High x bin
            edges.append(f"{x} < {bin_edges[i+1]:g}")
            
        # Add if statement
        condition = " && ".join(edges)
        cpp += f"    if ({condition}) return {hist[i]:g};\n"
    # Add default return
    cpp += "    return 0.0;\n"
    # Wrap up function      
    cpp += "}\n"
    
    return cpp

def make_table_2D(hist, x_bin_edges, y_bin_edges, func_name="table2D", x_name="x", 
                  y_name="y", x_abs=False, y_abs=False, x_type="float", 
                  y_type="float", x_overflow=False, y_overflow=False):
    # Interpret histogram dimensions 
    n_x_bins, n_y_bins = hist.shape
    if n_x_bins != len(x_bin_edges) - 1 or n_y_bins != len(y_bin_edges) - 1:
        print("ERROR: hist dimensions do not match given bin edges")
        return None
    # Build C++ function
    cpp = f"\nfloat {func_name}({x_type} {x_name}, {y_type} {y_name}) {{\n"
    for i in range(n_x_bins):
        for j in range(n_y_bins):
            edges = []
            # Low x bin
            x = x_name if not x_abs else f"fabs({x_name})"
            edges.append(f"{x} >= {x_bin_edges[i]:g}")
            if i < n_x_bins-1 or not x_overflow:
                # High x bin
                edges.append(f"{x} < {x_bin_edges[i+1]:g}")
            # Low y bin
            y = y_name if not y_abs else f"fabs({y_name})"
            edges.append(f"{y} >= {y_bin_edges[j]:g}")
            if j < n_y_bins-1 or not y_overflow:
                # High y bin
                edges.append(f"{y} < {y_bin_edges[j+1]:g}")
            # Add if statement
            condition = " && ".join(edges)
            cpp += f"    if ({condition}) return {hist[i,j]:g};\n"
    # Add default return
    cpp += "    return 0.0;\n"
    # Wrap up function      
    cpp += "}\n"
    
    return cpp

def write_tool(cpp, writemode="w", name="sfTool"):
    with open(f"{name}.cc", writemode) as f_out:
        if writemode == "w":
            f_out.write(f"#include \"{name}.h\"\n")
        f_out.write(cpp)
    
    func_decl = cpp.split(" {")[0].split("\n")[1]
    if writemode == "w":
        func_decl = cpp.split(" {")[0].split("\n")[1]
        with open(f"{name}.h", writemode) as f_out:
            f_out.write(f"#ifndef {name.upper()}_H\n#define {name.upper()}_H\n\n")
            f_out.write(f"{func_decl};\n")
            f_out.write("\n#endif")
    elif writemode == "a":
        with open(f"{name}.h", "r") as f_in:
            h_cpp = "".join(f_in.readlines()[:-1])
        with open(f"{name}.h", "w") as f_out:
            f_out.write(h_cpp)
            f_out.write(f"{func_decl};\n")
            f_out.write("\n#endif")
