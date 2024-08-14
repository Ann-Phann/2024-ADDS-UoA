#include <iostream>

int reverseDigit (int number) {
    int result = 0;
    if (number < 0) {
        return -1;
    }

    if (number < 10) {
        return number;
    }

    int lastDigit = number % 10;
    int remainDigit = number / 10;

    result = result * 10 + lastDigit;
    return reverseDigit(remainDigit) * 10 + lastDigit;
}

int main () {
    std::cout << reverseDigit(123) << std::endl;
    return 0;
}