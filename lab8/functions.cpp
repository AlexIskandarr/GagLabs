#include "functions.h"

void merge(double* arr, int32_t start, int32_t mid, int32_t finish, bool ascending) {
    int32_t first_part = mid - start + 1;
    int32_t second_part = finish - mid;

    double* leftArray = new double[first_part];
    double* rightArray = new double[second_part];

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

        if (ascending ? (leftArray[i] <= rightArray[j]) : (leftArray[i] >= rightArray[j])) {
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

void mergeSort(double* arr, int32_t start, int32_t finish, bool ascending) {
    if(start >= finish) {
        return;
    }

    int32_t mid = start + (finish - start) / 2;

    mergeSort(arr, start, mid, ascending);
    mergeSort(arr, mid + 1, finish, ascending);
    merge(arr, start, mid, finish, ascending);
}

void selectionSort(double* arr, int32_t size, bool ascending) {
    for(int32_t i = 0; i < size - 1; ++i) {
        int32_t selected_index = i; 

        for(int32_t j = i + 1; j < size; ++j) {

            if(ascending ? (arr[j] < arr[selected_index]) : (arr[j] > arr[selected_index])) {
                selected_index = j;
            }
        }

        if (selected_index != i) {
            std::swap(arr[i], arr[selected_index]);
        }
    }
}

void insertionSort(double* arr, int32_t size, bool ascending) {
    for(int32_t i = 1; i < size; ++i) {
        double key = arr[i];
        int32_t j = i - 1;

        while(j >= 0 && (ascending ? (arr[j] > key) : (arr[j] < key))) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

int32_t partitionHoare(double* arr, int32_t start, int32_t finish, bool ascending) {
    double pivot_value = arr[start + (finish - start) / 2];
    
    int32_t i = start - 1;
    int32_t j = finish + 1;

    while (true) {
        do {
            ++i;
        } while (ascending ? (arr[i] < pivot_value) : (arr[i] > pivot_value));

        do {
            --j;
        } while (ascending ? (arr[j] > pivot_value) : (arr[j] < pivot_value));

        if (i >= j) {
            return j;
        }

        std::swap(arr[i], arr[j]);
    }
}

void quicksortHoare(double* arr, int32_t start, int32_t finish, bool ascending) {
    if (start < finish) {
        int32_t piv = partitionHoare(arr, start, finish, ascending);
        quicksortHoare(arr, start, piv, ascending);
        quicksortHoare(arr, piv + 1, finish, ascending);
    }
}

void shaker_sort(double* arr, int32_t size, bool ascending) 
{
    bool swapped = true;
    int32_t left = 0;
    int32_t right = size - 1;

    while(swapped && left < right) 
    {
        swapped = false;
        
        for(int32_t i = left; i < right; i++) 
        {
            if(ascending ? (arr[i] > arr[i + 1]) : (arr[i] < arr[i + 1])) 
            {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        
        if(!swapped) 
        {
            break;
        }
        
        --right;
        swapped = false;
        
        for(int32_t i = right; i > left; i--) 
        {
            if(ascending ? (arr[i] < arr[i - 1]) : (arr[i] > arr[i - 1])) 
            {
                std::swap(arr[i], arr[i - 1]);
                swapped = true;
            }
        }
        ++left;
    }
}

void CheckInputFIle(std::ifstream& fin) {

	if (!fin.good()) {
		throw "file doesnt exist";
	}
	if (!fin) {
		throw "input file error";
	}
	if (fin.peek() == EOF) {
		throw "this file is empty";
    }
}

void CheckOutputFile(std::ofstream& fout){

    if (!fout.good()){
        throw "file doesn't exist\n";
    }
    if (!fout){
        throw "output file error\n";
    }

}

void FillArray(double* array, int32_t size) {
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << i + 1 << ": ";
		std::cin >> array[i];
	}
}

void sortArray(double* numArray, int32_t size) {
    int32_t choiseSort{};

    std::cout << "\n choise type of sort: \n";
    std::cout << "[1] - quick sort\n";
    std::cout << "[2] - Insertion sort\n";
    std::cout << "[3] - selection sort\n";
    std::cout << "[4] - Merge sort\n";
    std::cout << "[5] - Shaker sor\n";
    std::cin >> choiseSort;

    bool ascending = true;
    int32_t choise{};
     if (choiseSort != 6) {
        std::cout << "\n choise character of sprt: \n";
        std::cout << "[1] - low to high\n";
        std::cout << "[2] - high to low\n";
        std::cin >> choise;
    }

    if (choise == 1) {
        ascending = true;
    } else {
        ascending = false;
        
        if (choise != 2) {
        std::cout << "mistake with choise, program work: high to low\n";
        }
    }

    try {
        switch (choiseSort) {
        case 1: 
            quicksortHoare(numArray, 0, size - 1, ascending);
            break;
        case 2:
            insertionSort(numArray, size, ascending);
            break;
        case 3:
            selectionSort(numArray, size, ascending);
            break;
        case 4:
            mergeSort(numArray, 0, size - 1, ascending);
            break;
        case 5:
            shaker_sort(numArray, size, ascending);
            break;
        default:
            throw std::invalid_argument("incorrect type");
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

}

int32_t  NumberOfNumbersInFile(std::ifstream& fin) {
	int32_t count{};
	std::string word;
	while (fin >> word) {
		++count;
	}
	return count;

}

void fillArrayFromFile(std::ifstream& fin, double*& array, int32_t size) {
	fin.clear();
    fin.seekg(0);
    delete[] array; 
    array = new double[size];
	std::string word;
	for (int32_t i = 0; i < size; ++i) {
		fin >> word;
		array[i] = std::stod(word);
	}
}

void FillFileFromArray(std::ofstream& fout, double* array, int32_t size) {
	for (size_t i = 0; i < size; i++)
	{
		fout << array[i] << ' ';
	}
}

void PrintArray(double* array, int32_t size) {
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << array[i] << ' ';
	}
}

void InputInfoStudents(Student* students, int32_t size) {
	for (int32_t i = 0; i < size; ++i)
	{
		std::cin.ignore();
		std::cout << "input " << i + 1 << " student\n";
		std::cout << "input name: ";
		std::getline(std::cin, students[i].name);
		std::cout << "input surname: ";
		std::getline(std::cin, students[i].surname);
		std::cout << "input course: ";
		std::cin >> students[i].course;
		std::cout << "input 5 marks:\n";
		for (size_t j = 0; j < 5; ++j)
		{
			std::cin >> students[i].marks[j];
		}
	}
}

double AverageMark(Student& student) {
	int32_t sum{};
	for (int32_t j = 0; j < 5; ++j) {
		sum += student.marks[j];
	}
	return sum / 5.0;
}

void BubleSortForStudents(Student* student, double* averageMarks, int32_t size) {
	for (int32_t i = 0; i < size - 1; ++i) {
		bool flag = false;
		for (int32_t j = 0; j < size - i - 1; ++j) {
			if (averageMarks[j] > averageMarks[j + 1]) {
				std::swap(averageMarks[j], averageMarks[j + 1]);
				std::swap(student[j], student[j + 1]);
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}
}

void PrintStudents(Student* students, int32_t size, double* averageMark) {
	for (int32_t i = 0; i < size; ++i) {

		std::cout << i + 1 << ") " << students[i].name << ' ';
		std::cout << students[i].surname << ' ';
		std::cout << "aver mark: " << averageMark[i];

		std::cout << '\n';
	}
}

