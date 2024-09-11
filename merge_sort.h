#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include "Sort.h"

class Merge_Sort : public Sort {
private:
    std::vector<int> merge_sort (std::vector <int> list, int start, int end);
    std::vector<int> merge (std::vector <int>& list1, std::vector <int> &list2);
public: 
    std::vector <int> sort (std::vector<int> list);
};
#endif