#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;
void przyklad()
{
	
  Int_t n=2000,i;

	Float_t x1[2000];
   ifstream d;

   //d.open("density");
   // pod windows
   d.open("M:\\Vsemester\\symulacje\\projekt\\Project1\\Project1\\file.out");
   for(int i=0;i<2000;i=i+1)
     {
	  d>>x1[i];
     }
  d.close();
  TH1F *im1 = new TH1F("im1","histogram ",90,0,90);


   for(i=0;i<2000;i=i+1)
        { 
	  im1->Fill(x1[i]);
	  
	}
	
	im1->SetMaximum(70);
   
   Double_t par[12];
	
   TF1 *g1    = new TF1("g1","gaus",8,12);
   TF1 *g2    = new TF1("g2","gaus",16,22);
   TF1 *g3    = new TF1("g3","gaus",26,32);
   TF1 *g4    = new TF1("g4","gaus",33,90);
   TF1 *total = new TF1("total","gaus(0)+gaus(3)+gaus(6)+gaus(9)",0,90);
   total->SetLineColor(4);
   im1->Fit(g1,"R");
   im1->Fit(g2,"R+");
   im1->Fit(g3,"R+");
   im1->Fit(g4,"R+");
   g1->GetParameters(&par[0]);
   g2->GetParameters(&par[3]);
   g3->GetParameters(&par[6]);
   g4->GetParameters(&par[9]);
   total->SetParameters(par);
   
   TCanvas *canvas = new TCanvas("im1");
   canvas->SetFillColor(0);
   canvas->Divide(1,1);
   canvas->cd(1);
   im1->SetFillColor(2);
   im1->SetFillStyle(3002);
   im1->Fit(total,"R+"); 
}