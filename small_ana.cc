#include <iostream>
#include <string>

#include "Root_h.h"


using namespace std;

void Getwave(string filename);

int main(int argc, char* argv[]){
  if(argc!=2){
    cout<<"usage : ./ana_dark (inputfile name)"<<endl;
    return 1;
  }
  string filename = argv[1];

  cout << "Input file: "<<filename<<endl;

  TApplication app( "app", &argc, argv );

  Getwave(filename);

  
  app.Run();
}
