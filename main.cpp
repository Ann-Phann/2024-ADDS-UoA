// #include <iostream>
// #include "BubbleSort.h"
// #include "QuickSort.h"
// #include "RecursiveBinarySearch.h"
// int main () {
//     std::vector <int> list = {1,2,3,4,5};
//     // BubbleSort bubble;
//     // std::vector <int> sorted_list = bubble.sort(list);
//     // std::cout << "sorted: ";
//     // for (int i = 0; i < sorted_list.size(); i++)
//     // {
//     //     std::cout << sorted_list[i] << " ";
//     // }
//     // std::cout << std::endl;

//     QuickSort quick;
//     std::vector <int> sorted_list = quick.sort(list);
//     for (int i = 0; i < sorted_list.size(); i++)
//     {
//         std::cout << sorted_list[i] << " ";
//     }
//     std::cout << std::endl;

//     RecursiveBinarySearch recursivesearch;
//     if (recursivesearch.search(sorted_list, 8)) {
//         std::cout << "True" << std::endl;
//     } else {
//         std::cout << "False" <<std::endl;
//     }
// }
#include <iostream>
#include <sstream>
#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main() {
    // Input: one line of integers separated by space
    std::string input;
    std::getline(std::cin, input);

    // Convert input string to vector of integers using std::istringstream
    std::istringstream iss(input);
    std::vector<int> list;
    int num;
    while (iss >> num) {
        list.push_back(num);
    }

    // Sort the list using QuickSort
    QuickSort sorter;
    list = sorter.sort(list);

    // Check if '1' is in the list using RecursiveBinarySearch
    RecursiveBinarySearch searcher;
    bool found = searcher.search(list, 1);

    // Output result
    std::cout << (found ? "true" : "false");
    for (int n : list) {
        std::cout << " " << n;
    }
    std::cout << std::endl;

    return 0;
}
