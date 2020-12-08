#include "FileError.h"
/* Default Constructor */
FileError::FileError(){}
/* Overload Constructor */
/* sets the m_file to the parameter */
/*
  * @param file - the name of the file to check
*/
FileError::FileError(string file){
  setFile(file);
}
/* Destructor */
FileError::~FileError(){}
string FileError::getFileValue(){
  return m_file;
}
/* MUTATOR */
/*
  * @param file - the name of the file
*/
void FileError::setFile(string file){
  m_file = file;
}
/* HELPER FUNCTIONS */
/* prompt the user for name of the file to check */
string FileError::getFile(){
  string file;
  cout << "PLEASE ENTER THE NAME OF THE FILE: " << endl;
  cin >> file;
  return file;
};
/* opens a file and checks if it fails - returns true if successful and false if it failed to open the file */
int FileError::checkFile(){
  m_inFile.open(m_file);
  if(m_inFile.fail()){
    cerr << "ERROR IN OPENING THE FILE.\nPLEASE MAKE SURE YOUR FILE INPUT IS CORRECT." << endl;
    return -1;
  }
  else {
    return 0;
  }
}
/* opens a file and checks if it fails - returns result of checkFile() */
bool FileError::pass(){
  return (checkFile() == 0);
}
