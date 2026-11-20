#include <iostream>
#include <vector>
#include <format>

int main() {

    std::vector<float> numbers;
    float number;

    std::cout << "Enter floating-point numbers (enter 0 to stop)\n";

    while (std::cin >> number) {

        if (number == 0) {
            break;
        }

        numbers.push_back(number);
    }

    for (auto i : numbers) {
        std::cout << std::format("|{:<10}| ", i);
        std::cout << std::format("|{:>10}| ", i);
        std::cout << std::format("|{:_^10}|\n", i);
    }

    return 0;
}