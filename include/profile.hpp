#pragma once

#include <chrono>

#define PROFILE(fn, time) \
do{ \
    auto start = high_resolution_clock::now(); \
    fn; \
    auto stop = high_resolution_clock::now(); \
 \
   auto duration = duration_cast<microseconds>(stop - start); \
   time = duration.count(); \
}while(0)
