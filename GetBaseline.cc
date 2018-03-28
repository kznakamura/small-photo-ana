#include <iostream>
#include <vector>
#include "Root_h.h"

using namespace std;

double GetBaseline (vector<double> wave){

  TH1D *h = new TH1D("h","h",1000,-499,0);
  for(int i=0; i<1015; i++){
    h -> Fill(wave[i]);
  }
  //  cout << h->GetMean() << endl;
  
  double baseline = h->GetMean();
  
  delete h;
  return baseline;
}
