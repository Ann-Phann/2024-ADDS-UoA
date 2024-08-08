#include "Reverser.h"
#include <iostream>
#include <string>
#include <cmath>
int Reverser::reverseDigit(int number)
{
    if(number < 0)
    {
        return -1;
    }
    int result = 0;
    //just have one digit
    if (number < 10)
    {
        return number;
    }  
    int numLastDigit = number % 10;
    int remainDigit = number / 10;
    
    int size = std::to_string(number).size();

    result = result + numLastDigit * pow(10, size-1) ;
    result = result + reverseDigit(remainDigit);
    //std::cout << "result: "<< result << std::endl;
    return result;
   
}

std::string Reverser:: reverseString(std::string str)
{
    std::string result="";
    if(str.size() == 1)
    {
        return str;
    }
    //std::string last = str.substr(str.size()-1);
    int last_pos = str.size()-1;
    char last = str[last_pos];

    //std::cout << result + last << std::endl;
    return result + last + reverseString(str.substr(0, str.size()-1));
}