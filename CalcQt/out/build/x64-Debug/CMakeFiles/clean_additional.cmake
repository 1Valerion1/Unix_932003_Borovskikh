# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\CalcQt_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CalcQt_autogen.dir\\ParseCache.txt"
  "CalcQt_autogen"
  )
endif()
