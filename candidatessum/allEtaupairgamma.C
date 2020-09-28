void allEtaupairgamma()  //(const char* filename)
{
   
  TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010_gamma.root");
  TTree* t_gamma = (TTree*)file0->Get("t_gamma");
  std::string filename = Form("taupair_bg");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH1* h = new TH1F(("h_"+filename).c_str(), ";Energy[GeV];", 200, 0, 2);

  int ncandidates;
  float E[100];
  t_gamma->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_gamma->SetBranchAddress("E", E);
  for (int i = 0; i < t_gamma->GetEntries(); i++) {
    t_gamma->GetEntry(i); 
    for (int in = 0; in < ncandidates; in++) {
    	h -> Fill(E[in]);  
    }
  }
  h->Draw("hist");
}
