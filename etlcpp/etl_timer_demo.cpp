#include "etl_timer_demo.h"
#include <etl/callback_timer.h>
#include <etl/delegate.h>
#include <cstdio>
#include <thread>
#include <chrono>

namespace {
    // Timer callback function
    void on_timer()
    {
        printf("[ETL Timer] Callback fired!\n");
    }

    // Class with member data for delegate callback with "arguments"
    class TimerHandler {
    public:
        TimerHandler(int val) : value(val) {}
        
        void on_timer_with_data() {
            printf("[ETL Timer] Callback with value: %d\n", value);
            value++; // Increment for next call
        }
        
        void set_value(int val) { value = val; }
        
    private:
        int value;
    };
}


/**
 * @typedef 
 */
void benchmark_etl_timer_callback_demo()
{
    etl::callback_timer<1> cb_timer;
    cb_timer.enable(true);
    static etl::callback_timer<1>::callback_type timer_cb = etl::delegate<void()>::create<on_timer>();
    auto id = cb_timer.register_timer(timer_cb, 500, true);
    cb_timer.start(id);
    for (int i = 0; i < 4; ++i) {
        //std::this_thread::sleep_for(std::chrono::milliseconds(500));
        cb_timer.tick(500);
    }
    cb_timer.stop(id);
}

// ETL timer demo with delegate and "arguments" via member data
void benchmark_etl_timer_delegate_with_args_demo()
{
    static TimerHandler handler(100); // Start with value 100
    etl::callback_timer<1> cb_timer;
    cb_timer.enable(true);
    
    // Create delegate pointing to member function
    static etl::callback_timer<1>::callback_type timer_cb = 
        etl::delegate<void()>::create<TimerHandler, &TimerHandler::on_timer_with_data>(handler);
    
    auto id = cb_timer.register_timer(timer_cb, 500, true);
    cb_timer.start(id);
    
    for (int i = 0; i < 4; ++i) {
        cb_timer.tick(500);
    }
    cb_timer.stop(id);
}

void benchmark_etl_timer_demo_run()
{
    printf("[Basic Timer Demo]\n");
    benchmark_etl_timer_callback_demo();
    printf("\n[Delegate with Args Demo]\n");
    benchmark_etl_timer_delegate_with_args_demo();
}
