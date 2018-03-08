// usage:
// root -l makePlots.C+

#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <math.h>
#include <fstream>
#include <sstream>
#include "TCanvas.h"
#include "TLegend.h"
#include "TChain.h"
#include "TDirectory.h"
#include "TFile.h"
#include "TROOT.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TMath.h"
#include "TPad.h"
#include "TCut.h"
#include "TProfile.h"
#include "THStack.h"
#include "TLatex.h"
#include "TGraphErrors.h"
#include "TStyle.h"
#include "TLine.h"
#include "TMath.h"
#include "TBrowser.h"
#include "string.h"
//#include "TTreeReader.h"
//#include "TTreeReaderValue.h"


using namespace std;

void makePlots(){

   TFile* f = TFile::Open("user.asantra.TestJob.pool.root"); // open output ROOT file, change the filename to match

   //TBrowser b; // create TBrowser

   //f->ls();      // list contents of file

   TTree* CollectionTree = (TTree*) f->Get("CollectionTree");

   CollectionTree->SetScanField(100); // scan 1st 100 entries
				         
   const char* px = "McEventCollection_p5_GEN_EVENT.m_genParticles.m_px";
   const char* py = "McEventCollection_p5_GEN_EVENT.m_genParticles.m_py";
   const char* pz = "McEventCollection_p5_GEN_EVENT.m_genParticles.m_pz";
   const char* mass = "McEventCollection_p5_GEN_EVENT.m_genParticles.m_m";
   const char* status = "McEventCollection_p5_GEN_EVENT.m_genParticles.m_status"; 
   const char* pdgid = "McEventCollection_p5_GEN_EVENT.m_genParticles.m_pdgId";
   
   //const char* cuts = "(abs(McEventCollection_p5_GEN_EVENT.m_genParticles.m_pdgId) == 11) || (abs(McEventCollection_p5_GEN_EVENT.m_genParticles.m_pdgId) == 13) || (abs(McEventCollection_p5_GEN_EVENT.m_genParticles.m_pdgId) == 15)"; // only show SUSY particles
   const char* cuts = "McEventCollection_p5_GEN_EVENT.m_genParticles.m_pdgId > 1000000"; // only show SUSY particles
      
   // see https://root.cern.ch/doc/master/classTTreePlayer.html for scan options
   cout << "PDG_ID, status, mass, pT, eta for pz > 0 , eta for pz < 0, phi" << endl; // print table contents   
   // Scan and print table with PDG_ID, status, mass, pT, eta, phi (SUSY particles only)
   CollectionTree->Scan(Form("%s: %s : %s : pow((%s*%s)+(%s*%s),.5) : -log(tan(atan(pow((%s*%s)+(%s*%s),.5)/%s))/2) : log(tan(atan(pow((%s*%s)+(%s*%s),.5)/abs(%s)))/2) : atan(%s/%s)",pdgid,status,mass,px,px,py,py,px,px,py,py,pz,px,px,py,py,pz,py,px), cuts ,"colsize=15 precision=7");
   
   //CollectionTree->Print();
   
    

   // Make histograms

     TCanvas *c = new TCanvas("c", "Phi", 600, 600);

     TH1F *h_phi = new TH1F("Plot for Phi", "Collection Tree", 100, -5, 5);
    
     CollectionTree->Draw(Form("atan(%s/%s)", py,px)); // make plot for phi

     TCanvas *c2 = new TCanvas("c2", "pT", 600, 600);

     TH1F *h_pT = new TH1F("Plot for pT", "Collection Tree", 100, -5, 5);

     CollectionTree->Draw(Form("pow((%s*%s)+(%s*%s),.5)", px,px,py,py)); // make plot for pT, use editor to scale
    

    // to make a histogram from TTree::Draw some other commands
    // CollectionTree->Draw( Form("%s",px) ); // default binning
    // CollectionTree->Draw( Form("%s>>myhisto(100,-5,5)",px) ); // create myhisto "on the fly"
    // CollectionTree->Draw( Form("%s>>test",px) ); // use previously created histo
    // CollectionTree->Draw( Form("%s",px) , (eventNumber < 50)*WEIGHT ); // default binning

   }
