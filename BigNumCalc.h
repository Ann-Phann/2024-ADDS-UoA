#ifndef BIGNUMCALC_H
#define BIGNUMCALC_H

#include <list>
#include <iostream>
#include <string>

class BigNumCalc {
public:
    BigNumCalc();
    ~BigNumCalc();

    //A method that creates a list representing the provided string. For example, a string "12345" would become a list with elements 1,2,3,4, and 5 respectively.
    std::list<int> buildBigNum(std::string numString);

    //method to add num1 to num2 and return the sum.
    std::list<int> add(std::list<int> num1, std::list<int> num2);

    //method to subtract num2 from num1 and return the difference.
    std::list<int> sub(std::list<int> num1, std::list<int> num2);

    //method to multiply num1 by num2 and return the product. For simplicity, you can assume num2 will be only 1 digit long.
    std::list<int> mul(std::list<int> num1, std::list<int> num2);
};
#endif // BIGNUMCALC_H