#include <cmath>
#include <iostream>

//recursive function to calculate sum of power of n (n^n + (n-1)^(n-1) + ... + 1^1)
int sum_of_powers(int n) {
    if (n < 1) {
        return 0;
    }
    return pow(n,n) + sum_of_powers(n-1);
}

int tail_sum_of_powers(int n, int result = 0) {
    if (n < 1) {
        return result;
    }

    return tail_sum_of_powers(n-1, result + pow(n,n));
}

int main() {
    int n = 3;
    std::cout << sum_of_powers(n) << std::endl;
    std::cout << tail_sum_of_powers(n) << std::endl;
    return 0;
}