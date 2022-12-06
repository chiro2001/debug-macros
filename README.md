# debug-macros

Useful C/C++ debug macros, copying from nemu project, provide via CMake.

## Usage

```cmake
set(CPM_DOWNLOAD_VERSION 0.36.0)

if (CPM_SOURCE_CACHE)
    set(CPM_DOWNLOAD_LOCATION "${CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
elseif (DEFINED ENV{CPM_SOURCE_CACHE})
    set(CPM_DOWNLOAD_LOCATION "$ENV{CPM_SOURCE_CACHE}/cpm/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
else ()
    set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")
endif ()

# Expand relative path. This is important if the provided path contains a tilde (~)
get_filename_component(CPM_DOWNLOAD_LOCATION ${CPM_DOWNLOAD_LOCATION} ABSOLUTE)
if (NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake to ${CPM_DOWNLOAD_LOCATION}")
    file(DOWNLOAD
            https://github.com/cpm-cmake/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake
            ${CPM_DOWNLOAD_LOCATION}
            )
endif ()

include(${CPM_DOWNLOAD_LOCATION})

CPMAddPackage(
        NAME debug_macros
        VERSION 0.7
        GITHUB_REPOSITORY chiro2001/debug-macros)

link_libraries(debug_macros)
```

[example usage](src/simple_test.cpp)

```c++
#include "debug_macros.h"
#include <cstdio>

int main() {
  Log("Hi, this' a Log.");
  Dbg("This's a DEBUG message, display when CONFIG_DEBUG was set.");
  Err("This is an ERROR message.");
  return 0;
}
```

Log to file:

```c++
#ifndef CONFIG_FILE_LOG
#define CONFIG_FILE_LOG 1
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
```