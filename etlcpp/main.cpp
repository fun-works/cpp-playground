#include <cstdio>

#include "etl_string_view_demo.h"
#include "my_string_view_demo.h"
#include "etl_timer_demo.h"
#include "etl_task_scheduler_demo.h"
#include "etl_assert_demo.h"

int main() {
    printf("[ETL string_view]\n");
    printf("size: %zu\n", benchmark_etl_string_view_size());
    printf("empty: %d\n", benchmark_etl_string_view_empty());
    printf("front: '%c'\n", benchmark_etl_string_view_front());
    printf("back: '%c'\n", benchmark_etl_string_view_back());
    printf("find('Template'): %zu\n", benchmark_etl_string_view_find());
    printf("compare('Hello, Embedded Template Library!'): %d\n", benchmark_etl_string_view_compare());
    printf("substr(7, 9) size: %zu\n", benchmark_etl_string_view_substr_size());

    printf("\n[My string_view]\n");
    printf("size: %zu\n", benchmark_my_string_view_size());
    printf("empty: %d\n", benchmark_my_string_view_empty());
    printf("front: '%c'\n", benchmark_my_string_view_front());
    printf("back: '%c'\n", benchmark_my_string_view_back());
    printf("find('Template'): %zu\n", benchmark_my_string_view_find());
    printf("compare('Hello, Embedded Template Library!'): %d\n", benchmark_my_string_view_compare());
    printf("substr(7, 9) size: %zu\n", benchmark_my_string_view_substr_size());

    printf("\n[ETL Timer Demo]\n");
    benchmark_etl_timer_demo_run();
    
    printf("\n[ETL Scheduler Demo]\n");
    benchmark_etl_task_scheduler_etl_only();
    
    printf("\n[ETL Assert Macros Demo]\n");
    benchmark_assert_demo_etl();
    
    printf("\n[Standard Assert Demo]\n");
    benchmark_assert_demo_standard();
    
    printf("\n[Plain C Assert Demo]\n");
    benchmark_assert_demo_plain_c();
    
    return 0;
}
