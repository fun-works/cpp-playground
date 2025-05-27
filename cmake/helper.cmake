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
