//recursive function to calculate power( int a, int b), the result would be a^b 

#include <cmath>
#include <iostream>

int power (int a, int b) 
{
    //base case
    if (b == 0) 
    {
        return 1;
    }

    if (b == 1) 
    {
        return a;
    }
    return a * power(a, b -1);
}

int power_tail (int a, int b, int result = 1)
{
    if (b == 0) 
    {
        return result;
    }

    if (b == 1)
    {
        return a * result;
    }
    return power_tail(a, b - 1, result*a);
}

int main() 
{
    int a = 2;
    int b = 3;
    std::cout << power(a, b) << std::endl;
    std::cout << power_tail(a, b) << std::endl;
    return 0;
}