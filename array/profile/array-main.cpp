#include <memory>
#include <cstdio>

void testArray(void);

void testArray() {
    int c_array[10];
    printf("C array size: %zu bytes\n", sizeof(c_array));
}

int main(int argc, char* argv[]) {
    testArray();
    return 0;
}