add_executable(string string-main.cpp)
target_compile_options(string PRIVATE -Os -fno-rtti -fno-exceptions)
enable_map_file_for_target(string)

add_test( NAME string
          COMMAND $<TARGET_FILE:string>)

print_size(string)
