TLorentzVector Lorentz(Double_t p[3], Double_t E);
void allEgammaobcofg()  //(const char* filename)
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
  TH2* h = new TH2F(("h_"+filename).c_str(), ";observation Energy[GeV];center of gravity Energy [GeV]}", 200, 0, 12,200,0,12);

  int ncandidates;
  float E[100];
  float px[100];
  float py[100];
  float pz[100];
  t_gamma->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_gamma->SetBranchAddress("px", px);	
  t_gamma->SetBranchAddress("py", py);
  t_gamma->SetBranchAddress("pz", pz);	
  t_gamma->SetBranchAddress("E", E);
  for (int i = 0; i < t_gamma->GetEntries(); i++) {
    t_gamma->GetEntry(i); 
    for (int in = 0; in < ncandidates; in++) {
    	Double_t p[3] = {px[in],py[in],pz[in]};
        TLorentzVector p4 = Lorentz(p,E[in]);
    	h -> Fill(E[in],p4[3]);  
    }
  }
  h->Draw("hist");
}
TLorentzVector Lorentz(Double_t p[3],Double_t E)
{
	Double_t P_beam[4] = {0.456369, 0, 2.99742, 11};
	const TLorentzVector p4_beam(P_beam[0], P_beam[1],
				     P_beam[2], P_beam[3]);
	TLorentzVector p4(p[0],p[1],p[2],E);
	p4.Boost(-p4_beam.BoostVector());
	return p4;
}
