#ifndef CONFIG_FILE_LOG
#define CONFIG_FILE_LOG 1
#endif

#ifndef CONFIG_LOG_COLOR_DISABLED
#define CONFIG_LOG_COLOR_DISABLED 1
#endif


#include "debug_macros.h"
#include <cstdio>

FILE *log_fp = nullptr;

int main() {
  Log("Hi, this' a Log.");
  log_fp = fopen("log.txt", "w");
  Log("This line will log to stdio and file.");
  fclose(log_fp);
  return 0;
}