#include <memory>
#include <cstdio>

#include "StringContainer.hpp"

int main() {
    StringContainer<32> name;
    if (name.assign("Hello")) {
        name.append(", world!");
    }

    std::cout << name.c_str() << std::endl;
    return 0;
}
