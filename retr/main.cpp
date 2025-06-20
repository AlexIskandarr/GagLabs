#include <iostream>
#include <cstring>
#include <cstdint>

bool IsPolindrome(const char*);
int32_t FindPolindromes(char*, const char*, char**, int32_t*);
int32_t FindMaxLength(const int32_t*, int32_t);
void PrintLongetsPolindromes(char**, const int32_t*, int32_t, int32_t);
void FreeMemory(char**, int32_t);

int main(){
    char input[300];
    std::cout << "enter u text: \n";
    std::cin.getline(input, 300);
    char delimetrs[300];
    std::cout << "enter delimetrs: \n";
    std::cin.getline(delimetrs, 300);

    char buffer[301];
    strcpy(buffer, input);

    char* polindromes[300];
    int32_t length[300] {};
    int32_t count {FindPolindromes(buffer, delimetrs, polindromes, length)};

    int32_t max_length {FindMaxLength(length, count)};

    PrintLongetsPolindromes(polindromes, length, max_length, count);
    FreeMemory(polindromes, count);
    return 0;
}

bool IsPolindrome(const char* word){
    int32_t len = strlen(word);
    for(int32_t i{}; i < len / 2; ++i){
        if(word[i] != word[len - i - 1]){
            return false;
        }
    }
    return true;
}

int32_t FindPolindromes(char* buffer, const char* delimetrs, char** polindromes, int32_t* length){
    int32_t count{};
    char* token = strtok(buffer, delimetrs);
    while (token != nullptr){
        if(IsPolindrome(token)){
            polindromes[count] = new char[strlen(token) + 1];
            strcpy(polindromes[count], token);
            length[count] = strlen(token);
            ++count;
        }
        token = strtok(nullptr, delimetrs);
    }
    return count;
}

int32_t FindMaxLength(const int32_t* length, int32_t count){
    int32_t max {length[0]};
    for (int32_t i{1}; i < count; ++i){
        if(length[i] > max){
            max = length[i];
        }
    }
    return max;
}

void PrintLongetsPolindromes(char** polindromes, const int32_t* length, int32_t max_length, int32_t count){
    std::cout << "The longest polindrome is: \t";
    for(int32_t i{}; i < count; ++i){
        if(length[i] == max_length){
            std::cout << polindromes[i] << ';'; 
        }
    }
}

void FreeMemory(char** polindomes, int32_t count){
    for(int32_t i{}; i < count; ++i){
        delete[] polindomes[i];
    }
}