void Esum_taupair_bg_gamma_fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TChain *t_pi=new TChain("t_pi","");
  Int_t t= 29;
  Int_t i;
  /*for(i=10;i<=t;i++){
  	t_pi->Add(Form("/home/usr/data/belle2/mc/BGx1/mugamma1_00%d_BGx1_pi.root",i));
  }*/
  TChain *t_gamma=new TChain("t_gamma","");
  for(i=10;i<=t;i++){
  	t_gamma->Add(Form("/home/usr/data/belle2/mc/BGx1/mugamma1_00%d_BGx1_gamma.root",i));
  }
   
  std::string filename = Form("mugamma1");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  //TH1* h = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 3);
  //TH1* h = new TH1F(("h_"+filename).c_str(), ";theta", 300, 0, 180);
  //TH1* h = new TH1F(("h_"+filename).c_str(), ";rad", 300, -3.14159265, 3.14159265);

  int pi_ncandidates;
  int gamma_ncandidates;
  //TTree* t_gamma = (TTree*)_file0->Get("t_gamma");
  //ofstream fout("Esum_taupair_bg_gamma.dat");
  TH1* h = new TH1F(("h_"+filename).c_str(), ";Energy[GeV];", 200, 0, 11);

  int ncandidates;
  float E[100];
  float Esum = 0;
  int in;
  t_gamma->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_gamma->SetBranchAddress("E", E);
  for (int i = 0; i < t_gamma->GetEntries(); i++) {
    t_gamma->GetEntry(i); 
    Esum = 0;
    for (in = 0; in < ncandidates; in++) {
    	Esum +=  E[in];  
    }
    //fout << Esum;	fout << "\n";
    if(ncandidates!=0)	h->Fill(Esum);
  }
  //fout.close();
  h->Draw("hist");
}
