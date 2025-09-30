#include "my_string_view_demo.h"
#include <cstring>

struct my_string_view {
    const char* data_;
    size_t size_;
    my_string_view(const char* s) : data_(s), size_(strlen(s)) {}
    size_t size() const { return size_; }
    bool empty() const { return size_ == 0; }
    char front() const { return data_[0]; }
    char back() const { return data_[size_-1]; }
    size_t find(const char* sub) const {
        const char* pos = strstr(data_, sub);
        return pos ? (size_t)(pos - data_) : (size_t)-1;
    }
    int compare(const char* other) const {
        return strcmp(data_, other);
    }
    my_string_view substr(size_t pos, size_t count) const {
        if (pos > size_) return my_string_view("");
        size_t n = (pos + count > size_) ? size_ - pos : count;
        char* buf = new char[n+1];
        memcpy(buf, data_ + pos, n);
        buf[n] = '\0';
        my_string_view sv(buf);
        delete[] buf;
        return sv;
    }
};

static my_string_view get_sv() {
    return my_string_view("Hello, Embedded Template Library!");
}

size_t benchmark_my_string_view_size() { return get_sv().size(); }
int benchmark_my_string_view_empty() { return get_sv().empty(); }
char benchmark_my_string_view_front() { return get_sv().front(); }
char benchmark_my_string_view_back() { return get_sv().back(); }
size_t benchmark_my_string_view_find() { return get_sv().find("Template"); }
int benchmark_my_string_view_compare() { return get_sv().compare("Hello, Embedded Template Library!"); }
size_t benchmark_my_string_view_substr_size() { return get_sv().substr(7, 9).size(); }
