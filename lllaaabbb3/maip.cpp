#include "header.h"
#include <iostream>
#include <ctime>


int main() {
    int32_t size{};
    int32_t int_right_border{};
    int32_t int_left_border{};
    double double_right_border{};
    double double_left_border{};

    srand(time(0));

    try {
        std::cout << "Enter size: ";
        std::cin >> size;
        if (size > 100 || size <= 0) {
            throw std::invalid_argument("Size must be between 1 and 100");
        }

        int64_t* int_dynamic_array = new int64_t[size];
        double* double_dynamic_array = new double[size];

        std::cout << "Enter int left border: ";
        std::cin >> int_left_border;
        std::cout << "Enter int right border: ";
        std::cin >> int_right_border;
        if (int_left_border >= int_right_border) {
            throw std::range_error("Int left border must be less than right");
        }

        std::cout << "Enter double left border: ";
        std::cin >> double_left_border;
        std::cout << "Enter double right border: ";
        std::cin >> double_right_border;
        if (double_left_border >= double_right_border) {
            throw std::range_error("Double left border must be less than right");
        }

        char choice{};
        std::cout << "Fill arrays manually (m) or randomly (r)? ";
        std::cin >> choice;

        if (choice == 'm') {
            std::cout << "Enter " << size << " integers:\n";
            FillIntegerArrayManually(int_dynamic_array, size);

            std::cout << "Enter " << size << " doubles:\n";
            FillDoubleArrayManually(double_dynamic_array, size);
        } else if (choice == 'r') {
            FillIntegerArrayWithRand(int_dynamic_array, size, int_right_border, int_left_border);
            FillDoubleArrayWithRand(double_dynamic_array, size, double_right_border, double_left_border);
        } else {
            throw std::invalid_argument("Invalid choice. Use 'm' or 'r'.");
        }

        std::cout << "\nInteger array:\n";
        PrintArray(int_dynamic_array, size);
        std::cout << "\nDouble array:\n";
        PrintArray(double_dynamic_array, size);

        int32_t min_abs = minAbsElement(int_dynamic_array, size);
        std::cout << "\nMinimum absolute element (int): " << min_abs << '\n';

        int32_t sum_zero = sumAfterLastZero(int_dynamic_array, size);
        std::cout << "Sum after last zero (int): " << sum_zero;

        rearrangeEvenOddNumbers(double_dynamic_array, size);
        std::cout << "\nAfter rearranging even-odd positions (double):\n";
        PrintArray(double_dynamic_array, size);

        int32_t unique = countUniqueElements(double_dynamic_array, size);
        std::cout << "\nNumber of unique elements (double): " << unique;

        rearrangeArrayInPlace(double_dynamic_array, size);
        std::cout << "\nAfter rearranging negatives, zeros (double):\n";
        PrintArray(double_dynamic_array, size);

        delete[] int_dynamic_array;
        delete[] double_dynamic_array;

        std::cout << "\nGreat job! Program finished successfully.\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << '\n';
    } catch (const std::range_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }

    return 0;
}