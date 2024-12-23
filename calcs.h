#ifndef CALCS_H
#define CALCS_H

#include <iostream>
#include <random>
#include <array>

constexpr auto NUM_RANDS = 1000;

class Calcs
{
public:
    Calcs()
    {
        std::uniform_int_distribution<> dis(1, 100000);
        std::uniform_int_distribution<> small_dis(1, NUM_RANDS);
        std::random_device rd; // Used to seed the generator
        std::mt19937 gen(rd());

        for (auto i = 0; i < NUM_RANDS; ++i) {
            random_numbers[i] = dis(gen);
        }

        for (auto j = 0; j < 10; ++j) {
            sum = random_numbers[small_dis(gen)] + random_numbers[small_dis(gen)]
                  + random_numbers[small_dis(gen)];
        }
    }

    ~Calcs() {}

    int calc(int seed)
    {
        std::uniform_int_distribution<> dis(1, 100000);
        std::uniform_int_distribution<> small_dis(1, NUM_RANDS);
        std::random_device rd; // Used to seed the generator
        std::mt19937 gen(seed);

        int s = 0;

        for (auto k = 0; k < 1000; ++k) {
            // std::cout << k << std::endl;
            for (auto j = 0; j < 10000; ++j) {
                s += random_numbers[small_dis(gen)] + random_numbers[small_dis(gen)]
                     + random_numbers[small_dis(gen)];
                s %= 332432;
            }
        }
        std::cout << s << std::endl;

        return s;
    }

private:
    // Generate a random number

    std::array<int, NUM_RANDS> random_numbers;
    std::array<int, NUM_RANDS> random_indices;

    int sum;
};

#endif // CALCS_H
