#include <iostream>
#include <string>

// Write a program that asks the user for a source string (= haystack), a string to find (= needle) in the source string, and a replacement string. 
// Write a function with three parameters - the haystack, needle, and replacement string - that returns a copy of the haystack 
// with all needles replaced with the replacement string. Use only std::string, no string_view. 

const std::string replaceAll(const std::string& text, const std::string& searched, const std::string& replacement);

int main() {

    std::string text, searched, replacement;
    std::getline(std::cin, text);
    std::getline(std::cin, searched);
    std::getline(std::cin, replacement);

    std::cout << replaceAll(text, searched, replacement) << "\n";

    return 0;
}

const std::string replaceAll(const std::string& text, const std::string& searched, const std::string& replacement) {
    std::string result = text; // copy of text
    size_t pos = result.find(searched); // position

    while (pos != std::string::npos) {
        result.replace(pos, searched.length(), replacement); // (skąd zaczynamy, ile liter usunąć, na co zamienić)

        pos = result.find(searched, pos + replacement.length()); 
    }

    return result;
}