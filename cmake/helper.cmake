# Function to print size info in ESP-IDF style
function(print_size target)
    add_custom_command(TARGET ${target} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E echo "----------------------"
        COMMAND ${CMAKE_COMMAND} -E echo "Footprint for: ${target}"
        COMMAND size --format=SysV $<TARGET_FILE:${target}>
        COMMAND ${CMAKE_COMMAND} -E echo "----------------------"
        VERBATIM
    )
endfunction()

# Macro to add map file generation for a target
macro(enable_map_file_for_target target_name)
    if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
        set(MAP_FILE "${CMAKE_CURRENT_BINARY_DIR}/${target_name}.map")
        target_link_options(${target_name} PRIVATE "-Wl,-Map=${MAP_FILE}")
    elseif(MSVC)
        set(MAP_FILE "${CMAKE_CURRENT_BINARY_DIR}/${target_name}.map")
        target_link_options(${target_name} PRIVATE "/MAP:${MAP_FILE}")
    endif()
endmacro()

# Macro to configure a target with common settings
macro(configure_target target_name source_file)
    add_executable(${target_name} ${source_file})
    target_compile_options(${target_name} PRIVATE -Os -fno-rtti -fno-exceptions)
    enable_map_file_for_target(${target_name})
    add_test(NAME ${target_name} COMMAND $<TARGET_FILE:${target_name}>)
    print_size(${target_name})
endmacro()
