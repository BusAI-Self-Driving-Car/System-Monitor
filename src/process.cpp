#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;
using std::stol;

// Constructor for Process class
Process::Process(int pid) : pid_(pid){
  cpu_ = 0;
  cached_active_ticks_ = 0;
  cached_idle_ticks_ = 0;
  cached_system_ticks_= 0;

  user_ = LinuxParser::User(pid_);
  command_ = LinuxParser::Command(pid_);
}

// --TODO--: Return this process's ID
int Process::Pid() const { return pid_; }

// --TODO--: Return this process's CPU utilization
float Process::CpuUtilization() const { return cpu_; }

void Process::CpuUtilization(long active_ticks, long system_ticks) {
  long duration_active = active_ticks - cached_active_ticks_;
  long duration = system_ticks - cached_system_ticks_;
  cpu_ = static_cast<float>(duration_active) / duration;
  cached_active_ticks_ = active_ticks;
  cached_system_ticks_ = system_ticks;
}

// --TODO--: Return the command that generated this process
string Process::Command() const { return command_; }

// --TODO--: Return this process's memory utilization
string Process::Ram() const { return LinuxParser::Ram(pid_); }

// --TODO--: Return the user (name) that generated this process
string Process::User() const { return user_; }

// --TODO--: Return the age of this process (in seconds)
long int Process::UpTime() const { return LinuxParser::UpTime(pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(const Process& a) const {
  return CpuUtilization() < a.CpuUtilization();
}

bool Process::operator>(const Process& a) const {
  return CpuUtilization() > a.CpuUtilization();
}
