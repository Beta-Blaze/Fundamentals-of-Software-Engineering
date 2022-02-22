#ifndef FUNDAMENTALS_OF_SOFTWARE_ENGINEERING_MARTIX_H
#define FUNDAMENTALS_OF_SOFTWARE_ENGINEERING_MARTIX_H

#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <array>

class Matrix {
    const std::pair<int, int> boundaries{-10, 10};
    static const int LEN{17};
    std::array<std::array<int, LEN>, LEN> array;

public:
    Matrix();

    /// Fills a 17x17 two-dimensional array with random numbers.
    void generate_array();

/// Prints a 17x17 two-dimensional array with even spacing based on the max element contained in each line
    void print_array();


/// Returns the maximum elements contained in each line of a 2D array
    int get_max_elem_in_even_columns();

/// Checks if elements on main and secondary diagonals are equal respectively
/// \returns bool - result of comparison
    bool are_main_and_secondary_diagonals_equal();

/// Returns the minimum element contained beneath the main diagonal of a 2D array
/// \returns int - the minimum element
    bool get_min_element_beneath_main_diagonal();

};

#endif //FUNDAMENTALS_OF_SOFTWARE_ENGINEERING_MARTIX_H
