#include "BigNumCalc.h"

BigNumCalc::BigNumCalc(){}
BigNumCalc::~BigNumCalc(){}

//A method that creates a list representing the provided string. For example, a string "12345" would become a list with elements 1,2,3,4, and 5 respectively.
std::list<int> BigNumCalc:: buildBigNum(std::string numString){
    
    std::list<int> number;

    for(char c : numString) {
        int numberInterger = std::stoi(std::string(1,c));
        number.push_back(numberInterger);
    }
    return number;
}

// //method to add num1 to num2 and return the sum.
// std::list<int> BigNumCalc:: add(std::list<int> num1, std::list<int> num2){

// }

// //method to subtract num2 from num1 and return the difference.
// std::list<int> BigNumCalc:: sub(std::list<int> num1, std::list<int> num2){}

// //method to multiply num1 by num2 and return the product. For simplicity, you can assume num2 will be only 1 digit long.
// std::list<int> BigNumCalc:: mul(std::list<int> num1, std::list<int> num2){}