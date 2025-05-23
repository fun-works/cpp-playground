cmake_minimum_required(VERSION 3.10) 
 
project(profile_map)

enable_testing()
 
add_subdirectory(maps/profile)
add_subdirectory(vectors/profile)
add_subdirectory(smart_ptr/profile)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  add_subdirectory(threads/profile) 
endif ()
