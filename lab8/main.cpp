#include "functions.h" 

int main() {
    double* array = nullptr;
    int32_t size {};
    std::string filename;
    char sourceChoice, outputChoice;

    try {
      
        std::cout << "Data source? (f - file, k - keyboard): ";
        std::cin >> sourceChoice;

        if (sourceChoice == 'f') {
           
            std::cout << "Enter filename: ";
            std::cin >> filename;
            
            std::ifstream fin(filename);
            CheckInputFIle(fin);
            
            size = NumberOfNumbersInFile(fin);
            fillArrayFromFile(fin, array, size);
            fin.close();
        } 
        else if (sourceChoice == 'k') {
        
            std::cout << "Enter array size: ";
            std::cin >> size;
            if (size <= 0) throw std::invalid_argument("Invalid size");
            
            array = new double[size];
            FillArray(array, size);
        } 
        else {
            throw std::invalid_argument("Invalid choice");
        }

        std::cout << "\nOriginal array:\n";
        PrintArray(array, size);

        sortArray(array, size);

        std::cout << "\nOutput destination? (f - file, s - screen): ";
        std::cin >> outputChoice;

        if (outputChoice == 'f') {
            std::cout << "Enter output filename: ";
            std::cin >> filename;
            
            std::ofstream fout(filename);
            CheckOutputFile(fout);
            FillFileFromArray(fout, array, size);
            fout.close();
            std::cout << "Data saved to " << filename << "\n";
        } 
        else if (outputChoice == 's') {
            std::cout << "\nSorted array:\n";
            PrintArray(array, size);
            std::cout << "\n";
        } 
        else {
            throw std::invalid_argument("Invalid output choice");
        }

        delete[] array;
    } 
    catch (const char* e) {
        std::cerr << "Error: " << e << "\n";
        delete[] array;
        return 1;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        delete[] array;
        return 1;
    }

    int32_t qntStudent{};
	std::cout << "input quantity of students: \n";
	std::cin >> qntStudent;

	Student* students = new Student[qntStudent];
	InputInfoStudents(students, qntStudent);

	double* averageMarks = new double[qntStudent];
	for (size_t i = 0; i < qntStudent; ++i) {
		averageMarks[i] = AverageMark(students[i]);
	}

	BubleSortForStudents(students, averageMarks, qntStudent);
	PrintStudents(students, qntStudent, averageMarks);

	delete[] students;
	delete[] averageMarks;

    return 0;
}

   
