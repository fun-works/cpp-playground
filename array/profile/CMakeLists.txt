add_executable(array array-main.cpp)
target_compile_options(array PRIVATE -Os -fno-rtti -fno-exceptions)
add_test( NAME array
          COMMAND $<TARGET_FILE:array>)


add_executable(stdarray stdarray-main.cpp)
target_compile_options(stdarray PRIVATE -Os -fno-rtti -fno-exceptions)
add_test( NAME stdarray
          COMMAND $<TARGET_FILE:stdarray>)

print_size(array)
print_size(stdarray)
