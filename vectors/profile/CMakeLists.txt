add_executable(profile_vector main.cpp)
enable_map_file_for_target(profile_vector)

add_test( NAME profile_vector
          COMMAND $<TARGET_FILE:profile_vector>)