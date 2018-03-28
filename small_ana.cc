#include <iostream>
#include <string>
#include <vector>
#include "Root_h.h"


using namespace std;

const int READCH=6;
//const int SAMPLE=2048;

vector<double> GetWave(TTree *rawwave, int ch, int sample);
double GetIntegral(vector<double> wave);

int main(int argc, char* argv[]){
  if(argc!=2){
    cout<<"usage : ./ana_dark (inputfile name)"<<endl;
    return 1;
  }
  string filename = argv[1];

  cout << "Input file: "<<filename<<endl;

  TApplication app( "app", &argc, argv );

  TTree *rawwave;
  TFile *inputfile = new TFile(filename.c_str());
  rawwave = (TTree*)inputfile->Get("rawwave");

  const int ENTRY = rawwave -> GetEntries();

 
  for(int entry = 0; entry < ENTRY; entry++){  
    for(int ch = 0; ch < READCH; ch++){
      const int sample = rawwave -> GetLeaf(Form("ch%d",ch)) -> GetLen();
      //      cout << SAMPLE << endl;
      rawwave->GetEntry(entry);
      
      vector<double> wave = GetWave(rawwave, ch, sample);
      cout << wave.size() << endl;
      
      double integral = GetIntegral(wave);
      cout << integral << endl;
    }
  }
  
  app.Run();
}
