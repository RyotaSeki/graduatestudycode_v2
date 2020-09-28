//#include<omp.h>
TLorentzVector Lorentz(Double_t p[3], Double_t E);
//void eventselection()  //(const char* filename)
void test(const std::string filename)
{
    int nthreds = 4;
    ROOT :: EnableImplicitMT(nthreds);
  //TFile* file = new TFile(filename);
  TTree* t_pi = (TTree*)_file0->Get("t_pi");
  TTree* t_gamma = (TTree*)_file1->Get("t_gamma");
  

  /*
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
*/  
  
  
 
  //std::string filename = Form("%s",filename1.c_str());
  std::string cname = "c_" + filename;
  TCanvas* c1 = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);	//canvasの定義
  //gStyle->SetStatX(0.5);						//canvasのx位置
  //gStyle->SetStatY(0.9);						//canvasのy位置
  //TH1* h = new TH1F(("h_"+filename).c_str(), "two photon event;rad ;combination of two photon", 300, 0, 3.14);	//ヒストグラムの範囲 
  //TH1* h = new TH1F(("h_"+filename).c_str(), "muid cut selection;muid cut ;combination of charged particle and photon", 100, 0, 1);	//ヒストグラムの範囲  
  TH1* h = new TH1F(("h_"+filename).c_str(), "gamma E cut selection;gamma E cut ;combination of charged particle and photon", 100, 0, 1);	//ヒストグラムの範囲  
  /*
  TH1* h = new TH1F(("h_"+filename).c_str(), "muid cut selection;charged particle and photon Minv[GeV/c^2];combination of charged particle and photon", 300, 0, 3);	//ヒストグラムの範囲  
  h->SetFillColor(kRed);
  TH1* h1 = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 3);	//ヒストグラムの範囲
  h1->SetFillColor(kBlue);
  TH1* h2 = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 3);	//ヒストグラムの範囲
  h2->SetFillColor(kGreen);
  TH1* h3 = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 3);	//ヒストグラムの範囲
  h3->SetFillColor(kYellow);
  TH1* h4 = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 3);	//ヒストグラムの範囲
  h4->SetFillColor(kViolet);
  TH1* h9 = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 3);	//ヒストグラムの範囲
  TH1* h5 = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 3);	//ヒストグラムの範囲
  TH1* h6 = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 3);	//ヒストグラムの範囲
  TH1* h7 = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 3);	//ヒストグラムの範囲
  TH1* h8 = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 3);	//ヒストグラムの範囲
  */
  //TH1* h = new TH1F(("h_"+filename).c_str(), ";Minv[GeV]", 300, 0, 20);	//ヒストグラムの範囲
  //TH2* h = new TH2F(("h_"+filename).c_str(), ";Minv[GeV];DeltaE[GeV]", 300, 1.65, 1.85,300,-0.4,0.2);	//ヒストグラムの範囲
  //TH2* h = new TH2F(("h_"+filename).c_str(), ";Minv[GeV];DeltaE[GeV]", 300, 0,3,300,-5,5);	//ヒストグラムの範囲
