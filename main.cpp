#include <iostream>
#include "SortAlgorithms.h"
#include "FileError.h"
using namespace std;

int main(int argc, char ** argv){

  FileError* FE; /* used to check file input */
  SortAlgorithms* sortAlgos;
  if(argc > 1){  /* if console argument provided */
    FE = new FileError(argv[1]);

    if(FE->pass() == false){
      while(true){
        FE->setFile(FE->getFile());
        if(FE->pass()) break;
      }
    }
  }
  else{ // if no console arguments were provided
    FE = new FileError();

    if(FE->pass() == false){
      while(true){
        FE->setFile(FE->getFile());
        if(FE->pass()) break;
      }
    }
  }
  // at this point, know the file provided by user is invalid
  string file = FE->getFileValue();
  sortAlgos = new SortAlgorithms(file);

  return 0;
}
