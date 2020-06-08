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

void Process::UpdateCpuUtilization() {
  vector<string> cpu_utilization = LinuxParser::CpuUtilization(pid_);
  float uptime     = float(LinuxParser::UpTime());
  float utime      = std::stof(cpu_utilization[0]);
  float stime      = std::stof(cpu_utilization[1]);
  float cutime     = std::stof(cpu_utilization[2]);
  float cstime     = std::stof(cpu_utilization[3]);
  float starttime  = std::stof(cpu_utilization[4]);

  float total_time = (utime + stime + cutime + cstime)/sysconf(_SC_CLK_TCK);
  float seconds = uptime - (starttime / sysconf(_SC_CLK_TCK));

  cpu_ = total_time / seconds;
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
