#include "my_thread.h"
#define BREAK

MyThread::MyThread(int threadId, std::atomic<int> &sharedCounter, int maxTotalRuns)
    : id(threadId)
    , total_counter(sharedCounter)
    , max_total_runs(maxTotalRuns)
{
    thread = std::make_unique<std::thread>(&MyThread::run, this);
}

MyThread::~MyThread()
{
    if (thread && thread->joinable()) {
        thread->join();
    }
}

void MyThread::run()
{
    while (!shouldStop) {
        int current_count = ++total_counter; // Increment and get value atomically

        if (current_count > max_total_runs) {
            shouldStop = true; // Signal other threads to stop
            break;
        }

        int res = calcs.calc(id * 2103);
        std::cout << "Thread ID: " << id << " Time: " << __TIME__
                  << " Total runs: " << current_count << "/" << max_total_runs << " Result: " << res
                  << std::endl;
    }
}
