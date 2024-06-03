add_executable(profile_vector main.cpp)

add_test( NAME profile_vector
          COMMAND $<TARGET_FILE:profile_vector>)