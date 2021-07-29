void print_yield(TString process)
{
    TFile* f = new TFile(Form("hists/Nominal/v2.3_SS/v1/2016/%s.root", process.Data()));
    TH1F* TestEvents__Yield = (TH1F*) f->Get("TestEvents__Yield");
    TH1F* TrainEvents__Yield = (TH1F*) f->Get("TrainEvents__Yield");
    float ntest = TestEvents__Yield->GetBinContent(1);
    float ntrain = TrainEvents__Yield->GetBinContent(1);
    float ntest_err = TestEvents__Yield->GetBinError(1);
    float ntrain_err = TrainEvents__Yield->GetBinError(1);
    float nall = ntest + ntrain;
    float xsec_sf = nall / ntest;
    std::cout <<  " xsec_sf: " << xsec_sf <<  std::endl;
}
