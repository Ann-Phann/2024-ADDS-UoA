#include "selection_sort.h"
#include "bubble_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#include <iostream>
int main () {
    Sort* sort_algo = new Quick_Sort();
    std::vector <int> number = {2,5,1,7,4};
    std::vector<int> sorted_list = sort_algo->sort(number);

    for (int i = 0; i < number.size(); i++) {
        std::cout << sorted_list[i] << " " ;
    }
    std::cout << std::endl;
}