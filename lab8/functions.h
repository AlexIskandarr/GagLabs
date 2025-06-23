#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>


struct Student {
	std::string name;
	std::string surname;
	int32_t course;
	int32_t marks[5];
};


void merge(double* arr, int32_t start, int32_t mid, int32_t finish, bool ascending);
void mergeSort(double* arr, int32_t start, int32_t finish, bool ascending);
void selectionSort(double* arr, int32_t size, bool ascending);
void insertionSort(double* arr, int32_t size, bool ascending);
int32_t partitionHoare(double* arr, int32_t start, int32_t finish, bool ascending);
void quicksortHoare(double* arr, int32_t start, int32_t finish, bool ascending);
void shaker_sort(double* arr, int32_t size, bool ascending);
void CheckInputFIle(std::ifstream& fin);
void fillArrayFromFile(std::ifstream& fin, double*& array, int32_t size);
void sortArray(double* arr, int32_t size);
int32_t NumberOfNumbersInFile(std::ifstream& fin);
void FillArray(double* array, int32_t size);
void FillFileFromArray(std::ofstream& fout, double* array, int32_t size);
void PrintArray(double* array, int32_t size);
void CheckOutputFile(std::ofstream& fout);
void InputInfoStudents(Student* students, int32_t size);
double AverageMark(Student& student);
void BubleSortForStudents(Student* student, double* averageMarks, int32_t size);
void PrintStudents(Student* students, int32_t size, double* averageMark);
