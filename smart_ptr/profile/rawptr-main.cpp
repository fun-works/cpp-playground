#include <memory>
#include <cstdio>

#include "test.hpp"

void testRawPointer(void);

void testRawPointer() {
    Test* rawPtr = new Test();
    printf("%p\n", reinterpret_cast<void *>(rawPtr));
    delete rawPtr;
    Test1* rawPtr1 = new Test1();
    printf("%p\n", reinterpret_cast<void *>(rawPtr1));
    delete rawPtr1;
}

int main(int argc, char* argv[]) {
    testRawPointer();
    return 0;
}