//use of array ADT
#include <array>
#include <iostream>
int main()
{
    std::array<int,10> myarray;

    //assign values
    for (int i = 0; i < 10; i++) 
        myarray.at(i) = i+1;

    //print content
    for (int i = 0; i < 10; i++)
        std::cout <<' '<< myarray.at(i);
    std::cout << std::endl;

    //traverse the array by different ways
    for (auto it = myarray.begin(); it != myarray.end(); ++it)
    {
        std::cout << ' ' << *it;
    }

    for(auto &it : myarray) //& is used so that if we change the value of it, it will change the value of array element
    {
        std::cout << ' ' << it;
    }

    return 0;
}