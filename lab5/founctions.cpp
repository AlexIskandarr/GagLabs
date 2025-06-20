#include <iostream>
#include <random>

int64_t** allocateMatrix(int64_t rows, int64_t cols) {
    int64_t** matrix{new int64_t*[rows]};
    for (int32_t i{0}; i < rows; ++i) {
        matrix[i] = new int64_t[cols]{};
    }
    return matrix;
}

void fillArrayWithRandom(int64_t*& array, int32_t size, int32_t lowerBound, int32_t upperBound) {
    std::random_device rd;              
    std::mt19937 gen(rd());             
    std::uniform_real_distribution<> dis(lowerBound, upperBound); 

    for (int32_t i {}; i < size; ++i) {
        array[i] = dis(gen);
    }
}

void freeMatrix(int64_t** matrix, int64_t rows) {
    for (int32_t i {}; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int32_t CountNegativeInLowerRightTriangle(int64_t** matrix, int64_t size) {
    int32_t count {};
    for (int32_t i {}; i < size; ++i) {
        for (int32_t j {}; j < size; ++j) {
            if ((i + j >= size - 1) && (matrix[i][j] < 0)) {
                ++count;
            }
        }
    }
    return count;
}

void printMaxInEachNonPositiveColumn(int64_t** matrix, int64_t rows, int64_t cols) {
    bool has_any = false;
    for (int32_t j {}; j < cols; ++j) {
        bool has_positive = false;

        for (int32_t i {}; i < rows; ++i) {
            if (matrix[i][j] > 0) {
                has_positive = true;
                break;
            }
        }
        
        if (!has_positive) {
            has_any = true;
            int32_t col_max = matrix[0][j];
            for (int32_t i = 1; i < rows; ++i) {
                if (matrix[i][j] > col_max) {
                    col_max = matrix[i][j];
                }
            }
            std::cout << "Column " << j << " max: " << col_max << "\n";
        }
    }
    if (!has_any) {
        std::cout << "No valid columns found\n";
    }
}

int32_t calculateSum(int64_t** matrix, int64_t rows) {
    int32_t totalSum = 0;
    int32_t mainDiagSum = 0;
    
    for (int32_t i {}; i < rows; ++i) {
        for (int32_t j {}; j < rows; ++j) {
            totalSum += matrix[i][j];
        }
        mainDiagSum += matrix[i][i];
    }
    
    return totalSum - mainDiagSum;
}

int32_t findFirstNonNegativeRow(int64_t** matrix, int64_t rows) {
    for (int32_t i {}; i < rows; ++i) {
        bool hasNegative = false;
        for (int32_t j {}; j < rows; ++j) {
            if (matrix[i][j] < 0) {
                hasNegative = true;
                break;
            }
        }
        if (!hasNegative) return i + 1; 
    }
    return -1;
}