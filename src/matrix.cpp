#include "../include/martix.h"

 Matrix::Matrix() {
    this->generate_array();
}

void Matrix::generate_array(){
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
    std::uniform_int_distribution<int> distrib(boundaries.first, boundaries.second);

    for (int i{}; i < LEN; i++) {
        for (int j{}; j < LEN; j++) {
            array[i][j] = distrib(gen);
        }
    }
}

void Matrix::print_array() {
    unsigned long long temp_max = 0;
    for (int i{}; i < LEN; i++) {
        for (int j{}; j < LEN; j++) {
            if (std::to_string(array[i][j]).size() > temp_max)
                temp_max = std::to_string(array[i][j]).size();
        }
    }
    for (int i{}; i < LEN; i++) {
        for (int j{}; j < LEN; j++) {
            std::cout << std::setw((int) temp_max) << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::get_max_elem_in_even_columns() {
    int temp_max = -INT_MAX - 1;
    for (int j{1}; j < LEN; j += 2) {
        for (int i{0}; i < LEN; i++) {
            if (array[i][j] > temp_max)
                temp_max = array[i][j];
        }
    }
    return temp_max;
}

bool Matrix::are_main_and_secondary_diagonals_equal() {
    for(int i{0}; i < LEN; i++) {
        if (array[i][i] != array[i][LEN- 1 - i]) {
            return false;
        }
    }

    return true;
}

bool Matrix::get_min_element_beneath_main_diagonal () {
    int min_element{INT_MAX};
    for(int i{0}; i < LEN; i++) {
        for (int j{0}; j < i; j++) {
            min_element = std::min(min_element, array[i][j]);
        }
    }
    return min_element;
}
