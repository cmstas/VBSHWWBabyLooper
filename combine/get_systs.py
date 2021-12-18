def get_systs(signal,
              philip_plot_dir="../outputs/histogram/v2.6/miniNtupV3/Run2/HistV2/plots", 
              jonathan_table_dir="../outputs/histogram/v2.6/miniNtupV3/Run2/HistV2/plots",
              doBDT=False):
    bdt_philip_systs = []
    cut_philip_systs = []
    # Parse Philip's table
    if doBDT:
        philip_table = "{}/aexp_bdt.tex".format(philip_plot_dir)
    else:
        philip_table = "{}/aexp_cut.tex".format(philip_plot_dir)
    with open(philip_table, "r") as f_in:
        headers = []
        channel_systs = []
        channel_names = []
        for line in f_in.readlines():
            if "Channels" in line:
                cols = line.split("&")
                header_tex = cols[3].split("$(")[-1].split("))")[0].replace(".", "")
                headers = ["alpha_" + h.lower().replace(" ", "_") for h in header_tex.split(" $\\oplus$ ")]
            else:
                line_no_whitespace = "".join(line.split())
                cols = line_no_whitespace.split("&")
                if len(cols) > 1:
                    channel_tex = cols[0]
                    alpha_ext_syst_tex = cols[3].split("$\\pm$")[-1]
                    _, systs_tex = alpha_ext_syst_tex[:-1].replace("\\%", "").split("(=")
                    systs = [float(s) for s in systs_tex.split("$\\oplus$")]
                    channel_systs.append(systs)
                    channel_names.append(channel_tex)
            if "end" in line and len(headers) != 0:
                philip_systs = []
                for i, header in enumerate(headers):
                    systs = [s[i] for s in channel_systs]
                    philip_systs.append((header, "lnN", [], {signal: 0, "topbkgfit": systs, "bosons": 0}))
                if len(channel_names) == 4 and doBDT:
                    bdt_philip_systs += philip_systs
                elif len(channel_names) == 5 and not doBDT:
                    cut_philip_systs += philip_systs
                headers = []
                channel_systs = []
                channel_names = []
    # Parse Jonathan's tables
    signal_systs = []
    bosons_systs = []
    for table_path_template in ["{0}/{1}_based_bkg_syst.tex", "{0}/{1}_based_sig_syst.tex"]:
        table_path = table_path_template.format(jonathan_table_dir, "bdt" if doBDT else "cut")
        with open(table_path, "r") as f_in:
            for line in f_in.readlines():
                line_no_whitespace = "".join(line.split())
                cols = line_no_whitespace.split("&")
                if len(cols) > 1 and cols[0] != "systematics":
                    header = cols[0]
                    systs = [float(c.replace("\\", "")) if c != "NaN" else 0 for c in cols[1:]]
                    if "bkg" in table_path:
                        bosons_systs.append((header, systs))
                    else:
                        signal_systs.append((header, systs))
    philip_systs = []
    for i, (header, s_systs) in enumerate(signal_systs):
        _header, b_systs = bosons_systs[i]
        if header != _header:
            raise RuntimeError("ERROR: Jonathan's tables are misaligned!")
            return
        philip_systs.append((header+"_syst", "lnN", [], {signal: s_systs, "topbkgfit": 0, "bosons": b_systs}))
    if doBDT:
        bdt_philip_systs += philip_systs
    else:
        cut_philip_systs += philip_systs
    # Deliver the final product
    if doBDT:
        return bdt_philip_systs
    else:
        return cut_philip_systs

if __name__ == "__main__":
    print("Cut-based 'Philip Systematics':")
    systs = get_systs("dummy_signal", doBDT=False)
    for syst in systs:
        print(syst)
    print("BDT-based 'Philip Systematics':")
    systs = get_systs("dummy_signal", doBDT=True)
    for syst in systs:
        print(syst)
