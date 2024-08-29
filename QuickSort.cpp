#include "QuickSort.h"

std::vector <int> QuickSort::sort (std::vector<int> list) {
    if (list.size() < 2) {
        return list;
    } else if (list.size() == 2) {
        if (list[0] > list[1]) {
            std::swap(list[0], list[1]);
        }    
        return list;
    }
    int start = 0;
    int end = list.size() - 1;
    quicksort(list, start, end);
    return list;
}

void QuickSort::quicksort (std::vector <int>& list, int start, int end) {
    if (start < end) {
        int p = partition(list, start, end);
        quicksort(list, start, p -1);
        quicksort(list, p + 1, end);
    }
}

//use to get all the number less than the pivot on the left hand side, and all the larger on the right hand side
int QuickSort::partition(std::vector<int>& list ,int start, int end) {

    //get pivot
    int pivot = list[start + 2];

    //move pivot to the end of list by swapping index 
    std::swap(pivot, end);
    int pivotIndex = start;
    
    //partition the list around the pivot
    for (int i = 0; i < end; i++) {
        if (list[i] < pivot){
            std::swap(list[i], list[pivotIndex]);
            pivotIndex++;
        }
    }

    //put the pivot into right position
    std::swap(pivot, list[pivotIndex]);
    return pivotIndex;
}