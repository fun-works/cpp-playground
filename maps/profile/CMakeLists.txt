
add_executable(profile_map main.cpp)

add_test( NAME profile_map
          COMMAND $<TARGET_FILE:profile_map>)