//#pragma omp parallel for
  for(float cut = 0; cut < 1; cut+=0.01000)
  {
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
    int eventsuu = 0;
    float eventfloat = 0;
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
                    TVector3 vec_mu(p4a[0], p4a[1], p4a[2]);
                    
                    for (int im = 0; im < gamma_ncandidates; im++){
                        //if(gamma_E[im]<0.5)break;//mugamma forms candidates required
                        Double_t  pb[3] = {gamma_px[im],gamma_py[im],gamma_pz[im]};	//Double_t  p[3] = {0,0,0};
                        TLorentzVector p4b = Lorentz(pb,gamma_E[im]);
                        TVector3 vec_gamma(p4b[0], p4b[1], p4b[2]);
                        
                        float candidateEsum = 0;
                        float candidatePsum = 0;
                        for(int io =0;io<pi_ncandidates;io++){		
                            Double_t  pc[3] = {pi_px[io],pi_py[io],pi_pz[io]};	//Double_t  p[3] = {0,0,0};
                            TLorentzVector p4c = Lorentz(pc,pi_E[io]);
                            candidateEsum += p4c[3];
                            candidatePsum += sqrtf(p4c[0]*p4c[0]+p4c[1]*p4c[1]+p4c[2]*p4c[2]);
                        }
                        for (int ip = 0; ip < gamma_ncandidates; ip++){
                            Double_t  pd[3] = {gamma_px[ip],gamma_py[ip],gamma_pz[ip]};	//Double_t  p[3] = {0,0,0};
                            TLorentzVector p4d = Lorentz(pd,gamma_E[ip]);
                            candidateEsum += p4d[3];
                            candidatePsum += sqrtf(p4d[0]*p4d[0]+p4d[1]*p4d[1]+p4d[2]*p4d[2]);
                            TVector3 vec_gamma1(p4d[0], p4d[1], p4d[2]);
                            float twophotontheta = vec_gamma.Angle(vec_gamma1);
                            //if(ip != im)h->Fill(twophotontheta);
                        }
                        //if(candidateEsum<10.5)break;
                        //if(candidatePsum>5.5)break;
                        
                        
                        //TVector3 vec_mu(p4a[0], p4a[1], p4a[2]);
                        
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
                        float deltae = esum-(10.573/2);
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
                        
                        if(muid[in]<cut)continue;
                        //if(p4b[3]<cut)continue;
                        if(minv >=1.7 && minv <= 1.85 && deltae >= -0.4 && deltae <= 0.1)h->Fill(cut);
                    }	
                
                
                }
                il++;
               
                break;
                 
            }
        }
        eventsuu ++;
        eventfloat ++;
        float percent = cut * 100.0 ;
        std::cout << std::fixed;
    if(filename == "ccbar0010"&& eventsuu % 14671==0)
    std::cout <<std::setprecision(1)<< "ccbar " << percent+eventsuu/146710 << "%" << std::endl;   
    if(filename == "ddbar0011"&& eventsuu %17788==0)
    std::cout <<std::setprecision(1)<< "           " << "ddbar " << percent+eventfloat/177880 << "%" << std::endl;
    if(filename == "ssbar0011"&& eventsuu %17042==0)
    std::cout <<std::setprecision(1)<< "           " << "          "<< "ssbar " << percent+eventfloat/170422 << "%" << std::endl;
    if(filename == "uubar0010"&& eventsuu %20767==0)
    std::cout <<std::setprecision(1)<< "           " << "          "<< "          "<< "uubar " << percent+eventfloat/207674 << "%" << std::endl;
    if(filename == "eeee0010"&& eventsuu %21000==0)
    std::cout <<std::setprecision(1)<< "           " << "          "<< "          "<< "           "<< "eeee " << percent+eventfloat/210000 << "%" << std::endl;
    if(filename == "ee_ecldigits0010"&& eventsuu %5400==0)
    std::cout <<std::setprecision(1)<< "           " << "          "<< "          "<< "           "<<"          "<<"ee_ecldigits " << percent+eventfloat/540000 << "%" << std::endl;
    if(filename == "mumu_ecldigits0010"&& eventsuu %5600==0)
    std::cout <<std::setprecision(1)<< "           " << "          "<< "          "<< "           "<<"          "<<"                  "<<"mumu_ecldigits " << percent+eventfloat/560000 << "%" << std::endl;
    if(filename == "eeisr0010"&& eventsuu %24924==0)
    std::cout <<std::setprecision(1)<< "           " << "          "<< "          "<< "           "<<"          "<<"                  "<<"                    "<<"eeisr "<< percent+eventfloat/249245 << "%" << std::endl;
    if(filename == "taupair0010"&& eventsuu %21000==0)
    std::cout <<std::setprecision(1)<< "           " << "          "<< "          "<< "           "<<"          "<<"                  "<<"                    "<<"           "<< "taupair " << percent+eventfloat/210000 << "%" << std::endl;
    if(filename == "mugamma1"&& eventsuu %40000==0)
    std::cout <<std::setprecision(1)<< "           " << "          "<< "          "<< "           "<<"          "<<"                  "<<"                    "<<"           "<<"              "<< filename << " " << percent+eventfloat/40000 << "%" << std::endl;  
        
 
    
    
    
    }
    /*
    float percent = cut * 100.0;
    std::cout << std::fixed;
    if(filename == "ccbar0010")
    std::cout <<std::setprecision(1)<< "ccbar " << percent << "%" << std::endl;   
    if(filename == "ddbar0011")
    std::cout <<std::setprecision(1)<< "            " << "ddbar " << percent << "%" << std::endl;
    if(filename == "ssbar0011")
    std::cout <<std::setprecision(1)<< "            " << "             "<< "ssbar " << percent << "%" << std::endl;
    if(filename == "uubar0010")
    std::cout <<std::setprecision(1)<< "            " << "             "<< "             "<< "uubar " << percent << "%" << std::endl;
    if(filename == "eeee0010")
    std::cout <<std::setprecision(1)<< "            " << "             "<< "             "<< "             "<< "eeee " << percent << "%" << std::endl;
    if(filename == "ee_ecldigits0010")
    std::cout <<std::setprecision(1)<< "            " << "             "<< "             "<< "             "<<"             "<<"ee_ecldigits " << percent << "%" << std::endl;
    if(filename == "mumu_ecldigits0010")
    std::cout <<std::setprecision(1)<< "            " << "             "<< "             "<< "             "<<"             "<<"                     "<<"mumu_ecldigits " << percent << "%" << std::endl;
    if(filename == "eeisr0010")
    std::cout <<std::setprecision(1)<< "            " << "             "<< "             "<< "             "<<"             "<<"                     "<<"                       "<<"eeisr "<< percent << "%" << std::endl;
    if(filename == "taupair0010")
    std::cout <<std::setprecision(1)<< "            " << "             "<< "             "<< "             "<<"             "<<"                     "<<"                       "<<"              "<< "taupair " << percent << "%" << std::endl;
    if(filename == "mugamma1")
    std::cout <<std::setprecision(1)<< "            " << "             "<< "             "<< "             "<<"             "<<"                     "<<"                       "<<"              "<<"              "<< filename << " " << percent << "%" << std::endl;    
 */
      
}
 h->Draw("hist");
 c1->SaveAs(Form("./muidcutpng/%s.png",filename.c_str()));
    
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
