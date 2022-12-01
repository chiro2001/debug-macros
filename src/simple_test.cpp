#include "common.h"
#include <cstdio>

int main() {
  Log("Hi, this' a Log.");
  Dbg("This's a DEBUG message, display when CONFIG_DEBUG was set.");
  Err("This is an ERROR message.");
  return 0;
}