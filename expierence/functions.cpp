#include "header.h"

void CheckInputFile(std::ifstream& fin)
{
    if (!fin.good())
    {
        throw std::runtime_error("File doesn't exist \n");
    }
    if (!fin)
    {
        throw std::runtime_error("input file error\n");
    }
    if (fin.peek() == EOF)
    {
        throw std::runtime_error("file is empty\n");
    }
}


void CheckOutputFile(std::ofstream& fout)
{
    if (!fout)
    {
        throw std::runtime_error("output file error\n");
    }
}

bool operator<(const Student& a, const Student& b) {

    if (a.course != b.course) {
        return a.course < b.course;
    }

    if (a.group != b.group) {
        return a.group < b.group;
    }

    return a.name < b.name;
}

bool operator>(const Student& a, const Student& b) {
    if (a.course != b.course) {
        return a.course > b.course;
    }
    if (a.group != b.group) {
        return a.group > b.group;
    }
    return a.name > b.name;
}

void InputChoice(int32_t& choice)
{
    std::cout << "input choice:\n";
    std::cout << "1 - direct input and output to file;\n";
    std::cout << "2 - generation of data random and output to file;\n" ;
    std::cout << "3 - input from file and output to console\n";
    std::cin >> choice;
}

void InputSize(int32_t& size)
{
    std::cout << "input size\n";
    std::cin >> size;
    if (size < 0 || size > 1001)
    {
        throw std::invalid_argument("false size\n");
    }
}

void InputType(char& type)
{
    std::cout << "input type of data: \n";
    std::cout << "1 - int\n";
    std::cout << "2 - double\n"; 
    std::cout << "3 - char\n";
    std::cout << "4 - string\n"; 
    std::cout << "5 - student\n";
    std::cin >> type;

}

void InputFileName(std::string& fileName)
{
    std::cin.ignore();
    std::cout << "input name of file\n";
    getline(std::cin, fileName);
}

bool ChouseSort()
{
    bool sort;
    std::cout << "Choose type of sort:\n";
    std::cout << "1 - ascending\n";
    std::cout << "0 - descending\n";
    std::cin >> sort;
    return sort;
}
void ChouseTypeOfSort(int32_t& typeOfSort)
{
    std::cout << "input type of sort:\n";
    std::cout << "1 - bubblesort;\n";
    std::cout << "2 - combsort;\n";
    std::cout << "3 - insertionsort;\n";
    std::cout << "4 - selectionsort;\n";
    std::cout << "5 - quicksort;\n";
    std::cout << "6 - mergesort;\n";
    std::cout << "7 - cocktailsort;\n";
    //std::cout << "8 - countsort;\n";
    //std::cout << "9 - bogosort\n";
    std::cin >> typeOfSort;
}

void ChouseType(char type)
{
    switch (type)
    {
    case '1':
    {
        int32_t* arr = nullptr;
        int32_t choice{};
        InputChoice(choice);
        ChouseInputAndOutput(choice, arr);
        break;
    }
    case '2':
    {
        double* arr = nullptr;
        int32_t choice{};
        InputChoice(choice);
        ChouseInputAndOutput(choice, arr);
        break;
    }
    case '3':
    {
        char* arr = nullptr;
        int32_t choice{};
        InputChoice(choice);
        ChouseInputAndOutput(choice, arr);
        break;
    }
    case '4':
    {
        std::string* arr = nullptr;
        int32_t choice{};
        InputChoice(choice);
        ChouseInputAndOutput(choice, arr);
        break;
    }
    case '5':
    {
        Student* arr = nullptr;
        int32_t choice{};
        InputChoice(choice);
        ChouseInputAndOutput(choice, arr);
        break;
    }
    default:
    {
        throw std::invalid_argument("false type of data\n");
        break;
    }
    }
}

