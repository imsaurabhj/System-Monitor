#ifndef PROCESS_H
#define PROCESS_H

#include <string>

/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
using std::string;
class Process {
 public:
  int Pid();                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp
  Process(string filepath, int pid);
  // TODO: Declare any necessary private members
 private:
 int pid_;
 string proc_dirPath;
 string UID;
};

#endif