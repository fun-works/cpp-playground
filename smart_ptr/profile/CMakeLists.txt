
add_executable(rawptr rawptr-main.cpp)
add_test( NAME rawptr
          COMMAND $<TARGET_FILE:rawptr>)


add_executable(uniqueptr uniqueptr-main.cpp)
add_test( NAME uniqueptr
          COMMAND $<TARGET_FILE:uniqueptr>)