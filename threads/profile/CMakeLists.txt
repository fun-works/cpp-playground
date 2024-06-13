
add_executable(profile_threads main.cpp)

target_link_libraries(profile_threads pthread)

add_test( NAME profile_threads
          COMMAND $<TARGET_FILE:profile_threads>)
		  