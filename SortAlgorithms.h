#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H
#include <iostream>
#include <fstream>
#include "InputException.h"
class SortAlgorithms{
  private:
    double* m_array;
    int m_size;
    int m_lastIndex;
    string m_file;
    ifstream inFile;
    InputException IE;
  public:
    SortAlgorithms(); // default constructor
    SortAlgorithms(string file);
    ~SortAlgorithms(); // destructor
    void processFile();
    void setLastIndex();
    int getLastIndex();

    void quickSort(double* array, int start, int end);
    int partition(double* array, int start, int end);
    void swap(double* a, double* b); // helper function to swap two elements 
    void mergeSort(double array);
    void selectionSort(double array);
    void insertionSort(double array);
    void bubbleSort(double array);

    void printArray();
};
#endif