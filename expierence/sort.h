#ifndef SORT_H
#define SORT_H


#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

template<typename T>
void ShowArray(T* arr, int32_t size)
{
	for (int32_t i{}; i < size; ++i)
	{
		std::cout << arr[i] << '\t';
	}
	std::cout << '\n';
}

template<typename T>
bool compare(const T& a, const T& b, bool sort) {
    return sort ? (a < b) : (a > b);
}

template<typename T>
void BubbleSort(T* arr, int32_t size, bool sort) {
    if (size <= 1) return;

    bool swapped;
    for (int32_t i = 0; i < size - 1; ++i) {
        swapped = false;
        for (int32_t j = 0; j < size - i - 1; ++j) {

            if (compare(arr[j], arr[j + 1], sort)) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped){
			 break;
		}
		ShowArray(arr, size);
    }
	ShowArray(arr, size);
} 

template <typename T>
void CombSort(T* arr, int32_t size, bool sort)
{
    double factor = 1.2473309; 
    int32_t step = size;
    bool swapped = true;

    while (step > 1 || swapped) {
        step = static_cast<int32_t>(step / factor);
        if (step < 1) {
            step = 1;
        }

        swapped = false;
        for (int32_t i {}; i + step < size; ++i)
        {
            if (compare(arr[i], arr[i + step], sort)) {
                std::swap(arr[i], arr[i + step]);
                swapped = true;
            }
        }
        ShowArray(arr, size);
    }
}

template<typename T>
void InsertionSort(T* arr, int32_t size, bool sort)
{
	ShowArray(arr, size);
	for (int32_t i{ 1 }; i < size; i++)
	{
		int32_t j{ i - 1 };

		while (j >= 0 && compare(arr[j], arr[j + 1], sort))
		{
			std::swap(arr[j], arr[j + 1]);
			--j;
			ShowArray(arr, size);
		}
	}
}


template<typename T>
void SelectionSort(T* arr, int32_t size, bool sort) {

    for (int32_t i = 0; i < size - 1; ++i) {
        int32_t selected_index = i;

        for (int32_t j = i + 1; j < size; ++j) {
 
            if (compare(arr[j], arr[selected_index], sort)){
                selected_index = j;
            }
        }

        if (selected_index != i) {
            std::swap(arr[i], arr[selected_index]);
			ShowArray(arr, size);
        }
    }
}

template<typename T>
int32_t partitionHoare(T* arr, int32_t start, int32_t finish, bool sort, int32_t size) {

    T pivot_value = arr[start + (finish - start) / 2];

    int32_t i = start - 1;
    int32_t j = finish + 1;

    while (true) {
        do {
            ++i;
        } while (compare(arr[i], pivot_value, sort));

        do {
            --j;
        } while (compare(pivot_value, arr[j], sort));

        if (i >= j) {
            return j; 
        }

        std::swap(arr[i], arr[j]);

    }
}

template<typename T>
void quicksortHoareRecursive(T* arr, int32_t start, int32_t finish, bool sort, int32_t size) {
    if (start < finish) {

        int32_t pivot_index = partitionHoare(arr, start, finish, sort, size);
		ShowArray(arr, size);
        quicksortHoareRecursive(arr, start, pivot_index, sort, size);
        quicksortHoareRecursive(arr, pivot_index + 1, finish, sort, size);
    }
}

template<typename T>
void QuickSort(T* arr, int32_t size, bool sort) {
    if (size > 1) {
        quicksortHoareRecursive(arr, 0, size - 1, sort, size);
    }
}

template<typename T>
void merge(T* arr, int32_t start, int32_t mid, int32_t finish, bool sort, int32_t size) {
    int32_t first_part = mid - start + 1;
    int32_t second_part = finish - mid;

    T* leftArray = new T[first_part];
    T* rightArray = new T[second_part];

    for(int32_t i = 0; i < first_part; ++i) {
        leftArray[i] = arr[start + i];
    }
    for(int32_t j = 0; j < second_part; ++j) {
        rightArray[j] = arr[mid + 1 + j];
    }

    int32_t i = 0;
    int32_t j = 0;
    int32_t k = start;

    while (i < first_part && j < second_part) {

        if (compare(leftArray[i], rightArray[j], sort)) {
            arr[k] = leftArray[i];
            ++i;
        }
        else {
            arr[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    while (i < first_part) {
        arr[k] = leftArray[i];
        ++i;
        ++k;
    }

    while (j < second_part) {
        arr[k] = rightArray[j];
        ++j;
        ++k;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template<typename T>
void  MergeSortInside(T* arr, int32_t start, int32_t finish, bool sort, int32_t size) {
    if(start >= finish) {
        return;
    }

    int32_t mid = start + (finish - start) / 2;

    MergeSortInside(arr, start, mid, sort, size);
    MergeSortInside(arr, mid + 1, finish, sort, size);
    merge(arr, start, mid, finish, sort, size);
	ShowArray(arr, size);
}

template<typename T>
void MergeSort(T* arr, int32_t size, bool sort) {
    if (size < 2) {
        return;
    }
    MergeSortInside(arr, 0, size - 1, sort, size);
}

template<typename T>
void CocktailSort(T* arr, int32_t size, bool sort)
{
	ShowArray(arr, size);
	int32_t left{};
	int32_t right{ size };
	bool swap{ true };
	while (swap)
	{
		swap = false;
		for (int32_t i{ left }; i < right - 1; ++i)
		{
			if (compare(arr[i], arr[i + 1], sort))
			{
				std::swap(arr[i], arr[i + 1]);
				swap = true;
				ShowArray(arr, size);
			}
		}
		--right;
		for (int32_t i{ right }; i > left; --i)
		{
			if (compare( arr[i - 1], arr[i], sort)) 
			{
				std::swap(arr[i], arr[i - 1]);
				swap = true;
				ShowArray(arr, size);
			}
		}
		++left;
	}
}
#endif