TLorentzVector Lorentz(Double_t p[3], Double_t E);
void gammacut(const std::string filename)  //(const char* filename)
{
  TTree* t_pi = (TTree*)_file0->Get("t_pi");
  TTree* t_gamma = (TTree*)_file1->Get("t_gamma");
   
  
  std::string cname = "c_" + filename;
  TCanvas* c = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);	//canvasの定義
  //gStyle->SetStatX(0.5);						//canvasのx位置
  //gStyle->SetStatY(0.9);						//canvasのy位置
  TH1* h = new TH1F(("h_"+filename).c_str(), ";gamma E cut ;combination of charged particle and photon", 100, 0, 1);	//ヒストグラムの範囲  
  for(float cut = 0; cut < 1; cut+=0.01)
  {
  int pi_ncandidates;
  int gamma_ncandidates;
  
  long int gme0 = 0;    long int muid0 = 0;
  long int gme2 = 0;    long int muid2 = 0;
  long int gme4 = 0;    long int muid4 = 0;
  long int gme6 = 0;    long int muid6 = 0;
  long int gme8 = 0;    long int muid8 = 0;
  long int gme1 = 0;
  long int gme12 = 0;
  long int gme14 = 0;
  long int gme16 = 0;
  long int gme18 = 0;
  
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
  
    for (int i = 0; i < t_pi -> GetEntries(); i++) {
        t_pi -> GetEntry(i);
        for(il ; il < t_gamma -> GetEntries();il++){
            t_gamma -> GetEntry(il);
            long int i_pi_evtNum = pi_evtNum;
            long int i_gamma_evtNum = gamma_evtNum;
            if(pi_evtNum  == gamma_evtNum){
                
                for (int in = 0; in < pi_ncandidates; in++) {
                    Double_t  pa[3] = {pi_px[in],pi_py[in],pi_pz[in]};	//Double_t  p[3] = {0,0,0};
                    TLorentzVector p4a = Lorentz(pa,pi_E[in]);	

                    for (int im = 0; im < gamma_ncandidates; im++){
                        //if(gamma_E[im]<0.5)break;//mugamma forms candidates required
                        Double_t  pb[3] = {gamma_px[im],gamma_py[im],gamma_pz[im]};	//Double_t  p[3] = {0,0,0};
                        TLorentzVector p4b = Lorentz(pb,gamma_E[im]);
                        
                        
                        
                        TVector3 vec_mu(p4a[0], p4a[1], p4a[2]);
                        TVector3 vec_gamma(p4b[0], p4b[1], p4b[2]);
                        float theta = vec_mu.Angle(vec_gamma);
                        float cosign = cos(theta);
                        
                        //if(cosign>0.78)break;//signal or tag selection
                        
                        
                        float ppisum = p4a[0]*p4a[0] + p4a[1]*p4a[1] + p4a[2]*p4a[2]; ppisum = sqrtf(ppisum);
                        //if(ppisum>5.6)break;
                        float pgammasum = p4b[0]*p4b[0] + p4b[1]*p4b[1] + p4b[2]*p4b[2]; pgammasum = sqrtf(pgammasum);
                        float px = p4a[0] + p4b[0];
                        float py = p4a[1] + p4b[1];
                        float pz = p4a[2] + p4b[2];
                        float psum = px*px + py*py + pz*pz; psum = sqrtf(psum);
                        //if(psum<=4.5)break;//each track must have a momentum
                        
                        
                        

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

                        //h->Fill(minv,esum-(10.573/2));
                        //h->Fill(esum);
                        //h->Fill(minv);
                        //if(minv=>1.65 && minv=<1.85)//std::cout << "1.65-1.85event" << ppisum << std::endl;
                        if(cosign<0)continue;//signal or tag selection
                        //if(muid[in]<0.)continue;
                        //if(muid[in]<cut)continue;
                        if(p4b[3]<cut)continue;
                        h->Fill(cut);
                         
                       
                    }	
                }
                il++;
               
                break;
                 
            }
        }
    }
    if(filename == "uubar")
    std::cout << filename << "  " << cut*100 << "% completed" << std::endl;   
    if(filename == "ssbar")
    std::cout << "                    " << filename << "  " << cut*100 << "% completed" << std::endl;
    if(filename == "ccbar")
    std::cout << "                    " << "                    "<< filename << "  " << cut*100 << "% completed" << std::endl;
    if(filename == "eeee")
    std::cout << "                    " << "                    "<< "                    "<< filename << "  " << cut*100 << "% completed" << std::endl;
    if(filename == "taupair")
    std::cout << "                    " << "                    "<< "                    "<< "                    "<< filename << "  " << cut*100 << "% completed" << std::endl;
 }   
 //h->Print(Form("./png/gammacut%s.png",filename.c_str()));
 h->SaveAs(Form("./png/gammacut%s.pdf",filename.c_str()));
 h->Draw("hist");
    
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
