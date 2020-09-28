#include "Thrust.hh"
TLorentzVector Lorentz(Double_t p[3], Double_t E);
void ssbardeltaeminv()  //(const char* filename)
//void eventselection(const std::string filename)
{
  //TFile* file = new TFile(filename);
  //TTree* t_pi = (TTree*)_file0->Get("t_pi");
  //TTree* t_gamma = (TTree*)_file1->Get("t_gamma");
  
 /*
   
  TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/ccbar_BGx1_0010_pi.root");
  TFile* file1 = new TFile("/home/usr/data/belle2/mc/BGx1/ccbar_BGx1_0010_gamma.root");
  TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_gamma = (TTree*)file1->Get("t_gamma");
  */
/*
  TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/ddbar_BGx1_0011_pi.root");
  TFile* file1 = new TFile("/home/usr/data/belle2/mc/BGx1/ddbar_BGx1_0011_gamma.root");
  TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_gamma = (TTree*)file1->Get("t_gamma");
*/
  
  /* 
  TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/ssbar_BGx1_0011_pi.root");
  TFile* file1 = new TFile("/home/usr/data/belle2/mc/BGx1/ssbar_BGx1_0011_gamma.root");
  TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_gamma = (TTree*)file1->Get("t_gamma");
  */

 /*
  TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/uubar_BGx1_0010_pi.root");
  TFile* file1 = new TFile("/home/usr/data/belle2/mc/BGx1/uubar_BGx1_0010_gamma.root");
  TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_gamma = (TTree*)file1->Get("t_gamma");
*/
  

  /* 
  TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/eeee_BGx1_0010_pi.root");
  TFile* file1 = new TFile("/home/usr/data/belle2/mc/BGx1/eeee_BGx1_0010_gamma.root");
  TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_gamma = (TTree*)file1->Get("t_gamma");
*/
  /*
  TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/ee_ecldigits_BGx1_0010_pi.root");
  TFile* file1 = new TFile("/home/usr/data/belle2/mc/BGx1/ee_ecldigits_BGx1_0010_gamma.root");
  TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_gamma = (TTree*)file1->Get("t_gamma");
  */

 /*
  TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/mumu_ecldigits_BGx1_0010_pi.root");
  TFile* file1 = new TFile("/home/usr/data/belle2/mc/BGx1/mumu_ecldigits_BGx1_0010_gamma.root");
  TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_gamma = (TTree*)file1->Get("t_gamma");

*/
 /*
 
  TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/eeisr_BGx1_0010_pi.root");
  TFile* file1 = new TFile("/home/usr/data/belle2/mc/BGx1/eeisr_BGx1_0010_gamma.root");
  TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_gamma = (TTree*)file1->Get("t_gamma");
*/
 
  

/*   
 
  TFile* file0 = new TFile("/home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010_pi.root");
  TFile* file1 = new TFile("/home/usr/data/belle2/mc/BGx1/taupair_BGx1_0010_gamma.root");
  TTree* t_pi = (TTree*)file0->Get("t_pi");
  TTree* t_gamma = (TTree*)file1->Get("t_gamma");

   
*/
  
  
  TChain *t_pi=new TChain("t_pi","");
  Int_t t= 29;
  Int_t i;
  for(i=11;i<=18;i++){
  	t_pi->Add(Form("/home/usr/data/belle2/mc/BGx1/ssbar_BGx1_00%d_pi.root",i));
  }
  for(i=20;i<=22;i++){
  	t_pi->Add(Form("/home/usr/data/belle2/mc/BGx1/ssbar_BGx1_00%d_pi.root",i));
  }
  for(i=24;i<=29;i++){
  	t_pi->Add(Form("/home/usr/data/belle2/mc/BGx1/ssbar_BGx1_00%d_pi.root",i));
  }
  TChain *t_gamma=new TChain("t_gamma","");
  for(i=11;i<=18;i++){
  	t_gamma->Add(Form("/home/usr/data/belle2/mc/BGx1/ssbar_BGx1_00%d_gamma.root",i));
  }
  for(i=20;i<=22;i++){
  	t_gamma->Add(Form("/home/usr/data/belle2/mc/BGx1/ssbar_BGx1_00%d_gamma.root",i));
  }
  for(i=24;i<=29;i++){
  	t_gamma->Add(Form("/home/usr/data/belle2/mc/BGx1/ssbar_BGx1_00%d_gamma.root",i));
  }
  
  
  //std::string filename = Form("ccbar0010");
  //std::string filename = Form("ddbar0011");
  std::string filename = Form("ssbar");
  //std::string filename = Form("uubar0010");
  //std::string filename = Form("eeee0010");
  //std::string filename = Form("ee_ecldigits");
  //std::string filename = Form("mumu_ecldigits");
  //std::string filename = Form("eeisr");
  //std::string filename = Form("mugamma1");
  //std::string filename = Form("taupair0010");
  std::string cname = "c_" + filename;
  TCanvas* c1 = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);	//canvasの定義
  //gStyle->SetStatX(0.5);						//canvasのx位置
  //gStyle->SetStatY(0.9);						//canvasのy位置
  
  //TH1* h = new TH1F(("h_"+filename).c_str(), "muid cut selection;muid cut ;combination of charged particle and photon", 100, 0, 1);	//ヒストグラムの範囲  
  //TH1* h = new TH1F(("h_"+filename).c_str(), "gamma E cut selection;gamma E cut ;combination of charged particle and photon", 100, 0, 1);	//ヒストグラムの範囲  
  
  
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
  //TH1* h = new TH1F(("h_"+filename).c_str(), ";Thrust", 300, 0, 1);	//ヒストグラムの範囲
  
  
  TH2* h = new TH2F(("h_"+filename).c_str(), ";Minv[GeV/c^2];DeltaE[GeV]", 50, 1.7, 1.85,50,-0.4,0.1);	//ヒストグラムの範囲
  
  
  //TH2* h = new TH2F(("h_"+filename).c_str(), ";Minv[GeV];DeltaE[GeV]", 300, 0,3,300,-5,5);	//ヒストグラムの範囲
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
  int select = 0;
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
                std::vector<TVector3> momenta;
                float candidateEsum = 0;
                float candidatePsum = 0;
                        
                for(int io =0;io<pi_ncandidates;io++){		
                    Double_t  pc[3] = {pi_px[io],pi_py[io],pi_pz[io]};	//Double_t  p[3] = {0,0,0};
                    TLorentzVector p4c = Lorentz(pc,pi_E[io]);
                    candidateEsum += p4c[3];
                    candidatePsum += sqrtf(p4c[0]*p4c[0]+p4c[1]*p4c[1]+p4c[2]*p4c[2]);	
                    TVector3 momentum(p4c[0], p4c[1], p4c[2]);
                    momenta.push_back(momentum);
                    
                }
                for (int ip = 0; ip < gamma_ncandidates; ip++){
                    Double_t  pd[3] = {gamma_px[ip],gamma_py[ip],gamma_pz[ip]};	//Double_t  p[3] = {0,0,0};
                    TLorentzVector p4d = Lorentz(pd,gamma_E[ip]);
                    candidateEsum += p4d[3];
                    candidatePsum += sqrtf(p4d[0]*p4d[0]+p4d[1]*p4d[1]+p4d[2]*p4d[2]);
                    TVector3 momentum(p4d[0], p4d[1], p4d[2]);
                    momenta.push_back(momentum);
                          
                }
                TVector3 v = calculateThrust(momenta);
                //h->Fill(v.Mag());
                if(v.Mag() < 0.90 || v.Mag() > 0.92)break;
                for (int in = 0; in < pi_ncandidates; in++) {
                    Double_t  pa[3] = {pi_px[in],pi_py[in],pi_pz[in]};	//Double_t  p[3] = {0,0,0};
                    TLorentzVector p4a = Lorentz(pa,pi_E[in]);

                    for (int im = 0; im < gamma_ncandidates; im++){
                        //if(gamma_E[im]<0.5)break;//mugamma1 forms candidates required
                        Double_t  pb[3] = {gamma_px[im],gamma_py[im],gamma_pz[im]};	//Double_t  p[3] = {0,0,0};
                        TLorentzVector p4b = Lorentz(pb,gamma_E[im]);
                        
                        float gammae=p4b[3];
                        
                        
                        
                        //if(candidateEsum<10.5)break;
                        //if(candidatePsum>5.5)break;
                        
                        TVector3 vec_mu(p4a[0], p4a[1], p4a[2]);
                        //TVector3 vec_mu(p4a[0], p4a[1], p4a[2]);
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
                        
                        
                        if(cosign<0.4||cosign>0.8)continue;//signal or tag selection
                        if(muid[in]<0.95)continue;
                        if(gammae<0.8)continue;
                        
                        
                        if(minv >=1.7 && minv <= 1.85 && deltae >= -0.4 && deltae <= 0.1){
                            h->Fill(minv,deltae);
                            select ++;
                        }
                        
                        //if(minv >=0 && minv <= 3 && deltae >= -5 && deltae <= 5)h->Fill(minv,deltae);
                        
                        //if(muid[in]<cut)continue;
                        //if(p4b[3]<cut)continue;
                        //h->Fill(cut);
                         
                        /*
                        if(muid[in]<0)continue;
                        h->Fill(minv);
                    std::cout << cut*100 << "% completed" << std::endl;       if(minv>=1.65 && minv<=1.85)gme0++;
                        if(muid[in]<0.2)continue;//each photon is requred to have an energy	
                        h1->Fill(minv);str
                        if(minv>=1.65 && minv<=1.85)gme2++;
                        if(muid[in]<0.4)continue;
                        h2->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme4++;
                        if(muid[in]<0.6)continue;
                        h3->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme6++;
                        if(muid[in]<0.8)continue;
                        h4->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme8++;
                        */
                        /*
                        if(p4b[3]<0)continue;
                        h->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme0++;
                        if(p4b[3]<0.2)continue;//each photon is requred to have an energy	
                        h1->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme2++;
                        if(p4b[3]<0.4)continue;
                        h2->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme4++;
                        if(p4b[3]<0.6)continue;
                        h3->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme6++;
                        if(p4b[3]<0.8)continue;
                        h4->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme8++;
                        */
                        
                        /*
                        if(p4b[3]<1.0)continue;
                        h->Fill(minv);
                        
                        if(minv>=1.65 && minv<=1.85)gme0++;
                        if(p4b[3]<1.2)continue;//each photon is requred to have an energy	
                        h1->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme2++;
                        if(p4b[3]<1.4)continue;
                        h2->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme4++;
                        if(p4b[3]<1.6)continue;
                        h3->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme6++;
                        if(p4b[3]<1.8)continue;
                        h4->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme8++;
                        */
                        
                        /*
                        if(p4b[3]<1.0)continue;
                        h1->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme1++;
                        if(p4b[3]<1.2)continue;
                        h1->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme12++;
                        if(p4b[3]<1.4)continue;
                        h1->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme14++;
                        if(p4b[3]<1.6)continue;
                        h1->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme16++;
                        if(p4b[3]<1.8)continue;
                        h1->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)gme18++;
                        */
                        /*
                        if(muid[in]<0.4)continue;
                        h2->Fill(minv);
                        if(muid[in]<0.4)continue;
                        h2->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)muid2++;
                        if(muid[in]<0.6)continue;
                        h3->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)muid3++;
                        if(muid[in]<0.8)continue;
                        h4->Fill(minv);
                        if(minv>=1.65 && minv<=1.85)muid4++;
                        */
                        //if(muid[in]<0.95)continue;//muon identification
                        //h3->Fill(minv);
                    }	
                    //std::cout << cut << " event" << std::endl;
                }
                
                il++;
               
                break;
                 
            }
        }
    /*float percent = 100.0;
    std::cout << std::fixed;
    if(filename == "ccbar0010")
    std::cout <<std::setprecision(1)<< "ccbar " << percent << "%" << std::endl;   
    if(filename == "ddbar0011")
    std::cout <<std::setprecision(1)<< "         " << "ddbar " << percent << "%" << std::endl;
    if(filename == "ssbar0011")
    std::cout <<std::setprecision(1)<< "         " << "         "<< "ssbar " << percent << "%" << std::endl;
    if(filename == "uubar0010")
    std::cout <<std::setprecision(1)<< "         " << "         "<< "         "<< "uubar " << percent << "%" << std::endl;
    if(filename == "eeee0010")
    std::cout <<std::setprecision(1)<< "         " << "         "<< "         "<< "          "<< "eeee " << percent << "%" << std::endl;
    if(filename == "ee_ecldigits")
    std::cout <<std::setprecision(1)<< "         " << "         "<< "         "<< "          "<<"         "<<"         "<< filename << " " << percent << "%" << std::endl;
    if(filename == "mumu_ecldigits")
    std::cout <<std::setprecision(1)<< "         " << "         "<< "         "<< "          "<<"         "<<"         "<<"         "<< filename << " " << percent << "%" << std::endl;
    if(filename == "eeisr")
    std::cout <<std::setprecision(1)<< "         " << "         "<< "         "<< "          "<<"         "<<"         "<<"         "<<"         "<< filename << " " << percent << "%" << std::endl;
    if(filename == "mugamma1")
    std::cout <<std::setprecision(1)<< "         " << "         "<< "         "<< "          "<<"         "<<"         "<<"         "<<"         "<<"         "<< filename << " " << percent << "%" << std::endl;
    if(filename == "taupair0010")
    std::cout <<std::setprecision(1)<< "         " << "         "<< "         "<< "          "<<"          "<<"         "<<"         "<<"         "<<"         "<<"         "<< "taupair " << percent << "%" << std::endl;
 
        */
    }   
 h->Draw("box");
 //h->Draw("hist");
 //c1->SaveAs(Form("./trustvectorpng/%s.png",filename.c_str()));
 c1->SaveAs(Form("./deltaeminvpng/%s.png",filename.c_str()));
 std::cout << filename << "select" << select << std::endl;
 //scanf_s()
 //h1->Draw("same");
 //h2->Draw("same");
 //h3->Draw("same");
 //h4->Draw("same");

 //fout.close();
 /*
 std::cout << "muid0" << muid0 << std::endl;
 std::cout << "muid1" << muid1 << std::endl;
 std::cout << "muid2" << muid2 << std::endl;
 std::cout << "muid3" << muid3 << std::endl;
 std::cout << "muid4" << muid4 << std::endl;
 */
 /*
 std::cout << "gammae0.0<  " << gme0 << std::endl;   
 std::cout << "gammae0.2<  " << gme2 << std::endl;   
 std::cout << "gammae0.4<  " << gme4 << std::endl;   
 std::cout << "gammae0.6<  " << gme6 << std::endl;   
 std::cout << "gammae0.8<  " << gme8 << std::endl;   
 */
 /*
 std::cout << "gme10  " << gme1 << std::endl;   
 std::cout << "gme12  " << gme12 << std::endl;   
 std::cout << "gme14  " << gme14 << std::endl;   
 std::cout << "gme16  " << gme16 << std::endl;   
 std::cout << "gme18  " << gme18 << std::endl;   
 */
    
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
