# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\aemo_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\aemo_autogen.dir\\ParseCache.txt"
  "aemo_autogen"
  )
endif()
