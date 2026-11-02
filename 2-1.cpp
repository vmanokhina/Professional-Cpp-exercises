#include <iostream>
#include <string>

// a program that asks the user for two strings and then prints them out in alphabetical order, using the three-way comparison operator

void printAlphabetical(const std::string& s1, const std::string& s2);

int main() {

    std::string s1, s2;

    std::cout << "Enter the first line:\n";
    std::getline(std::cin, s1);
    std::cout << "Enter the second line:\n";
    std::getline(std::cin, s2);

    printAlphabetical(s1, s2);

    return 0;
}

void printAlphabetical(const std::string& s1, const std::string& s2) {

    auto alph = s1 <=> s2;

    if (alph < 0) {                 // то есть строка 1 меньше строки 2 (потому что буквы которые дальше по алфавиту - больше)
        std::cout << s1 << "\n";
        std::cout << s2 << "\n";
    } else if (alph > 0) {          
        std::cout << s2 << "\n";
        std::cout << s1 << "\n";
    } else {
        std::cout << s1 << "\n";
        std::cout << s2 << "\n";
    }
}