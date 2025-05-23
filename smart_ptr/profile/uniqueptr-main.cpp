#include <memory>
#include <cstdio>

#include "test.hpp"

void testUniquePointer(void);

void testUniquePointer() {
    std::unique_ptr<Test> uniquePtr(new Test());
    printf("%p\n", reinterpret_cast<void *>(uniquePtr.get()));
    std::unique_ptr<Test1> uniquePtr1(new Test1());
    printf("%p\n", reinterpret_cast<void *>(uniquePtr1.get()));
}

int main(int argc, char* argv[]) {
    testUniquePointer();
    return 0;
}