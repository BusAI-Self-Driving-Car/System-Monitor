#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "linux_parser.h"

using std::stof;
using std::vector;
using std::string;

class Processor {
public:
  float Utilization();  // --TODO--: See src/processor.cpp

// --TODO--: Declare any necessary private members
private:
  long cached_active_ticks_{0};
  long cached_idle_ticks_{0};
};

#endif
