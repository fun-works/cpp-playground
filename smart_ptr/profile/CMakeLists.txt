add_executable(rawptr rawptr-main.cpp)
target_compile_options(rawptr PRIVATE -Os -fno-rtti -fno-exceptions)

enable_map_file_for_target(rawptr)
add_test( NAME rawptr
          COMMAND $<TARGET_FILE:rawptr>)


add_executable(uniqueptr uniqueptr-main.cpp)
target_compile_options(uniqueptr PRIVATE -Os -fno-rtti -fno-exceptions)
enable_map_file_for_target(uniqueptr)

add_test( NAME uniqueptr
          COMMAND $<TARGET_FILE:uniqueptr>)

print_size(rawptr)
print_size(uniqueptr)
