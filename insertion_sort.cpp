#include "insertion_sort.h"

std::vector <int> Insertion_Sort:: sort (std::vector<int> list) {
    int size =list.size();
    for (int i = 1; i < size; i++){
        int key = list[i]; // the key shoud be sorted
        int j;

        //find the correct position for the key
        for (j = i-1; j >= 0 && list[j] > key; j--) {
            list[j+1] = list[j];
        }
        //put the key at its correct position
        list[j+1] = key;
    }
    return list;
}