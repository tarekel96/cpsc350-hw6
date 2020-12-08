#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H
#include <iostream>
#include <fstream>
#include "InputException.h"
class SortAlgorithms{
  private:
    double* m_array;
    int m_size;
    string m_file;
    ifstream inFile;
    InputException IE;
  public:
    SortAlgorithms(); // default constructor
    SortAlgorithms(string file);
    ~SortAlgorithms(); // destructor
    void processFile();

    void quickSort(double array);
    void mergeSort(double array);
    void selectionSort(double array);
    void insertionSort(double array);
    void bubbleSort(double array);

    void printArray();
};
#endif