void InputFromConsole(Student* arr, int32_t size) {
    for (int32_t i{}; i < size; ++i)
    {
        std::cout << "student" << i + 1 << "\ncourse: ";
        std::cin >> arr[i].course;
        std::cout << "group: ";
        std::cin >> arr[i].group;
        std::cin.ignore();
        std::cout << "full name: ";
        std::getline(std::cin, arr[i].name);
        std::cout << "grades (3): ";
        for (int32_t j{}; j < 3; ++j)
        {
            std::cin >> arr[i].grades[j];
        }
    }
}

void ReadFromFile(std::string& filename, Student* arr, int32_t size) {
    std::ifstream fin(filename);
    CheckInputFile(fin);
    for (int32_t i{}; i < size; ++i)
    {
        fin >> arr[i].course >> arr[i].group;
        fin.ignore();
        std::getline(fin, arr[i].name);
        for (int32_t j{}; j < 3; ++j)
        {
            fin >> arr[i].grades[j];
        }
    }
    fin.close();
}
void WriteToFile(std::string& filename, Student* arr, int32_t size)
{
    std::ofstream fout(filename);
    CheckOutputFile(fout);
    for (int32_t i{}; i < size; ++i)
    {
        fout << arr[i].course << " " << arr[i].group << " " << arr[i].name << " ";
        for (int32_t j{}; j < 3; ++j)
        {
            fout << arr[i].grades[j] << " ";
        }
        fout << "\n";
    }
    fout.close();
}

void GenerateRandom(int32_t* arr, int32_t size) {
    int32_t firstElement{};
    int32_t lastElement{};
    InputInterval(firstElement, lastElement);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t>dist(firstElement, lastElement);
    for (int32_t i{}; i < size; ++i)
    {
        arr[i] = dist(gen);
    }
}
void GenerateRandom(double* arr, int32_t size) {
    double firstElement{};
    double lastElement{};
    InputInterval(firstElement, lastElement);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double>dist(firstElement, lastElement);
    for (int32_t i{}; i < size; ++i)
    {
        arr[i] = dist(gen);
    }
}
void GenerateRandom(char* arr, int32_t size) {
    char firstElement{};
    char lastElement{};
    InputInterval(firstElement, lastElement);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> dist(static_cast<int>(firstElement), static_cast<int>(lastElement));
    for (int32_t i{}; i < size; ++i)
    {
        arr[i] = static_cast<char>(dist(gen));
    }
}
void GenerateRandom(std::string* arr, int32_t size) {
    for (int32_t i{}; i < size; ++i) {
        arr[i] = GenerateRandomStr();
    }
}
std::string GenerateRandomStr() {
    std::cout << "extreme values of length\n";
    int32_t firstElement{};
    int32_t lastElement{};
    InputInterval(firstElement, lastElement);
    std::cout << "extreme values of letters\n";
    char firstLetter{};
    char lastLetter{};
    InputInterval(firstLetter, lastLetter);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> dist(firstElement, lastElement);
    std::uniform_int_distribution<int32_t> char_dist(static_cast<int>(firstLetter), static_cast<int>(lastLetter));
    int32_t size{ dist(gen) };
    std::string word;
    word.reserve(size);
    for (int32_t i{}; i < size; ++i) {
        word += static_cast<char>(char_dist(gen));
    }
    return word;
}
void GenerateRandom(Student* arr, int32_t size) {
    int32_t firstElement{};
    int32_t lastElement{};
    std::cout << "extreme values of course, group and grades\n";
    InputInterval(firstElement, lastElement);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int32_t> dist(firstElement, lastElement);
    for (int32_t i{}; i < size; ++i)
    {
        std::cout << "student " << i + 1 << ":\n";
        arr[i].name = GenerateRandomStr();
        arr[i].course = dist(gen);
        arr[i].group = dist(gen);
        for (int32_t j{}; j < 3; ++j)
        {
            arr[i].grades[j] = dist(gen);
        }
    }
}


std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << student.course << " " << student.group << " " << student.name;
    for (int32_t i = 0; i < 3; ++i) {
        out << " " << student.grades[i];
    }
    return out;
}

