TLorentzVector Lorentz(Double_t p[3], Double_t E);
void signaltwophotonbg()  //(const char* filename)
{
  
  /*TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010_pi.root");
  TFile* file1 = new TFile("/home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010_gamma.root");
  TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_gamma = (TTree*)file1->Get("t_gamma");
  */
  TChain *t_pi=new TChain("t_pi","");
  Int_t t= 29;
  Int_t i;
  for(i=10;i<=t;i++){
  	t_pi->Add(Form("/home/usr/data/belle2/mc/BGx1/mugamma1_00%d_BGx1_pi.root",i));
  }
  TChain *t_gamma=new TChain("t_gamma","");
  for(i=10;i<=t;i++){
  	t_gamma->Add(Form("/home/usr/data/belle2/mc/BGx1/mugamma1_00%d_BGx1_gamma.root",i));
  }
  
  //std::string filename = Form("mugamma1");
  std::string filename = Form("mugamma1");
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);
  gStyle->SetStatX(0.5);
  gStyle->SetStatY(0.9);
  TH1* h = new TH1F(("h_"+filename).c_str(), ";rad", 300, 0, 3.14);

  int pi_ncandidates;
  int gamma_ncandidates;

  float pi_evtNum;	float gamma_evtNum;
  float pi_px[100];	float gamma_px[100];
  float pi_py[100];	float gamma_py[100];
  float pi_pz[100];	float gamma_pz[100];
  float pi_E[100];	float gamma_E[100];
  float muid[100];

  int il = 0;
  t_pi->SetBranchAddress("__ncandidates__", &pi_ncandidates);	t_gamma->SetBranchAddress("__ncandidates__", &gamma_ncandidates);  
  t_pi->SetBranchAddress("px", pi_px);				t_gamma->SetBranchAddress("px", gamma_px);
  t_pi->SetBranchAddress("py", pi_py);				t_gamma->SetBranchAddress("py", gamma_py);
  t_pi->SetBranchAddress("pz", pi_pz);				t_gamma->SetBranchAddress("pz", gamma_pz);
  t_pi->SetBranchAddress("E", pi_E);				t_gamma->SetBranchAddress("E", gamma_E);
  t_pi->SetBranchAddress("evtNum", &pi_evtNum);			t_gamma->SetBranchAddress("evtNum", &gamma_evtNum); 
  t_pi->SetBranchAddress("muid", &muid); 
  
  
for(il ; il < t_gamma -> GetEntries();il++){
    		t_gamma -> GetEntry(il);
            for (int im = 0; im < gamma_ncandidates; im++){
					//if(gamma_E[im]<0.8)break;
                    Double_t  pb_1[3] = {gamma_px[im],gamma_py[im],gamma_pz[im]};	//Double_t  p[3] = {0,0,0};
                    TLorentzVector p4b_1 = Lorentz(pb_1,gamma_E[im]);	
                
                    
                    for (int k = 0; k < gamma_ncandidates; k++){
                        if(k==im)continue;
                        Double_t  pb_2[3] = {gamma_px[k],gamma_py[k],gamma_pz[k]};	//Double_t  p[3] = {0,0,0};
                        TLorentzVector p4b_2 = Lorentz(pb_2,gamma_E[k]);
                        
                        Double_t theta_gm = p4b_1.Angle(p4b_2.Vect());
                        h->Fill(theta_gm);
                    }
            }                    
}
  
  for (int i = 0; i < t_pi -> GetEntries(); i++) {
  	t_pi -> GetEntry(i);
    	for(il ; il < t_gamma -> GetEntries();il++){
    		t_gamma -> GetEntry(il);
  		long int i_pi_evtNum = pi_evtNum;
  		long int i_gamma_evtNum = gamma_evtNum;
   		if(pi_evtNum  == gamma_evtNum){
			for (int in = 0; in < pi_ncandidates; in++) {
				if(muid[in]<0.95)break;
			        Double_t  pa[3] = {pi_px[in],pi_py[in],pi_pz[in]};	//Double_t  p[3] = {0,0,0};
    				TLorentzVector p4a = Lorentz(pa,pi_E[in]);	
				for (int im = 0; im < gamma_ncandidates; im++){
					if(gamma_E[im]<0.8)break;
                    /*
                    int bg_gamma = 0;// two photon check
                     for (int k = 0; k < gamma_ncandidates; k++){
                        if(k==im)continue;
                        Double_t  pb_2[3] = {gamma_px[k],gamma_py[k],gamma_pz[k]};	//Double_t  p[3] = {0,0,0};
                        TLorentzVector p4b_2 = Lorentz(pb_2,gamma_E[k]);
                        Double_t theta_gm = p4b_1.Angle(p4b_2.Vect());
                        if(cos(theta_gm)>0.866 && cos(theta_gm)<0.956){
                            bg_gamma = 1;
                            break;
                        }
                        
                    }
                    if(bg_gamma==1) continue;//bg_gamma is 1, two photon
                    */
                    Double_t  pb[3] = {gamma_px[im],gamma_py[im],gamma_pz[im]};	//Double_t  p[3] = {0,0,0};
                    TLorentzVector p4b = Lorentz(pb,gamma_E[im]);	
                    TVector3 vec_mu(p4a[0], p4a[1], p4a[2]);
                    TVector3 vec_gamma(p4b[0], p4b[1], p4b[2]);
					
                    
                    float theta = vec_mu.Angle(vec_gamma);
					float cosign = cos(theta);
					
					float ppisum = p4a[0]*p4a[0] + p4a[1]*p4a[1] + p4a[2]*p4a[2]; ppisum = sqrtf(ppisum);
					float pgammasum = p4b[0]*p4b[0] + p4b[1]*p4b[1] + p4b[2]*p4b[2]; pgammasum = sqrtf(pgammasum);
					float px = p4a[0] + p4b[0];
					float py = p4a[1] + p4b[1];
					float pz = p4a[2] + p4b[2];
					float psum = px*px + py*py + pz*pz; psum = sqrtf(psum);
					float esum = p4a[3] + p4b[3];
					float minvpi = p4a[3]*p4a[3] - ppisum*ppisum; minvpi = sqrtf(minvpi); 
					//if(minvpi<0) cout << "hoge event: minvpi is " << minvpi << endl; 
					float minvgamma = p4b[3]*p4b[3] - pgammasum*pgammasum; 	minvgamma = sqrtf(minvgamma);
					float minv = esum*esum - psum*psum; minv = sqrtf(minv);
					//					float mugammae = p4a[3] + p4b[3];
					//std::cout << "ppisum" << ppisum << std::endl;
					//std::cout << "pgammasum" << pgammasum << std::endl;
					//std::cout << "minvpi" << minvpi << std::endl;
					//std::cout << "minvgamma" << minvgamma << std::endl;
					//std::cout << "p4b[3]" << p4b[3] << std::endl;
					//std::cout << "" << minvgamma << std::endl;[

					//h->Fill(cosign);
				}	
    			}
     			il++;
			break;
		}
    	}
 }
 h->Draw("hist");
 //fout.close();
}
TLorentzVector Lorentz(Double_t p[3], Double_t E)
{
	Double_t P_beam[4] = {0.456369, 0, 2.99742, 11};
	const TLorentzVector p4_beam(P_beam[0], P_beam[1],
	                             P_beam[2], P_beam[3]);
	TLorentzVector  p4(p[0], p[1], p[2], E);
	p4.Boost(-p4_beam.BoostVector());
	return p4;
}
