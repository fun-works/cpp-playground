
add_executable(profile_threads main.cpp)
target_link_libraries(profile_threads pthread)
enable_map_file_for_target(profile_threads)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR 
    CMAKE_C_COMPILER_ID STREQUAL "Clang"
)
  return()
endif()

add_test( NAME profile_threads
        COMMAND $<TARGET_FILE:profile_threads>)

