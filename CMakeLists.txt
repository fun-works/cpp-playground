cmake_minimum_required(VERSION 3.10)
project(profile_map)

include (cmake/helper.cmake)

enable_testing()
 
add_subdirectory(maps)
add_subdirectory(vectors)
add_subdirectory(smart_ptr)
add_subdirectory(array)
add_subdirectory(string)
add_subdirectory(heap)
add_subdirectory(rt_polymorphysm)

if (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  add_subdirectory(threads) 
endif ()
