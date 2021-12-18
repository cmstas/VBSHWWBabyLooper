import numpy as np
import ROOT
import sys

model="C2V"

def plotUpperLimit(mv,lov,lev,lp1v,lp2v,lm1v,lm2v,outname="upperlimit_br",coupling="c2v",ana="bdt"):

    lumi=101

    maxL = 200.0*np.amax(lp2v)
    # maxL = 20000
    minL = 0.1*np.amin(lm2v)
    # maxL = 10
    # minL = 0

    mv = np.array([float(i) for i in list(mv)])

    haxisl=ROOT.TH2D("haxiss","",1,np.amin(mv)*1,np.amax(mv)*1,1,minL,maxL)
    if coupling == "c2v":
        haxisl.GetXaxis().SetTitle("#kappa_{VV}")
    if coupling == "cv":
        haxisl.GetXaxis().SetTitle("#kappa_{V}")
    if coupling == "c3":
        haxisl.GetXaxis().SetTitle("#kappa_{#lambda}")
    haxisl.GetYaxis().SetTitle("95% CLs limit on #sigma(pp#rightarrowW^{#pm}W^{#pm}Hjj) / #sigma_{theory}")
    # if "H" in sys.argv[2]:
    #     if "H2" in sys.argv[2]:
    #         ytitle="#it{B}(h #rightarrow Z_{D}Z_{D}) #it{B}(Z_{D} #rightarrow #mu#mu)"
    #     else:
    #         ytitle="#it{B}(h #rightarrow Z_{D}Z_{D})"
    # else:
    #     haxisl.GetXaxis().SetTitle("m_{#phi} [GeV]")
    #     ytitle="#it{B}(B #rightarrow #phi X) #it{B}(#phi #rightarrow #mu#mu)"
    haxisl.GetXaxis().SetMoreLogLabels()
    haxisl.GetXaxis().SetNoExponent()
    haxisl.GetXaxis().SetLabelSize(0.035)
    haxisl.GetXaxis().SetLabelOffset(0.003)
    haxisl.GetYaxis().SetLabelSize(0.04)
    haxisl.GetXaxis().SetTitleSize(0.047)
    haxisl.GetYaxis().SetTitleSize(0.047)
    haxisl.GetXaxis().SetTitleOffset(0.85)

    if coupling == "cv":
        mask_ranges = [(-0.1, 0.1)]

        box=[]
        for r,m in enumerate(mask_ranges):
            box.append(ROOT.TBox(mask_ranges[r][0],minL+0.001*abs(minL),mask_ranges[r][1],maxL-0.001*maxL))
            box[r].SetFillColor(ROOT.kGray)
            box[r].SetLineColor(ROOT.kGray)
            box[r].SetLineWidth(0)
            box[r].SetFillStyle(1001)

    ROOT.gStyle.SetOptStat(0)
    can = ROOT.TCanvas("can", "", 1500, 1200)
    can.cd()
    # ROOT.gPad.SetLogx()
    ROOT.gPad.SetLogy()
    ROOT.gPad.SetTickx()
    ROOT.gPad.SetTicky()
    can.SetLeftMargin(0.15)
    can.SetRightMargin(0.05)

    haxisl.Draw()

    gr_s2b = ROOT.TGraphAsymmErrors(len(mv),mv,lev,mv-mv,mv-mv,lev-lm2v,lp2v-lev)
    gr_s2b.SetFillColor(ROOT.kOrange)
    gr_s2b.SetLineColor(0)
    gr_s2b.Draw("3")

    gr_s1b = ROOT.TGraphAsymmErrors(len(mv),mv,lev,mv-mv,mv-mv,lev-lm1v,lp1v-lev)
    gr_s1b.SetFillColor(ROOT.kGreen+2)
    gr_s1b.SetLineColor(0)
    gr_s1b.Draw("3")

    gexp = ROOT.TGraph(len(mv),mv,lev)
    gexp.SetLineStyle(7)
    gexp.SetLineWidth(3)
    gexp.SetLineColor(ROOT.kBlack)
    gexp.SetLineStyle(3)
    gexp.SetLineWidth(3)
    gexp.SetLineColor(ROOT.kRed)
    gexp.Draw("L")

    print "Printing expected"
    gexp.Print("all")

    gobs = ROOT.TGraph(len(mv),mv,lov)
    gobs.SetMarkerStyle(ROOT.kFullCircle)
    gobs.SetMarkerSize(1.5)
    gobs.SetMarkerColor(ROOT.kBlack)
    gobs.SetLineWidth(3)
    gobs.SetLineWidth(1)
    gobs.SetLineColor(ROOT.kBlack)
    gobs.Draw("L")

    if coupling == "cv":
        for b in box:
            if b.GetX1()>=(np.amin(mv)*0.99):
                b.Draw("same")

    latex = ROOT.TLatex()
    latex.SetTextFont(42)
    latex.SetTextAlign(31)
    latex.SetTextSize(0.04)
    latex.SetNDC(True)
    latexCMS = ROOT.TLatex()
    latexCMS.SetTextFont(61)
    latexCMS.SetTextSize(0.055)
    latexCMS.SetNDC(True)
    latexCMSExtra = ROOT.TLatex()
    latexCMSExtra.SetTextFont(52)
    latexCMSExtra.SetTextSize(0.03)
    latexCMSExtra.SetNDC(True)

    yearenergy="137 fb^{-1} (13 TeV)"
    latex.DrawLatex(0.95, 0.91, yearenergy)

    latexCMS.DrawLatex(0.15,0.91,"CMS")
    cmsExtra="Preliminary"
    latexCMSExtra.DrawLatex(0.25,0.91,"%s"%(cmsExtra))

    latexModel = ROOT.TLatex()
    latexModel.SetTextFont(42)
    latexModel.SetTextSize(0.05)
    latexModel.SetNDC(True)
    # latexModel.DrawLatex(0.13, 0.825, "%s"%(model))

    l1 = ROOT.TLegend(0.575, 0.675, 0.875, 0.875)
    # if sys.argv[2]=="B" and int(sys.argv[3])==1:
    #     l1 = ROOT.TLegend(0.525, 0.125, 0.775, 0.425)
    l1.SetTextFont(42)
    l1.SetTextSize(0.026)
    l1.SetLineColor(ROOT.kWhite)
    l1.SetShadowColor(ROOT.kWhite)
    l1.SetFillColor(ROOT.kWhite)

    l1.AddEntry(gobs , "Observed limit (95% CL)", "l")
    l1.AddEntry(gexp , "Median expected limit", "l")
    l1.AddEntry(gr_s1b , "68% expected", "f")
    l1.AddEntry(gr_s2b , "95% expected", "f")
    l1.Draw()

    line = ROOT.TLine()
    line.SetLineColor(ROOT.kRed)
    line.DrawLine(np.amin(mv)*1, 1, np.amax(mv)*1, 1)
    # np.amin(mv)*1,np.amax(mv)*1,1,minL,maxL)

    ROOT.gPad.RedrawAxis()

    can.Update()

    can.SaveAs("limit_{}_{}.png".format(coupling, ana))
    can.SaveAs("limit_{}_{}.pdf".format(coupling, ana))

if __name__ == "__main__":

    import sys

    tag = sys.argv[1]
    coupling = sys.argv[2]
    ana = sys.argv[3]

    cmd = "import limits.{}_asymptotic_results as lim".format(tag)

    exec(cmd)

    plotUpperLimit(lim.mv,lim.lov,lim.lev,lim.lp1v,lim.lp2v,lim.lm1v,lim.lm2v,outname="upperlimit_br", coupling=coupling, ana=ana)
