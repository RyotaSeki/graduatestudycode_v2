void allEgamma_value_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  //TTree* t_pi = (TTree*)_file0->Get("t_pi");
  /*
  TChain *t_pi =new TChain("t_pi","");
  Int_t t = 29;
  Int_t i;
  for(i=10;i<=t;i++){
  	t_pi->Add(Form("/home/usr/data/belle2/mc/BGx1/mugamma1_00%d_BGx1_pi.root",i));
  }
  */
  TChain *t_gamma =new TChain("t_gamma","");
  Int_t t = 29;
  Int_t i;
  for(i=10;i<=t;i++){
  	t_gamma->Add(Form("/home/usr/data/belle2/mc/BGx1/mugamma1_00%d_BGx1_gamma.root",i));
  }
  std::string filename = Form("mugamma1");
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
