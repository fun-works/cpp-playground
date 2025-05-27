#include <memory>
#include <cstdio>

#include "StringContainer.hpp"

int main() {
    StringContainer<32> name;
    if (name.assign("Hello")) {
        name.append(", world!");
    }

    printf("String: %s\n", name.c_str());
    
    return 0;
}
