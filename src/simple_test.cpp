// prefix before log line
#define ENVR ANSI_FMT("TEST", ANSI_FG_YELLOW) " "

#include "debug_macros.h"
#include <cstdio>

int main() {
  Log("Hi, this' a Log.");
  Dbg("This's a DEBUG message, display when CONFIG_DEBUG was set.");
  Err("This is an ERROR message.");
  Ok("This is SUCCESS message.");
  return 0;
}