#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
public:
  Process(int pid);
  int Pid() const;                               // --TODO--: See src/process.cpp
  std::string User() const;                      // --TODO--: See src/process.cpp
  std::string Command() const;                   // --TODO--: See src/process.cpp
  float CpuUtilization() const;                  // TODO: See src/process.cpp
  void CpuUtilization(long active_ticks, long system_ticks);
  std::string Ram() const;                       // --TODO--: See src/process.cpp
  long int UpTime() const;                       // --TODO--: See src/process.cpp
  bool operator<(const Process& a) const;  // TODO: See src/process.cpp
  bool operator>(const Process& a) const;

// TODO: Declare any necessary private members
private:
  int pid_;
  std::string user_;
  std::string command_;

  float cpu_;
  long cached_active_ticks_;
  long cached_idle_ticks_;
  long cached_system_ticks_;
};

#endif
