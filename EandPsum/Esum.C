void Esum()  //(const char* filename)
{
  
  //TFile* file = new TFile(filename);
  TTree* t_pi = (TTree*)_file0->Get("t_pi");
  TTree* t_gamma = (TTree*)_file0->Get("t_gamma");
  //ofstream fout("Esum.dat");
  int pi_ncandidates;
  int gamma_ncandidates;
  float pi_E[100];
  float gamma_E[100];
  float pi_E[100];
  float gamma_E[100];
  float Esum = 0;
  t_pi->SetBranchAddress("__ncandidates__", &pi_ncandidates); 
  t_gamma->SetBranchAddress("__ncandidates__", &gamma_ncandidates); 
  t_pi->SetBranchAddress("E", pi_E);
  t_gamma->SetBranchAddress("E", gamma_E);
  for (int i = 0; i < t_pi->GetEntries(); i++) {
    	t_pi->GetEntry(i);
  	for (int i = 0; i < t_gamma->GetEntries(); i++) {
    		t_pi->GetEntry(i);
		Esum = 0;
    		for (int in = 0; in < pi_ncandidates; in++) {
    		Esum +=  pi_E[in];  
		}
    		for (int in = 0; in < gamma_ncandidates; in++) {
    		Esum +=  gamma_E[in];
		Fill->(Esum);
	}
    }
    //fout << Esum;	fout << "\n";
  }
  //fout.close();
}
