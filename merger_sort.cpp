#include "merge_sort.h"
#include <iostream>

std::vector <int> Merge_Sort::sort (std::vector <int> list) {
    if (list.size() <= 1) {
        return list;
    }
    //call merge sort
    return merge_sort(list, 0, list.size()-1);
}

std::vector<int> Merge_Sort:: merge_sort (std::vector <int> list, int start, int end){
    if (start >= end || list.size() == 1) {
        return list;
    }

    int middle = (start + end)/2;

    //create sublists for the left and right halves
    std::vector<int> left(list.begin() + start, list.begin() + middle + 1);
    std::vector<int> right(list.begin() + middle + 1, list.begin() + end + 1);

    // Recursively sort the left and right halves
    left = merge_sort(left, 0, left.size() - 1);
    right = merge_sort(right, 0, right.size() - 1);


    //merge the sorted left and right
    return merge(left, right);
}

std::vector<int> Merge_Sort:: merge (std::vector <int>& list_left, std::vector <int> &list_right) {
    std::vector <int> result;

    int pointer_left = 0, pointer_right = 0;
    
    while (pointer_left < list_left.size() && pointer_right < list_right.size()) {
        //if left < right
        if (list_left[pointer_left] < list_right[pointer_right]) {
            result.push_back(list_left[pointer_left]);
            pointer_left++;
        } else {
            //if right < left
            result.push_back(list_right[pointer_right]);
            pointer_right++;
        }
    }

    //put the rest digit into the list
    //if left still have element
    while (pointer_left < list_left.size()) {
        result.push_back(list_left[pointer_left]);
        pointer_left++;
    }
    while (pointer_right < list_right.size()) {
        result.push_back(list_right[pointer_right]); 
        pointer_right++;
    }
    return result;
}