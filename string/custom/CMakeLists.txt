add_executable(string string-main.cpp)
target_compile_options(string PRIVATE -Os -fno-rtti -fno-exceptions)
add_test( NAME string
          COMMAND $<TARGET_FILE:string>)

print_size(string)
