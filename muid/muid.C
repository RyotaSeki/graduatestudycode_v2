void muid(const std::string filename)  //(const char* filename)
{
  
  //TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010_pi.root");
  //TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_pi = (TTree*)_file0->Get("t_pi");  
  
  //std::string filename = Form("taupair");
  std::string cname = "c_" + filename;
  TCanvas* c1 = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH1* h = new TH1F(("h_"+filename).c_str(), ";value; particle ", 200, 0, 1);

  int ncandidates;
  float E[100];
  float muid[100];
  t_pi->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_pi->SetBranchAddress("E", E);
  t_pi->SetBranchAddress("muid", muid);
  for (int i = 0; i < t_pi->GetEntries(); i++) {
    t_pi->GetEntry(i); 
    for (int in = 0; in < ncandidates; in++) {
    	h -> Fill(muid[in]);  
    }
  }
  h->Draw("hist");
  
}
