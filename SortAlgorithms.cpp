#include "SortAlgorithms.h"

SortAlgorithms::SortAlgorithms(){}
SortAlgorithms::SortAlgorithms(string file){
  m_file = file;
  processFile();
  setLastIndex();
  timeQuickSort();
  timeMergeSort();
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
void SortAlgorithms::swap(double* a, double* b){
  double temp = *a;
  *a = *b;
  *b = temp;
}
/*
********************QUICK SORT********************
*/
/*takes last element as pivot, places
the pivot element at its correct position in sorted
array, and places all smaller than pivot to left of
pivot and all greater elements to right of pivot*/
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
void SortAlgorithms::quickSort(double* array, int start, int end){
  if(start < end){
    int partitionIndex = partition(array, start, end);
    quickSort(array, start, partitionIndex - 1);
    quickSort(array, partitionIndex + 1, end);
  }
}
void SortAlgorithms::timeQuickSort(){
  double* arrayCopy = new double[m_size];
  for(int i = 0; i < m_size; ++i)
    arrayCopy[i] = m_array[i];
  printArray(arrayCopy, m_size, false);
  clock_t startTime, endTime;
  double cpu_time_used;
  startTime = clock();

  quickSort(arrayCopy, 0, m_lastIndex);

  endTime = clock();
  cpu_time_used = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
  printArray(arrayCopy, m_size, true);
  cout << "Finished QuickSort in " << cpu_time_used << " seconds" << endl;
  delete arrayCopy;
}
/*
********************MERGE SORT********************
*/
void SortAlgorithms::merge(double* array, int firstindex, int middle, int lastindex){
  int x, y, z;
  int subArrayLeftSize = middle - firstindex + 1;
  int subArrayRightSize =  lastindex - middle;

  double leftSubArr[subArrayLeftSize];  //temp array
  double rightSubArr[subArrayRightSize];

  for (x = 0; x < subArrayLeftSize; x++) // copying data to temp arrays
      leftSubArr[x] = array[firstindex + x];
  for (y = 0; y < subArrayRightSize; y++)
      rightSubArr[y] = array[middle + 1+ y];

  x = 0;
  y = 0;
  z = firstindex;
  while(x < subArrayLeftSize && y < subArrayRightSize){
      if(leftSubArr[x] <= rightSubArr[y]){
          array[z] = leftSubArr[x];
          x++;
      }
      else{
          array[z] = rightSubArr[y];
          y++;
      }
      z++;
  }
  while(x < subArrayLeftSize){
      array[z] = leftSubArr[x];
      x++;
      z++;
  }
  while (y < subArrayRightSize){
      array[z] = rightSubArr[y];
      y++;
      z++;
  }
}
void SortAlgorithms::mergeSort(double* array, int firstindex, int lastindex){
  if(firstindex < lastindex){
      int middle = firstindex + (lastindex - firstindex)/2;

      mergeSort(array, firstindex, middle);
      mergeSort(array, middle + 1, lastindex);

      merge(array, firstindex, middle, lastindex);
  }
}
void SortAlgorithms::timeMergeSort(){
  double* arrayCopy = new double[m_size];
  for(int i = 0; i < m_size; ++i)
    arrayCopy[i] = m_array[i];
  printArray(arrayCopy, m_size, false);
  clock_t startTime, endTime;
  double cpu_time_used;
  startTime = clock();

  mergeSort(arrayCopy, 0, m_lastIndex);

  endTime = clock();
  cpu_time_used = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
  printArray(arrayCopy, m_size, true);
  cout << "Finished MergeSort in " << cpu_time_used << " seconds" << endl;
  delete arrayCopy;
}
/*
********************SELECTION SORT********************
*/

void SortAlgorithms::printArray(){
  for(int i = 0; i < m_size; ++i){
    if(i == 0) cout << "[" << m_array[i] << ", ";
    else if(i == m_lastIndex) cout << m_array[i] << "]\n";
    else cout << m_array[i] << ", ";
  }
}
void SortAlgorithms::printArray(double* arr, int size, bool after){

  if(after) cout << "Array after sorting: " << endl;
  else cout << "Array before sorting: " << endl;

  for(int i = 0; i < size; ++i){
    if(i == 0) cout << "[" << arr[i] << ", ";
    else if(i == m_lastIndex) cout << arr[i] << "]\n";
    else cout << arr[i] << ", ";
  }
}
