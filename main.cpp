#include <iostream>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
int main () {
    std::vector <int> list = {1,2,3,4,5};
    // BubbleSort bubble;
    // std::vector <int> sorted_list = bubble.sort(list);
    // std::cout << "sorted: ";
    // for (int i = 0; i < sorted_list.size(); i++)
    // {
    //     std::cout << sorted_list[i] << " ";
    // }
    // std::cout << std::endl;

    QuickSort quick;
    std::vector <int> sorted_list = quick.sort(list);
    for (int i = 0; i < sorted_list.size(); i++)
    {
        std::cout << sorted_list[i] << " ";
    }
    std::cout << std::endl;
    
    RecursiveBinarySearch recursivesearch;
    if (recursivesearch.search(sorted_list, 8)) {
        std::cout << "True" << std::endl;
    } else {
        std::cout << "False" <<std::endl;
    }
}