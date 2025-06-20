#include <iostream>

int64_t** allocateMatrix(int64_t, int64_t);
void fillArrayWithRandom(int32_t*&, int32_t, int32_t, int32_t);
void freeMatrix(int64_t**, int64_t);
int32_t CountNegativeInLowerRightTriangle(int64_t**, int64_t);
void printMaxInEachNonPositiveColumn(int64_t**, int64_t, int64_t);
int32_t calculateSum(int64_t**, int64_t);
int32_t findFirstNonNegativeRow(int64_t**, int64_t);
