void candidatessum_mugamma_piandgamma_fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  //TTree* t_pi = (TTree*)_file0->Get("t_pi");
  //TTree* t_gamma = (TTree*)_file1->Get("t_gamma");
  //ofstream fout("Esum_taupair_bg_pi.dat");
  TChain *t_pi=new TChain("t_pi","");
  Int_t t = 29;
  Int_t i;
  for(i=10;i<=t;i++){
  	t_pi->Add(Form("/home/usr/data/belle2/mc/BGx1/mugamma1_00%d_BGx1_pi.root",i));
  }
  TChain *t_gamma=new TChain("t_gamma","");
  //t_gamma->Add("/home/usr/data/belle2/mc/BGx1/mugamma1_0010_BGx1_gamma.root");
  for(i=10;i<=t;i++){
         t_gamma->Add(Form("/home/usr/data/belle2/mc/BGx1/mugamma1_00%d_BGx1_gamma.root",i));
  }
  std::string filename = Form("taupair_BGx1_0010.piandgamma.root");
  std::string cname = filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH1* h = new TH1F((filename).c_str(), ";Candidates;Entryies of pi (one gamma) ", 200, 0, 11);

  int pi_ncandidates;
  int gamma_ncandidates;
  float candidatessum = 0;
  int gamma_candidatesum = 0;
  t_pi->SetBranchAddress("__ncandidates__", &pi_ncandidates); 
  t_gamma->SetBranchAddress("__ncandidates__", &gamma_ncandidates); 
  for (int i = 0; i <= t_pi->GetEntries(); i++) {       //piが0以上の時のループ
    t_gamma->GetEntry(i); 
    candidatessum = 0;
    for (int in = 0; in < gamma_ncandidates; in++) {
    	candidatessum +=  1;                              //一つのエントリのすべてのgammaの数
    }
    //fout << Esum;	fout << "\n";
    h->Fill(candidatessum);
  }
  //fout.close();
  h->Draw("hist");
}
