#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>
#include <algorithm>
#include "sort.h"

struct Student {
	int32_t course;
	int32_t group;
	std::string name;
	int32_t grades[3];
};

bool operator<(const Student& a, const Student& b);
bool operator>(const Student& a, const Student& b);
std::ostream& operator<<(std::ostream& out, const Student& student);


void CheckInputFile(std::ifstream& fin);
void CheckOutputFile(std::ofstream& fout);


void InputChoice(int32_t&);
void InputType(char& type);
void InputFileName(std::string& fileName);
void ChouseType(char type);
bool ChouseSort();
void ChouseTypeOfSort(int32_t& typeOfSort);

void InputSize(int32_t& size);

template <typename T>
int32_t CountSize(std::string& fileName)
{
	std::ifstream fin(fileName);
	CheckInputFile(fin);
	T element{};
	int32_t count{};
	while (fin >> element)
	{
		++count;
	}
	fin.close();
	return count;
}

template<>
inline int32_t CountSize<Student>(std::string& fileName)
{
    std::ifstream fin(fileName);
    CheckInputFile(fin);
    std::string line;
    int32_t count {};
    while (std::getline(fin, line)) {
        if (!line.empty()) {
            ++count;
        }
    }
    fin.close();
    return count;
}


template<typename T>
void ReadFromFile(std::string& filename, T* arr, int32_t size) {
	std::ifstream fin(filename);
	CheckInputFile(fin);
	for (int32_t i{}; i < size; ++i)
	{
		fin >> arr[i];
	}
	fin.close();
}
template<typename T>
void WriteToFile(std::string& filename, T* arr, int32_t size) {
	std::ofstream fout(filename);
	CheckOutputFile(fout);
	for (int32_t i{}; i < size; ++i)
	{
		fout << arr[i] << " ";
	}
	fout.close();
}
template<typename T>
void InputFromConsole(T* arr, int32_t size)
{
	std::cout << "input array\n";
	for (int32_t i{}; i < size; ++i)
	{
		std::cin >> arr[i];
	}
}
void InputFromConsole(Student* arr, int32_t size);


template <typename T>
void InputInterval(T& firstElement, T& lastElement)
{
    std::cout << "Input first element in interval\n";
    std::cin >> firstElement;
    std::cout << "Input last element in interval\n";
    std::cin >> lastElement;

    if (firstElement > lastElement)
    {
        std::swap(firstElement, lastElement);
    }
    else if (firstElement == lastElement)
    {
        throw std::invalid_argument("Impossible to complete. Wrong interval\n");
    }
}

void GenerateRandom(int32_t* arr, int32_t size);
void GenerateRandom(double* arr, int32_t size);
void GenerateRandom(char* arr, int32_t size);
std::string GenerateRandomStr();
void GenerateRandom(std::string* arr, int32_t size);
void GenerateRandom(Student* arr, int32_t size);



template <typename T>
void SortArray(T* arr, int32_t size)
{
	int32_t typeOfSort{};
	ChouseTypeOfSort(typeOfSort);
	switch (typeOfSort)
	{
	case 1:
	{
		bool sort{ ChouseSort() };
		ShowArray(arr, size);
		auto start = std::chrono::high_resolution_clock::now();
		BubbleSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 2:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		CombSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 3:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		InsertionSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 4:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		SelectionSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 5:
	{
		bool sort{ ChouseSort() };
		ShowArray(arr, size);
		auto start = std::chrono::high_resolution_clock::now();
		QuickSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 6:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		MergeSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	case 7:
	{
		bool sort{ ChouseSort() };
		auto start = std::chrono::high_resolution_clock::now();
		CocktailSort(arr, size, sort);
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> time = end - start;
		std::cout << "Sort worked: " << time.count() << " seconds\n";
		break;
	}
	default:
	{
		throw std::invalid_argument("false choice\n");
		break;
	}

	}

}

template<typename T>
void ChouseInputAndOutput(int32_t choice, T*& arr)
{
	switch (choice)
	{
	case 1:
	{
		int32_t size{};
		InputSize(size);
		arr = new T[size];
		InputFromConsole(arr, size);
		SortArray(arr, size);

		std::string filename;
		InputFileName(filename);
		WriteToFile(filename, arr, size);
		delete[] arr;
		break;
	}
	case 2:
	{
		int32_t size{};
		InputSize(size);
		arr = new T[size];
		GenerateRandom(arr, size);
		SortArray(arr, size);

		std::string filename;
		InputFileName(filename);
		WriteToFile(filename, arr, size);
		delete[] arr;
		break;
	}
	case 3:
	{
		std::string fileName;
		InputFileName(fileName);
		int32_t size = CountSize<T>(fileName);
		arr = new T[size];
		ReadFromFile(fileName, arr, size);
		SortArray(arr, size);

		ShowArray(arr, size);
		delete[] arr;
		break;
	}
	default:
	{
		throw std::invalid_argument("false choice\n");
		break;
	}
	}
}


#endif