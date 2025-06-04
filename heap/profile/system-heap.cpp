#include <iostream>
#include <chrono>
#include <cstdlib>

#define ITERATIONS 10000

void measureMallocFree() {
    const size_t iterations = ITERATIONS;
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < iterations; ++i) {
        volatile void* ptr = malloc(sizeof(int));        
        if (!ptr) {
            std::cerr << "Error: Memory allocation failed\n";
            return;
        }
        //*(int *)ptr = i; // Use the allocated memory to avoid optimization removal
        free((void *)ptr);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Time taken for malloc/free: " << elapsed.count() << " milliseconds\n";
}

void measureNewDelete() {
    const size_t iterations = ITERATIONS;
    auto start = std::chrono::high_resolution_clock::now();

    for (size_t i = 0; i < iterations; ++i) {
        volatile int* ptr = new int;
        if (!ptr) {
            std::cerr << "Error: Memory allocation failed\n";
            return;
        }
        *ptr = i; // Use the allocated memory to avoid optimization removal        
        delete ptr;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Time taken for new/delete: " << elapsed.count() << " milliseconds\n";
}

int main() {
    measureMallocFree();
    measureNewDelete();
    return 0;
}
