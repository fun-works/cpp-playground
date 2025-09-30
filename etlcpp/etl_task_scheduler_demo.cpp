#include "etl_task_scheduler_demo.h"
#include <etl/scheduler.h>
#include <etl/task.h>
#include <cstdio>
#include <thread>
#include <atomic>

// Example task class
class PrintTask : public etl::task {
public:
    PrintTask(const char* msg, etl::task_priority_t priority)
        : etl::task(priority), message(msg), work_count(0) {}

    uint32_t task_request_work() const override {
        // Simulate work available for 5 cycles
        return work_count < 5 ? 1 : 0;
    }

    void task_process_work() override {
        printf("[Task] %s (cycle %d)\n", message, work_count + 1);
        ++work_count;
    }

private:
    const char* message;
    mutable int work_count;
};

// ETL-only scheduler demo (no std::thread, no std::atomic)
void benchmark_etl_task_scheduler_etl_only()
{
    PrintTask t1("A", 2);
    PrintTask t2("B", 1);
    etl::scheduler<etl::scheduler_policy_sequential_single, 2> sched;
    sched.add_task(t1);
    sched.add_task(t2);
    
    // Manually run scheduler cycles instead of using start() which loops forever
    printf("Running ETL scheduler for limited cycles:\n");
    for (int cycle = 0; cycle < 5; ++cycle) {
        printf("Cycle %d:\n", cycle + 1);
        
        // Manually check each task and process work
        bool has_work = false;
        if (t1.task_request_work() > 0) {
            t1.task_process_work();
            has_work = true;
        }
        if (t2.task_request_work() > 0) {
            t2.task_process_work();
            has_work = true;
        }
        
        if (!has_work) {
            printf("No more work available, stopping scheduler.\n");
            break;
        }
    }
}
