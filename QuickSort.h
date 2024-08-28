#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "Sort.h"

class QuickSort : public Sort {
public: 
    std::vector <int> sort (std::vector<int> list);

private: 
    void quicksort (std::vector <int>& list);
    int partition(std::vector<int>& list ,int low, int high);
};
#endif