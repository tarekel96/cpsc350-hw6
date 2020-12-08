#include "SortAlgorithms.h"

SortAlgorithms::SortAlgorithms(){}
SortAlgorithms::SortAlgorithms(string file){
  m_file = file;
  processFile();
  setLastIndex();
  printArray();
  quickSort(m_array, 0, m_lastIndex);
  printArray();
}
SortAlgorithms::~SortAlgorithms(){
  delete m_array;
  inFile.close();
}
void SortAlgorithms::processFile(){
  inFile.open(m_file);
  string currLine;
  int counter = -1;
  while(getline(inFile, currLine)){
    if(counter == -1){
      m_size = stoi(currLine);
      m_array = new double[m_size];
    }
    else{
      m_array[counter] = stod(currLine);
    }
    counter++;
  }
}
void SortAlgorithms::setLastIndex(){
  m_lastIndex = m_size - 1;
}
int SortAlgorithms::getLastIndex(){
  return m_lastIndex;
}
/* takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller than pivot to left of
pivot and all greater elements to right of pivot */
int SortAlgorithms::partition(double* array, int start, int end){
  int pivot = array[end];
  int partitionIndex = start;
  for(int i = start; i < end; ++i){
    if(array[i] <= pivot){
      swap(&array[i], &array[partitionIndex]);
      partitionIndex++;
    }
  }
  swap(&array[partitionIndex], &array[end]);
  return partitionIndex;
}
void SortAlgorithms::swap(double* a, double* b){
  double temp = *a;
  *a = *b;
  *b = temp;
}
void SortAlgorithms::quickSort(double* array, int start, int end){
  if(start < end){
    int partitionIndex = partition(array, start, end);
    quickSort(array, start, partitionIndex - 1);
    quickSort(array, partitionIndex + 1, end);
  }
}
void SortAlgorithms::printArray(){
  for(int i = 0; i < m_size; ++i){
    if(i == 0) cout << "[" << m_array[i] << ", ";
    else if(i == m_lastIndex) cout << m_array[i] << "]\n";
    else cout << m_array[i] << ", ";
  }
}
