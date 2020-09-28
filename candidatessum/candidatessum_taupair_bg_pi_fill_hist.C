void candidatessum_taupair_bg_pi_fill_hist()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_pi = (TTree*)_file0->Get("t_pi");
  //ofstream fout("Esum_taupair_bg_pi.dat");
  std::string filename = Form("taupair_BGx1_0010.pi.root");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  TH1* h = new TH1F(("h_"+filename).c_str(), ";Candidates;Entryies of taupair bg pi  ", 200, 0, 11);

  int ncandidates;
  float candidatessum = 0;
  float pz = 0;
  t_pi->SetBranchAddress("__ncandidates__", &ncandidates); 
  t_pi->SetBranchAddress("pz", &pz); 
  for (int i = 0; i < t_pi->GetEntries(); i++) {
    t_pi->GetEntry(i); 
    candidatessum = 0;
    for (int in = 0; in < ncandidates; in++) {
    	if(pz > 0.0)candidatessum +=  1;
	cout << pz << "   "  ;
    }
    cout << "\n";
    if(candidatessum != 0)h->Fill(candidatessum);
    candidatessum = 0;
    for (int in = 0; in < ncandidates; in++) {
    	if(pz < 0.0)candidatessum +=  1;
	cout << pz << "   "  ;
    }
    cout << "\n";
    //fout << Esum;	fout << "\n";
    if(candidatessum != 0)h->Fill(candidatessum);
  }
  //fout.close();
  h->Draw("hist");
}
