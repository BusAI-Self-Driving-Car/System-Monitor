#include "processor.h"

// --TODO--: Return the aggregate CPU utilization
float Processor::Utilization() {
  float active_jiffies = LinuxParser::ActiveJiffies();
  float idle_jiffies = LinuxParser::IdleJiffies();
  
  float active_duration = active_jiffies - prev_active_jiffies_;
  float idle_duration = idle_jiffies - prev_idle_jiffies_;
  float whole_duration = active_duration + idle_duration;

  prev_active_jiffies_ = active_jiffies;
  prev_idle_jiffies_ = idle_jiffies;

  return active_duration/whole_duration;;
}
