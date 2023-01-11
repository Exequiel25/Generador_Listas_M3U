# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\MP3_Organizer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\MP3_Organizer_autogen.dir\\ParseCache.txt"
  "MP3_Organizer_autogen"
  )
endif()
