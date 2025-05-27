#include <memory>
#include <cstdio>
#include <array>

void testStdArray(void);

void testStdArray() {
    std::array<int, 10> std_array;
    std::fill(std_array.begin(), std_array.end(), 0);
    printf("std::array size: %zu bytes\n", sizeof(std_array));
    for (const auto& val : std_array) {
        printf("%d ", val);
    }
}

int main(int argc, char* argv[]) {
    testStdArray();
    return 0;
}