#ifndef MY_THREAD_H
#define MY_THREAD_H

#include "calcs.h"
#include <chrono>
#include <iostream>
#include <mutex>
#include <thread>

class MyThread
{
public:
    MyThread(int threadId, std::atomic<int> &sharedCounter, int maxTotalRuns);
    ~MyThread();

    void run();

    // Prevent copying as threads can't be copied
    MyThread(const MyThread &) = delete;
    MyThread &operator=(const MyThread &) = delete;

    // Allow moving threads (necessary for vector operations)
    MyThread(MyThread &&) = default;
    MyThread &operator=(MyThread &&) = default;

private:
    std::unique_ptr<std::thread> thread;
    int id;

    Calcs calcs;
    std::atomic<int> &total_counter;
    int max_total_runs;
    bool shouldStop{false};
};

#endif // MY_THREAD_H
