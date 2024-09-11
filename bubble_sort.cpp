#include "bubble_sort.h"
std::vector <int> Bubble_Sort:: sort (std::vector<int> list){
    int size = list.size();
    int swap = 0;
    for(int i = 0; i < size -1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (list[j] > list[j+1]) {
                std::swap(list[j], list[j+1]);
                swap++;
            }
        }
        if (swap == 0) {
            break;
        }
    }
    return list;
}