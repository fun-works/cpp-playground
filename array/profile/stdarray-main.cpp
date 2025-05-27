#include <memory>
#include <cstdio>
#include <array>

void testStdArray(void);

void testStdArray() {
    std::array<int, 10> std_array;
    printf("std::array size: %zu bytes\n", sizeof(std_array));
}

int main(int argc, char* argv[]) {
    testStdArray();
    return 0;
}