#include <iostream>
#include <vector>
#include "Root_h.h"

using namespace std;

vector<double> GetWave (TTree *rawwave, int ch, int sample){

  vector<double> wave(sample);

  for(int i=0; i<sample; i++){
    wave[i] = rawwave -> GetLeaf(Form("ch%d",ch)) -> GetValue(i);
  }

  return wave;
}
