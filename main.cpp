#include <iostream>
#include <iomanip>
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

/// Prints a 17x17 two-dimensional array with even spacing based on the max element contained in each line
/// \param arr std::array containing 17 std::array containers of 17 int
/// Parameter is taken by reference.
void print_array(const std::array<std::array<int, 17>, 17> &arr) {
    unsigned long long temp_max = 0;
    for (int i{}; i < LEN; i++) {
        for (int j{}; j < LEN; j++) {
            if (std::to_string(arr[i][j]).size() > temp_max)
                temp_max = std::to_string(arr[i][j]).size();
        }
    }
    for (int i{}; i < LEN; i++) {
        for (int j{}; j < LEN; j++) {
            std::cout << std::setw((int) temp_max) << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


/// Returns the maximum elements contained in each line of a 2D array
/// \param arr std::array containing 17 std::array containers of 17 int
/// Parameter is taken by reference.
int get_max_elem_in_even_columns(std::array<std::array<int, 17>, 17> &arr) {
    int temp_max = -INT_MAX - 1;
    for (int j{1}; j < LEN; j += 2) {
        for (int i{0}; i < LEN; i++) {
            if (arr[i][j] > temp_max)
                temp_max = arr[i][j];
        }
    }
    return temp_max;
}

/// Checks if elements on main and secondary diagonals are equal respectively
/// \param arr std::array containing 17 std::array containers of 17 int
/// \returns bool - result of comparison
bool are_main_and_secondary_diagonals_equal(const std::array<std::array<int, 17>, 17> &arr) {
    for(int i{0}; i < LEN; i++) {
        if (arr[i][i] != arr[i][16 - i]) {
            return false;
        }
    }

    return true;
}


/// Returns the minimum element contained beneath the main diagonal of a 2D array
/// \param arr std::array containing 17 std::array containers of 17 int
/// \returns int - the minimum element
bool get_min_element_beneath_main_diagonal (const std::array<std::array<int, 17>, 17> &arr) {
    int min_element{INT_MAX};
    for(int i{0}; i < LEN; i++) {
        for (int j{0}; j < i; j++) {
            min_element = std::min(min_element, arr[i][j]);
        }
    }
    return min_element;
}

int main() {
    return 0;
}
