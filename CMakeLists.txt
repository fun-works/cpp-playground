cmake_minimum_required(VERSION 3.10)
project(profile_map)

include (cmake/helper.cmake)

enable_testing()
 
add_subdirectory(maps/profile)
add_subdirectory(vectors/profile)
add_subdirectory(smart_ptr/profile)
add_subdirectory(array/profile)
add_subdirectory(string/custom)
add_subdirectory(heap)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  add_subdirectory(threads/profile) 
endif ()
