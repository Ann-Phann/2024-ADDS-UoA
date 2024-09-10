#include "LinkedList.h"
#include <iostream>
#include "BigNumCalc.h"

// Function to print a list of integers
void printList(const std::list<int>& lst) {
    for (int digit : lst) {
        std::cout << digit;
    }
    std::cout << std::endl;
}

int main() {
    // Create the BigNumCalc object
    BigNumCalc calc;

    // Define the numbers to multiply
    std::list<int> num1 = {2,3,4,5,6}; // Represents the number 23
    std::list<int> num2 = {5};    // Represents the number 5

    // Perform multiplication
    std::list<int> result = calc.mul(num1, num2);

    // Print the result
    std::cout << "Result: ";
    printList(result);

    return 0;
}