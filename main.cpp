#include "iostream"
#include "Truckloads.h"
#include "Reverser.h"
int main()
{
    Truckloads Truckloads;
    std::cout << Truckloads.numTrucks(10, 3) <<std::endl;

    Reverser reverse;
    std::cout << reverse.reverseDigit(-1) << std::endl;
    std::cout << reverse.reverseString("hello") << std::endl;
    return 0;

}