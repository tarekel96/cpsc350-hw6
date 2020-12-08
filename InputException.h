#ifndef INPUTEXCEPTION_H
#define INPUTEXCEPTION_H
#include <exception>
#include <iostream>
using namespace std;
class InputException {
  public:
    InputException();
    ~InputException();
    int getIntegerInput();
    int getIntegerInput(int min);
    string getStringInput();
    double getDoubleInput();
    double getDoubleInput(double min, double max);
  private:
};
#endif
