
#ifndef QUICK_SORT_H
#define QUICK_SORT_H

#include "Sort.h"
class Quick_Sort : public Sort {
private:
    int partition(std::vector<int>& list, int start, int end);
    void quick_sort (std::vector <int>& list, int start, int end);
public:
    std::vector <int> sort (std::vector<int> list);
};
#endif