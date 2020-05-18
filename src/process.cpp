#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;
using std::stol;

using std::cout;
using std::endl;

// --TODO--: Return this process's ID
int Process::Pid() {
  return pid_;
}

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() {
  // cout << "CpuUtilization: " << endl;
  vector<string> cpu_utils = LinuxParser::Cpu(pid_);
  // cout << "cpu_utils: " << cpu_utils.size() << endl;
  for(auto str : cpu_utils) {
    // cout << str << endl;
  }
  long total_time = stol(cpu_utils[0])
                    + stol(cpu_utils[1])
                    + stol(cpu_utils[2])
                    + stol(cpu_utils[3]);
  float seconds = float(UpTime());
  float cpu_utilization_ = ((total_time / sysconf(_SC_CLK_TCK)) / seconds);
  return cpu_utilization_;
}

// --TODO--: Return the command that generated this process
string Process::Command() {
  if(command_ == "") command_ = LinuxParser::Command(pid_);
  return command_;
}

// --TODO--: Return this process's memory utilization
string Process::Ram() {
  return LinuxParser::Ram(pid_);
}

// --TODO--: Return the user (name) that generated this process
string Process::User() {
  if(user_ == "") user_ = LinuxParser::User(pid_);
  return user_;
}

// --TODO--: Return the age of this process (in seconds)
long int Process::UpTime() {
  return LinuxParser::UpTime(pid_);
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a[[maybe_unused]]) const { return true; }
