#include <iostream>
#include "Root_h.h"

using namespace std;

void Getwave (string filename){
  
  TTree *rawwave;
  TFile *inputfile = new TFile(filename.c_str());
  
  rawwave = (TTree*)inputfile->Get("rawwave");
 
  cout << rawwave->GetEntries() << endl;
  
  inputfile -> Close();
  
  
  
  
}
