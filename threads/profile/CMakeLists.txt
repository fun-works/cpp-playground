
add_executable(profile_threads main.cpp)
target_link_libraries(profile_threads pthread)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang" OR 
    CMAKE_C_COMPILER_ID STREQUAL "Clang"
)
  add_test( NAME profile_threads
            COMMAND $<TARGET_FILE:profile_threads>)
endif()
