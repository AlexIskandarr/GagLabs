#include "founctions.h"
#include <iostream>
#include <stdexcept>
#include <random>

int main(){
    try {
        int64_t rows{};
        int64_t cols{};

        std::cout << "Enter number of rows: ";
        std::cin >> rows;
        if ( rows <= 0) {
            throw std::invalid_argument("Invalid input for rows. Must be a positive integer.");
        }

        std::cout << "Enter number of columns: ";
        std::cin >> cols;
        if ( cols <= 0) {
            throw std::invalid_argument("Invalid input for columns. Must be a positive integer.");
        }

        if (rows != cols) {
            throw std::invalid_argument("Matrix must be square");
        }


        int64_t** matrix = allocateMatrix(rows, cols);

        std::cout << "\nColumn max in non-positive columns:\n";
        printMaxInEachNonPositiveColumn(matrix, rows, cols);

        int64_t counter = CountNegativeInLowerRightTriangle(matrix, rows); 
        std::cout << "Negative elements in lower-right triangle: " 
                << counter << "\n";

        int32_t sum {calculateSum(matrix, rows)};
        std::cout << "sum of elements without main diagonals: " << sum << '\n';

        int32_t NumberOfRow {findFirstNonNegativeRow(matrix, rows)};
        std::cout << "number of first row without nagative" << NumberOfRow << '\n';
        
        freeMatrix(matrix, rows);
        return 0;
    } 
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << '/';
        return 1;
    }
}