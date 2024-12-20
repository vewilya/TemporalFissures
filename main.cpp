#include "calcs.h"
#include "measure.h"
#include "my_thread.h"
#include <future>
#include <iostream>

using namespace std;

int main()
{
    const int NUM_THREADS = std::thread::hardware_concurrency() - 1;
    const int NUM_CALCS = 10;
    const int TOTAL_RUNS = 20;

    std::vector<std::future<void>> futures;
    Calcs calcs;
    Measure pm;

    auto result = pm.measureProcess([&calcs](int val) { return calcs.calc(val); },
                                    10,   // number of rounds
                                    32143 // val parameter
    );

    // Launch tasks
    // for (int i = 0; i < NUM_CALCS; i++) {
    //     futures.push_back(std::async(std::launch::async, [i, &calcs] {
    //         int total = 0;

    //         // Performance Measurements
    //         auto t0 = std::chrono::high_resolution_clock::now();
    //         int res = calcs.calc(i * 32143);
    //         auto t1 = std::chrono::high_resolution_clock::now();
    //         std::cout << duration_cast<chrono::milliseconds>(t1 - t0).count() << " msec\n";

    //         // Increment amount
    //         total += res;

    //         // std::cout << "Thread ID: " << i << " Total runs: " << current_count << "/"
    //         //           << TOTAL_RUNS << " Result: " << res << std::endl;

    //         std::cout << "Total: " << total << std::endl;
    //     }));
    // }

    // // Wait for all tasks to complete
    // for (auto &future : futures) {
    //     future.wait();
    // }

    return 0;
}
