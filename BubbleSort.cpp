#include "BubbleSort.h"
#include <iostream>
std::vector <int> BubbleSort:: sort (std::vector<int> list) {
    int i, j;
    int size = list.size();
    for (i = 0; i < size; i++) {
        int swap = 0;
        for (j = 0; j < size-i-1; j++) {
            if (list[j] > list [j+1]) {
                std::swap(list[j], list[j+1]);
                swap++;
            }
        }
        //early break if everything sorted
        if (swap == 0) {
            //std::cout<< "no swap";
            break;
        }
    }

    return list;
}
