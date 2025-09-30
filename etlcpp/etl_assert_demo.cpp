#include "etl_assert_demo.h"
#include "etl/vector.h"
#include "etl/string.h"
#include "etl/error_handler.h"
#include "etl/exception.h"
#include "etl/not_null.h"
#include <cstdio>
#include <memory>
#include <chrono>
#include <cassert>
#include <stdexcept>
#include <iostream>

class my_exception : public etl::exception {
public: 
    my_exception(const char* file, int line)
        : etl::exception("Custom assertion failure", file, line) {}
};

namespace {
    // Custom error handler to log ETL exceptions
    void etl_assert_error_handler(const etl::exception& e) {
        printf("[ETL ERROR HANDLER] Exception caught: %s at line %d\n", 
               e.what(), static_cast<int>(e.line_number()));
    }
}


// Basic ETL assert demonstration
void benchmark_assert_demo_etl() {
    printf("\n=== ETL Assert Demo - Basic Assertions ===\n");
    
    // Set up error handler to log exceptions
    etl::error_handler::set_callback<etl_assert_error_handler>();
    
    // Test 1: Standard ETL exception
    printf("Test 1: Standard ETL exception\n");
    ETL_ASSERT(false, ETL_ERROR(etl::vector_out_of_bounds));
    printf("Standard ETL exception triggered and handled\n");
    
    // Test 2: Custom exception
    printf("\nTest 2: Custom exception\n");
    ETL_ASSERT(false, ETL_ERROR(my_exception));
    printf("Custom exception triggered and handled\n");
}

// Equivalent functionality using early returns (no assertions)
void benchmark_assert_demo_standard() {
    printf("\n=== Standard Assert Demo - Early Returns ===\n");
    
    // Helper lambda for error logging
    auto log_error = [](const char* message, int line) {
        printf("[STANDARD ERROR HANDLER] Error: %s at line %d\n", message, line);
    };
    
    // Test 1: Standard error with early return
    printf("Test 1: Standard error with early return\n");
    auto test_function_1 = [&]() -> bool {
        bool condition = false;
        if (!condition) {
            log_error("Vector out of bounds", __LINE__);
            return false;
        }
        return true;
    };
    
    if (!test_function_1()) {
        printf("Standard error triggered and handled\n");
    }
    
    // Test 2: Custom error with early return
    printf("\nTest 2: Custom error with early return\n");
    auto test_function_2 = [&]() -> bool {
        bool condition = false;
        if (!condition) {
            log_error("Custom assertion failure", __LINE__);
            return false;
        }
        return true;
    };
    
    if (!test_function_2()) {
        printf("Custom error triggered and handled\n");
    }
}

// Plain C-style implementation using early returns (no lambdas)
void benchmark_assert_demo_plain_c() {
    printf("\n=== Plain C Assert Demo - Early Returns ===\n");
    
    // Test 1: Standard error with early return - plain C style
    printf("Test 1: Standard error with early return (plain C)\n");
    {
        bool condition = false;
        if (!condition) {
            printf("[PLAIN C ERROR HANDLER] Error: Vector out of bounds at line %d\n", __LINE__);
            goto test1_error;
        }
        printf("Test 1 passed\n");
        goto test1_done;
        
        test1_error:
        printf("Standard error triggered and handled\n");
        
        test1_done:;
    }
    
    // Test 2: Custom error with early return - plain C style
    printf("\nTest 2: Custom error with early return (plain C)\n");
    {
        bool condition = false;
        if (!condition) {
            printf("[PLAIN C ERROR HANDLER] Error: Custom assertion failure at line %d\n", __LINE__);
            goto test2_error;
        }
        printf("Test 2 passed\n");
        goto test2_done;
        
        test2_error:
        printf("Custom error triggered and handled\n");
        
        test2_done:;
    }
}