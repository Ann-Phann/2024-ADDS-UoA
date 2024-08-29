#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch:: search(std::vector<int> list, int target)
{
    int start = 0;
    int end = list.size() - 1;
    bool result = recursivebinary(list, target, start, end);
    return result;
}

bool RecursiveBinarySearch::recursivebinary(std::vector <int> list,  int target, int start, int end) {
    if (start > end) {
        return false;
    }
    //calculate the target of the list/sublist
    int midpoint = (start + end)/2;

    if (list[midpoint] == target) {
        return true;
    }
    //searching in right hand side
    else if(list[midpoint] < target) {
        return recursivebinary(list, target, midpoint+1, end);
    }
    else {
        return recursivebinary(list, target,start, midpoint-1);
    }
    
}