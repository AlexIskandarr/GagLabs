#include <iostream>
#include <cstring>
#include <cstdint>

using namespace std;

bool isPalindrome(const char*);
int32_t extractPalindromes(char* , const char* , char**, int32_t*);
int32_t findMaxLength(const int32_t* , int32_t );
void printLongestPalindromes(char**, const int32_t*, int32_t, int32_t);
void freeMemory(char**, int32_t);

int main() {
    char input[300], delimiters[300];
    cout << "Enter string: ";
    cin.getline(input, 300);
    cout << "Enter delimiters: ";
    cin.getline(delimiters, 300);

    char buffer[301];
    strcpy(buffer, input);

    char* palindromes[300];
    int32_t lengths[300];
    int32_t count = extractPalindromes(buffer, delimiters, palindromes, lengths);

    if (count == 0) {
        cout << "No palindromes found!\n";
        return 0;
    }

    int32_t max_length = findMaxLength(lengths, count);
    
    printLongestPalindromes(palindromes, lengths, count, max_length);
     
    freeMemory(palindromes, count);

    return 0;
}

int32_t findMaxLength(const int32_t* lengths, int32_t count) {
    int32_t max_length = lengths[0];
    for (int32_t i = 1; i < count; ++i) {
        if (lengths[i] > max_length) {
            max_length = lengths[i];
        }
    }
    return max_length;
}


void printLongestPalindromes(char** palindromes, const int32_t* lengths, int32_t count, int32_t max_length) {
    cout << "Longest palindromes: ";
    for (int32_t i = 0; i < count; ++i) {
        if (lengths[i] == max_length) {
            cout << palindromes[i] << " ";
        }
    }
    cout << endl;
}

void freeMemory(char** palindromes, int32_t count) {
    for (int32_t i = 0; i < count; ++i) {
        delete[] palindromes[i];
    }
}

bool isPalindrome(const char* word) {
    int32_t len = static_cast<int32_t>(strlen(word));
    for (int32_t i = 0; i < len / 2; ++i) {
        if (word[i] != word[len - 1 - i]) return false;
    }
    return true;
}

int32_t extractPalindromes(char* buffer, const char* delimiters, char** palindromes, int32_t* lengths) {
    int32_t count = 0;
    char* token = strtok(buffer, delimiters);
    while (token != nullptr) {
        if (isPalindrome(token)) {
            palindromes[count] = new char[strlen(token) + 1];
            strcpy(palindromes[count], token);
            lengths[count] = static_cast<int32_t>(strlen(token));
            count++;
        }
        token = strtok(nullptr, delimiters);
    }
    return count;
}