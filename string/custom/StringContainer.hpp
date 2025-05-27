#pragma once

#include <cstring>
#include <cstdint>
#include <cstdio>

template<std::size_t MaxSize>
class StringContainer {
public:
    StringContainer() { buffer[0] = '\0'; }

    StringContainer(const char* str) { assign(str); }

    bool assign(const char* str) {
        if (!str) return false;
        std::size_t len = std::strlen(str);
        if (len >= MaxSize) return false;
        std::strncpy(buffer, str, MaxSize);
        buffer[MaxSize - 1] = '\0';
        return true;
    }

    bool append(const char* str) {
        if (!str) return false;
        std::size_t currentLen = std::strlen(buffer);
        std::size_t addLen = std::strlen(str);
        if (currentLen + addLen >= MaxSize) return false;
        std::strncat(buffer, str, MaxSize - currentLen - 1);
        return true;
    }

    const char* c_str() const {
        return buffer;
    }

    std::size_t size() const {
        return std::strlen(buffer);
    }

    std::size_t capacity() const {
        return MaxSize - 1;
    }

    void clear() {
        buffer[0] = '\0';
    }

private:
    char buffer[MaxSize] = {};
};
