#include <iostream>
#include <chrono>
#include <random>
#include <array>

const int LEN{17};

/// Fills a 17x17 two-dimensional array with random numbers.
/// \param arr std::array containing 17 std::array containers of 17 int
/// Parameter is taken by reference.
void generate_array(std::array<std::array<int, 17>, 17> &arr){
    std::random_device rd;
    // seed value is designed specifically to make initialization
    // parameters of std::mt19937 (instance of std::mersenne_twister_engine<>)
    // different across executions of application
    std::mt19937::result_type seed = rd() ^
                                     ((std::mt19937::result_type) std::chrono::duration_cast<std::chrono::seconds>(
                                             std::chrono::system_clock::now().time_since_epoch()).count() +
                                      (std::mt19937::result_type) std::chrono::duration_cast<std::chrono::microseconds>(
                                              std::chrono::high_resolution_clock::now().time_since_epoch()).count());
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> distrib(-100, 100);

    for (int i{}; i < LEN; i++) {
        for (int j{}; j < LEN; j++) {
            arr[i][j] = distrib(gen);
        }
    }
}

int main() {
    return 0;
}
