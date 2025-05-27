#include <memory>
#include <cstdio>

void testArray(void);

void testArray() {
    int c_array[10];
    memset(c_array, 0, sizeof(c_array));
    printf("C array size: %zu bytes\n", sizeof(c_array));
    for (size_t i = 0; i < sizeof(c_array); ++i) {
        printf("%d ", c_array[i]);
    }
}

int main(int argc, char* argv[]) {
    testArray();
    return 0;
}