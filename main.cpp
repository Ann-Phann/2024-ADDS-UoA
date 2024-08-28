#include <iostream>
#include "BubbleSort.h"

int main () {
    std::vector <int> list = {1,2,3,4,5};
    BubbleSort bubble;
    std::vector <int> sorted_list = bubble.sort(list);
    std::cout << "sorted: ";
    for (int i = 0; i < sorted_list.size(); i++)
    {
        std::cout << sorted_list[i] << " ";
    }
    std::cout << std::endl;

}