# ETL Demo Project - String View and Components Benchmarking
cmake_minimum_required(VERSION 3.10)
project(demo_string_view)

#-----------------------------------------------------------------------------
# Build Configuration
#-----------------------------------------------------------------------------
# Set Release build type and size optimization, no debug info
set(CMAKE_BUILD_TYPE Release)
if (MSVC)
    # MSVC does not support GCC/Clang linker flags
    set(CMAKE_CXX_FLAGS_RELEASE "/O2")
else()
    set(CMAKE_CXX_FLAGS_RELEASE "-Os -Wl,-Map=${CMAKE_PROJECT_NAME}.map")
endif()

#-----------------------------------------------------------------------------
# Dependencies
#-----------------------------------------------------------------------------
# Add ETL include directory (relative to this demo folder)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/etl/include")
    message(STATUS "Using local ETL from etlcpp/etl/include")
    include_directories(${CMAKE_CURRENT_SOURCE_DIR}/etl/include)
else()
    message(WARNING "Local ETL not found, please ensure etl/include is available.")
    include_directories(../etl/include)
endif()

#-----------------------------------------------------------------------------
# ETL Configuration
#-----------------------------------------------------------------------------
# Define ETL macros for enhanced functionality
add_definitions(-DETL_CALLBACK_TIMER_USE_ATOMIC_LOCK)
add_definitions(-DETL_LOG_ERRORS)

#-----------------------------------------------------------------------------
# Source Files
#-----------------------------------------------------------------------------
set(DEMO_SOURCES
    main.cpp
    etl_string_view_demo.cpp
    my_string_view_demo.cpp
    etl_timer_demo.cpp
    etl_task_scheduler_demo.cpp
    etl_assert_demo.cpp
)

#-----------------------------------------------------------------------------
# Executable Target
#-----------------------------------------------------------------------------

add_executable(${PROJECT_NAME} ${DEMO_SOURCES})

# Add test for ETL demo application
enable_testing()
add_test(NAME etlcpp_demo COMMAND $<TARGET_FILE:${PROJECT_NAME}>)
