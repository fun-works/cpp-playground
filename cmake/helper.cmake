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
