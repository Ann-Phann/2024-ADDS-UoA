#include "quick_sort.h"
#include <iostream>

std::vector <int> Quick_Sort:: sort(std::vector <int> list) {
    if (list.size() < 2) {
        return list;
    } else if (list.size() == 2) {
        if(list[0] > list[1]) {
            std::swap(list[0], list[1]);
        }
        return list;

    }
    
    int start = 0;
    int end = list.size() - 1;
    quick_sort(list, start, end);
    return list;
}

int Quick_Sort:: partition(std::vector<int>& list, int start, int end) {
    int pivotIndex = end;
    int pivotSwap = start;

    for (int i = start; i < end; i++) {
        if (list[pivotIndex] > list[i]) {
            std::swap(list[pivotSwap], list[i]);
            pivotSwap++;
        }
    }
    std::swap(list[pivotIndex], list[pivotSwap]);
    return pivotSwap;

}

void Quick_Sort::quick_sort (std::vector <int>& list, int start, int end) {
    if (start >= end) {
        return;
    }

    int part = partition(list, start, end);
    quick_sort(list, start, part - 1);
    quick_sort(list, part + 1, end);
}