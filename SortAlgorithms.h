#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H
#include <iostream>
#include <fstream>
#include <ctime>
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
    void processFile(); // processes the input file
    void setLastIndex();
    int getLastIndex();
    void swap(double* a, double* b); // helper function to swap two elements

    /* QUICK SORT */
    void quickSort(double* array, int start, int end);
    int partition(double* array, int start, int end); // helper function
    void timeQuickSort(); // runs and times QuickSort
    /* MERGE SORT */
    void mergeSort(double* array, int firstindex, int lastindex);
    void merge(double* array, int firstindex, int middle, int lastindex);
    void timeMergeSort();
    /* SELECTION SORT */
    void selectionSort(double* array, int size);
    void timeSelectionSort();

    void insertionSort(double* array);
    void bubbleSort(double* array);

    void printArray();
    void printArray(double* arr, int size, bool after); // reusable print function
    void run();
};
#endif
