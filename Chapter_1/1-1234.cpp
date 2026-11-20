#include <iostream>
#include <format>
#include <vector>

// 1) Modify the Employee structure from the beginning of this chapter by putting it in a namespace called HR.
// Additionally, modify the code to use C++20 designated initializers.
// При создании обьекта используя С++20 инишалайзерс ты сразу даешь ему значения, а не присваиваешь после создания.

// 2) Add an enumeration data member title to Employee to specify whether a certain employee is a Manager, Senior Engineer, or Engineer.
// Whatever you need to add, add it to the HR namespace.
// Test your new Employee data member in the main() function. Use a switch statement to print out a human-readable string for the title.

// 3) Use an std::array to store three Employee instances from Exercise 1-2 with different data. 
// Subsequently, use a range-based for loop to print out the employees in the array.

// 4) Use an std::vector instead of an array, and use push_back() to insert elements into the vector.

namespace HR
{
    enum class Position { Manager, SeniorEngineer, Engineer };

    struct Employee
    {
        char firstInitial;
        char lastInitial;
        int employeeNumber;
        int salary {75'000};
        Position role;
    };
}

void displayRole (HR::Position role);

template <size_t N>
void displayArray (const std::array<HR::Employee, N>& arr);

void displayVector (const std::vector<HR::Employee>& vect);

int main()
{
    HR::Employee anEmployee {
        .firstInitial = 'J',
        .lastInitial = 'D',
        .employeeNumber = 42,
        .role = HR::Position::Engineer
    };

    HR::Employee Boss {
        .firstInitial = 'C',
        .lastInitial = 'H',
        .employeeNumber = 67,
        .salary = 90'000,
        .role = HR::Position::Manager
    };

    HR::Employee Senior {
        .firstInitial = 'R',
        .lastInitial = 'K',
        .employeeNumber = 33,
        .salary = 80'000,
        .role = HR::Position::SeniorEngineer
    };

    std::array<HR::Employee, 3> workersArr { anEmployee, Boss, Senior };
    displayArray (workersArr);

    std::vector<HR::Employee> workersVect { Senior };
    workersVect.push_back(Boss);
    workersVect.push_back(anEmployee);

    displayVector (workersVect);

    return 0;
}

void displayRole (HR::Position role) {

    std::cout << "Position: ";

    switch (role) {

        case HR::Position::Manager:
            std::cout << "Manager\n";
            break;
        
        case HR::Position::SeniorEngineer:
            std::cout << "Senior Engineer\n";
            break;

        case HR::Position::Engineer:
            std::cout << "Engineer\n";
            break;

        default:
            std::cout << "Error: uknown role!\n";
            break;
    }
}

// можно написать функцию вывода одного работника и скопировать ее в функцию для таблицы и вектора отдельно

template <size_t N>
void displayArray (const std::array<HR::Employee, N>& arr) {

    std::cout << "---------------------------------------" << std::endl;

    for (const HR::Employee& employee : arr) {

        std::cout << std::format("Employee: {}{}", employee.firstInitial, employee.lastInitial) << std::endl;
        std::cout << std::format("Number: {}", employee.employeeNumber) << std::endl;
        std::cout << std::format("Salary: ${}", employee.salary) << std::endl;
        displayRole(employee.role);
        std::cout << "---------------------------------------" << std::endl;
    }
}

void displayVector (const std::vector<HR::Employee>& vect) {

    std::cout << "---------------------------------------" << std::endl;

    for (const HR::Employee& employee : vect) {

        std::cout << std::format("Employee: {}{}", employee.firstInitial, employee.lastInitial) << std::endl;
        std::cout << std::format("Number: {}", employee.employeeNumber) << std::endl;
        std::cout << std::format("Salary: ${}", employee.salary) << std::endl;
        displayRole(employee.role);
        std::cout << "---------------------------------------" << std::endl;
    }
}