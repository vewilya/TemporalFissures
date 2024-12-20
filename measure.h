#ifndef MEASURE_H
#define MEASURE_H

#include <chrono>
#include <iostream>

class Measure
{
public:
    Measure() {}

    ~Measure() {}

    template<typename Func, typename... Args>

    auto measureProcess(Func &&func, int numRounds, Args &&...args)
    {
        auto t0 = std::chrono::high_resolution_clock::now();

        // Let's run the function multiple times, as specified with numRounds
        int result;
        for (int i = 0; i < numRounds; i++) {
            auto t0a = std::chrono::high_resolution_clock::now();
            result = std::forward<Func>(func)(std::forward<Args>(args)...);
            auto t1a = std::chrono::high_resolution_clock::now();
            auto duration_internal = std::chrono::duration_cast<std::chrono::milliseconds>(t1a
                                                                                           - t0a);

            std::cout << "Round " << i << " lasted "
                      << static_cast<double>(duration_internal.count()) << " msec\n";
        }

        auto t1 = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t1 - t0);

        std::cout << "Total time for " << numRounds << " rounds: " << duration.count() << " msec\n";
        std::cout << "Average time per round: " << static_cast<double>(duration.count()) / numRounds
                  << " msec\n";

        return result;
    }

private:
};

#endif // MEASURE_H
