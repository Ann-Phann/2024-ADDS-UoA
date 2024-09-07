#include "BigNumCalc.h"
int main (void) {
    //test buildBigNum
    BigNumCalc calc;
    std::string input = "12345";

    // Build big number from string
    std::list<int> bigNum = calc.buildBigNum(input);

    // Output the list elements to verify
    std::cout << "List representation of the number " << input << ": ";
    for (std::list<int>::iterator it = bigNum.begin(); it != bigNum.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}