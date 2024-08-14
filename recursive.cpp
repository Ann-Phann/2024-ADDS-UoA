#include <iostream>
#include <cmath>
int sum_square(int n) {
    if (n == 0) 
        return 0;

    return sum_square(n - 1) + pow(n, 2);
}

int recursive_func(int n) {
    if (n == 0) 
        return 0;
    if (n == 1) 
        return 1;

    return recursive_func(n - 1) * recursive_func(n - 2);
}

void print_numbers(int n) {
    if (n == 0) {
        return;
    }

    std::cout << n << " ";
    print_numbers(n - 1);
}

int another_sum_square(int n, int acc = 0) {
    if (n == 0) 
        return acc;

    return another_sum_square(n - 1, acc + pow(n, 2));
}
int reverseDigit(int number, int result = 0) {
    // Error handling
    if (number < 0) {
        return -1;
    }

    // Base case: just have one digit
    if (number < 10) {
        return result * 10 + number;
    }

    int numLastDigit = number % 10;
    int remainDigit = number / 10;

    // Update result by shifting the previous result by one digit and adding the last digit
    result = result * 10 + numLastDigit;

    return reverseDigit(remainDigit, result);
}

int main() {
    std::cout << sum_square(5) << std::endl;
    std::cout << recursive_func(3) << std::endl;
    print_numbers(5);
    std::cout << std::endl;

    std::cout << another_sum_square(5) << std::endl;

    std::cout << reverseDigit(1) << std::endl;
    std::cout << reverseDigit(1234) << std::endl;
}