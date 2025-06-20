#include <iostream>
#include <ctime>

void PrintArray(int64_t* arr, int32_t size) {
    for (int32_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void PrintArray(double* arr, int32_t size) {
    for (int32_t i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

void InputSize(int32_t& size){
    std::cout << '\n' << "Enter your size:";
    std::cin >> size;
}

void FillDoubleArrayManually(double* arr,int32_t size){
    for (int32_t i = 0; i < size; ++i){
       std::cin >> arr[i];
   }
}

void FillIntegerArrayManually(int64_t* arr,int32_t size){
    for (int32_t i = 0; i < size; ++i){
       std::cin >> arr[i];
   }
}

void FillIntegerArrayWithRand(int64_t* arr, int32_t size, int32_t int_right_border, int32_t int_left_border){
    for ( int32_t i{}; i < size ; ++i){
        arr[i] = int_left_border + rand() % (int_right_border - int_left_border + 1);
    }
}

void FillDoubleArrayWithRand(double* arr, int32_t size, double double_right_border, double double_left_border){
    for ( int32_t i{}; i < size ; ++i){
        arr[i] = double_left_border + (rand()) / (RAND_MAX / (double_right_border - double_left_border));
    }
}

int32_t minAbsElement(int64_t* arr, int32_t size) {
    int32_t min_val = arr[0];
    for (int i = 1; i < size; ++i) {
        if (abs(arr[i]) < abs(min_val)) {
            min_val = arr[i];
        }
    }
    return min_val;
}

int32_t sumAfterLastZero(int64_t* arr, int32_t size) {
    int32_t last_zero {-1};
    for (int32_t i = size - 1; i >= 0; --i) {
        if (arr[i] == 0) {
            last_zero = i;
            break;
        }
    }
    
    if (last_zero == -1 || last_zero == size - 1) return 0;
    
    int32_t sum {};
    for (int32_t i {last_zero + 1}; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

void rearrangeEvenOddNumbers(double* arr, int32_t size) {
    int32_t insert_pos {}; 
    
    for (int32_t i {}; i < size; ++i) {
        if ((i + 1) % 2 == 0) {
            if (i != insert_pos) {
                double temp = arr[i];
                for (int j = i; j > insert_pos; --j) {
                    arr[j] = arr[j - 1];
                }
                arr[insert_pos] = temp;
            }
            ++insert_pos; 
        }
    }
}

int32_t countUniqueElements(double* arr, int32_t size) {
    int32_t unique_count {};
    for (int32_t i {}; i < size; ++i) {
        bool is_unique = true;
     
        for (int32_t j {}; j < i; ++j) {
            if (arr[i] == arr[j]) {
                is_unique = false;
                break;
            }
        }
        if (is_unique) {
            ++unique_count;
        }
    }
    return unique_count;
}

void rearrangeArrayInPlace(double* arr, int32_t size) {
    int32_t insert_pos {};

    for (int32_t i {}; i < size; ++i) {
        if (arr[i] < 0) {
            if (i != insert_pos) { 
                double temp = arr[i];
                for (int32_t j {i}; j > insert_pos; --j) {
                    arr[j] = arr[j - 1];
                }
                arr[insert_pos] = temp;
            }
            ++insert_pos;
        }
    }

    for (int32_t i {insert_pos}; i < size; ++i) {
        if (arr[i] == 0) {
            if (i != insert_pos) {
                double temp = arr[i];
                for (int32_t j {i}; j > insert_pos; --j) {
                    arr[j] = arr[j - 1];
                }
                arr[insert_pos] = temp;
            }
            ++insert_pos;
        }
    }
}