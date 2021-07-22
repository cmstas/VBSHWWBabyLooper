import os
import sys
import ROOT as r

#__________________________________________________________________________________________________________________________
# TH2F -> C++ function dump
# x-axis = pt
# y-axis = eta (abseta)
def dump_hist__pt_v_abseta(h,name,do_errors=False):
    buff = ""
    buff += "float {}(float pt, float abseta) {{\n".format(name)
    for xbin in range(1,h.GetNbinsX()+1):
        for ybin in range(1,h.GetNbinsY()+1):
            if xbin != h.GetNbinsX():
                buff += "   if (pt>={:.3f} && pt<{:.3f}".format(h.GetXaxis().GetBinLowEdge(xbin), h.GetXaxis().GetBinUpEdge(xbin) )
                buff += " && fabs(abseta)>={:.3f} && fabs(abseta)<{:.3f}) return ".format(h.GetYaxis().GetBinLowEdge(ybin), h.GetYaxis().GetBinUpEdge(ybin))
            else:
                buff += "   if (pt>={:.3f}".format(h.GetXaxis().GetBinLowEdge(xbin))
                buff += " && fabs(abseta)>={:.3f} && fabs(abseta)<{:.3f}) return ".format(h.GetYaxis().GetBinLowEdge(ybin), h.GetYaxis().GetBinUpEdge(ybin))
            if do_errors: buff += "{};\n".format(h.GetBinError(xbin,ybin))
            else: buff += "{}; // +-{:.1f}%;\n".format(h.GetBinContent(xbin,ybin),100.0*h.GetBinError(xbin,ybin)/max(1.0e-6,h.GetBinContent(xbin,ybin)))
    buff += "   return 0.;" + "\n"
    buff += "}" + "\n"
    return buff

#__________________________________________________________________________________________________________________________
# TH2F -> C++ function dump
# x-axis = eta
# y-axis = pt
def dump_hist__eta_v_pt(h,name,do_errors=False):
    buff = ""
    buff += "float {}(float eta, float pt) {{\n".format(name)
    maxpt = h.GetYaxis().GetBinUpEdge(h.GetNbinsY())
    buff += "   float pt_ = std::min((double) pt, {:.3f} - 0.001);\n".format(maxpt)
    for xbin in range(1,h.GetNbinsX()+1):
        for ybin in range(1,h.GetNbinsY()+1):
            if xbin != h.GetNbinsX():
                buff += "   if (eta>={:.3f} && eta<{:.3f}".format(h.GetXaxis().GetBinLowEdge(xbin), h.GetXaxis().GetBinUpEdge(xbin) )
                buff += " && pt_>={:.3f} && pt_<{:.3f}) return ".format(h.GetYaxis().GetBinLowEdge(ybin), h.GetYaxis().GetBinUpEdge(ybin))
            else:
                buff += "   if (eta>={:.3f}".format(h.GetXaxis().GetBinLowEdge(xbin))
                buff += " && pt_>={:.3f} && pt_<{:.3f}) return ".format(h.GetYaxis().GetBinLowEdge(ybin), h.GetYaxis().GetBinUpEdge(ybin))
            if do_errors: buff += "{};\n".format(h.GetBinError(xbin,ybin))
            else: buff += "{}; // +-{:.1f}%;\n".format(h.GetBinContent(xbin,ybin),100.0*h.GetBinError(xbin,ybin)/max(1.0e-6,h.GetBinContent(xbin,ybin)))
    buff += "   return 0.;" + "\n"
    buff += "}" + "\n"
    return buff

#__________________________________________________________________________________________________________________________
# Dumping
if __name__ == "__main__":

    # 2018 UL EGamma Reco SF
    f = r.TFile("egammaEffi_ptAbove20.txt_EGM2D_UL2018.root")
    h = f.Get("EGamma_SF2D")
    print(dump_hist__eta_v_pt(h, "getElecRecoEffSFUL2018"))

    # 2017 UL EGamma Reco SF
    f = r.TFile("egammaEffi_ptAbove20.txt_EGM2D_UL2017.root")
    h = f.Get("EGamma_SF2D")
    print(dump_hist__eta_v_pt(h, "getElecRecoEffSFUL2017"))
