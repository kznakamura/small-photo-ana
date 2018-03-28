#include <iostream>
#include <vector>
#include "Root_h.h"

using namespace std;

double GetIntegral (vector<double> wave){

  const int integral_min = 1015, integral_max = 1045;
  double integral = 0;

  for(int i=integral_min; i<integral_max; i++){
    integral += wave[i];
  }
  
  return integral;
}
