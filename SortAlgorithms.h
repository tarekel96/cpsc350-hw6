#ifndef SORTALGORITHMS_H
#define SORTALGORITHMS_H
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <random>
#include "InputException.h"
class SortAlgorithms{
  private:
    double* m_array;
    int m_size;
    int m_lastIndex;
    string m_file;
    ifstream inFile;
    ofstream outFile;
  public:
    SortAlgorithms(); // default constructor
    SortAlgorithms(string file);
    ~SortAlgorithms(); // destructor
    /* FILE PROCESSOR */
    void processFile(); // populates m_array with file input double values
    /* MUTATOR */
    void setLastIndex();
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
    /* INSERTION SORT */
    void insertionSort(double* array, int size);
    void timeInsertionSort();
    /* BUBBLE SORT */
    void bubbleSort(double* array, int size);
    void timeBubbleSort();
    /* PRINT FUNCTIONS */
    void printArray(); // prints out original array (ordered same as file)
    void printArray(double* arr, int size, bool after); // reusable print function
    /* runs all of the timed sorting algorithms */
    void run();

    void genSampleListFile(int listSize);
    double genRandomDouble(double min, double max);
};
#endif
