#include "InputException.h"

InputException::InputException(){}
InputException::~InputException(){}
int InputException::getIntegerInput(){
  int response = -1;
  while(true){
    cin >> response;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    cin.clear();
    cin.ignore(10000,'\n'); 
    break;
  }
  return response;
}
int InputException::getIntegerInput(int min){
  int response = -1;
  while(true){
    cin >> response;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    else{
      if(response < min){
        cerr << "ERROR: INVALID INPUT, INPUT MUST BE GREATER THAN OR EQUAL TO " << to_string(min) << endl;
        continue;
      }
      cin.clear();
      cin.ignore(10000,'\n');
      break;
    }
  }
  return response;
}
string InputException::getStringInput(){
  string response = "";
  while(true){
    cin >> response;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    cin.clear();
    cin.ignore(10000,'\n');
    break;
  }
  return response;
}
double InputException::getDoubleInput(){
  double response = -1.0;
  while(true){
    cin >> response;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    cin.clear();
    cin.ignore(10000,'\n');
    break;
  }
  return response;
}
double InputException::getDoubleInput(double min, double max){
  double response = -1.0;
  while(true){
    cin >> response;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT - PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    else{
      if(response < min){
        cerr << "ERROR: INVALID INPUT, INPUT MUST BE GREATER THAN OR EQUAL TO " << to_string(min) << endl;
        continue;
      }
      else if(response > max){
        cerr << "ERROR: INVALID INPUT, INPUT MUST BE LESS THAN OR EQUAL TO " << to_string(max) << endl;
        continue;
      }
      cin.clear();
      cin.ignore(10000,'\n');
      break;
    }
  }
  return response;
}
