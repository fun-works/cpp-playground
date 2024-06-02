
add_executable(profile_map main.cpp)

add_test( NAME test
          COMMAND $<TARGET_FILE:profile_map>)