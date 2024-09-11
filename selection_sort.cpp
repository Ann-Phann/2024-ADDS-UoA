#include "selection_sort.h"
#include <iostream>

std::vector <int> Selection_Sort:: sort (std::vector<int> list) {
    int size = list.size();
    int minIndex;
    for (int i = 0; i < size; i++) {
        minIndex = i;
        for (int j = i+1; j < size; j++) {
            if(list[minIndex] > list[j]) {
                minIndex = j;
            }
        }
        std::swap(list[minIndex], list[i]);
    }
    return list;
}