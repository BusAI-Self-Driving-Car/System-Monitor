#include <string>

#include "format.h"

using std::string;
using std::to_string;

// --TODO--: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  string elapsed = "";
  long hh, mm, ss;
  hh = seconds / 3600;
  mm = (seconds - hh*3600) / 60;
  ss = seconds - hh*3600 - mm*60;
  return to_string(hh) + ":" + to_string(mm) + ":" + to_string(ss);
}
