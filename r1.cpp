#include <iostream>
#include <cmath>

int sum_of_powers(int n) {
    if (n < 1) {
        return 0;
    } else {
        return pow(n, n) + sum_of_powers(n-1);
    }
}

