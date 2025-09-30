#pragma once
#include <cstddef>

#ifdef __cplusplus
extern "C" {
#endif

size_t benchmark_etl_string_view_size();
int benchmark_etl_string_view_empty();
char benchmark_etl_string_view_front();
char benchmark_etl_string_view_back();
size_t benchmark_etl_string_view_find();
int benchmark_etl_string_view_compare();
size_t benchmark_etl_string_view_substr_size();

#ifdef __cplusplus
}
#endif
