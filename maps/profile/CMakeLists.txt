
add_executable(profile_map main.cpp)
enable_map_file_for_target(profile_map)

add_test( NAME profile_map
          COMMAND $<TARGET_FILE:profile_map>)