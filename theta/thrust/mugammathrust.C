#include "Thrust.hh"
TLorentzVector Lorentz(Double_t p[3], Double_t E);
void mugammathrust()  //(const char* filename)
//void eventselection(const std::string filename)
{
  
  
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
  
  
  std::string filename = Form("mugamma1");
  //std::string filename = Form("taupair0010");
  std::string cname = "c_" + filename;
  TCanvas* c1 = new TCanvas(cname.c_str(), cname.c_str(), 840, 560);	//canvasの定義
  
  TH1* h = new TH1F(("h_"+filename).c_str(), ";Thrust", 300, 0, 1);	//ヒストグラムの範囲
  
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
    for (int i = 0; i < t_pi -> GetEntries(); i++) {
        t_pi -> GetEntry(i);
        std::cout << i << " entry" << std::endl;
        for(il ; il < t_gamma -> GetEntries();il++){
            t_gamma -> GetEntry(il);
            long int i_pi_evtNum = pi_evtNum;
            long int i_gamma_evtNum = gamma_evtNum;
            if(pi_evtNum  == gamma_evtNum){
                std::vector<TVector3> momenta;
                
                for (int in = 0; in < pi_ncandidates; in++) {
                    Double_t  pa[3] = {pi_px[in],pi_py[in],pi_pz[in]};	//Double_t  p[3] = {0,0,0};
                    TLorentzVector p4a = Lorentz(pa,pi_E[in]);	
                    TVector3 momentum(p4a[0], p4a[1], p4a[2]);
                    momenta.push_back(momentum);
                }
                    for (int im = 0; im < gamma_ncandidates; im++){
                        //if(gamma_E[im]<0.5)break;//mugamma1 forms candidates required
                        Double_t  pb[3] = {gamma_px[im],gamma_py[im],gamma_pz[im]};	//Double_t  p[3] = {0,0,0};
                        TLorentzVector p4b = Lorentz(pb,gamma_E[im]);
                        TVector3 momentum(p4b[0], p4b[1], p4b[2]);
                        momenta.push_back(momentum);
                        
                      
                    }	
                    //std::cout << cut << " event" << std::endl;
                
                TVector3 v = calculateThrust(momenta);
                h->Fill(v.Mag());
                il++;
               
                break;
                 
            }
        }
    
    }   
    
    
 //h->Draw("box");
 h->SetLineWidth(4);
 h->Draw("hist");
 c1->SaveAs(Form("./trustvectorpng/%s.png",filename.c_str()));
 
    
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
