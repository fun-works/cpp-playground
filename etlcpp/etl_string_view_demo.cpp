#include "etl/string_view.h"
#include "etl/error_handler.h"
#include "etl_string_view_demo.h"

static etl::string_view get_sv() {
    return etl::string_view{"Hello, Embedded Template Library!"};
}

size_t benchmark_etl_string_view_size() {
    return get_sv().size();
}

int benchmark_etl_string_view_empty() {
    return get_sv().empty();
}

char benchmark_etl_string_view_front() {
    return get_sv().front();
}

char benchmark_etl_string_view_back() {
    return get_sv().back();
}

size_t benchmark_etl_string_view_find() {
    return get_sv().find("Template");
}

int benchmark_etl_string_view_compare() {
    return get_sv().compare("Hello, Embedded Template Library!");
}

size_t benchmark_etl_string_view_substr_size() {
    return get_sv().substr(7, 9).size();
}
