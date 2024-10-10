#include <vector>
#include <queue>

int kth_largest(std::vector<int> values, int k) {
    std::priority_queue <int, std::vector<int>, std::greater<int>> min_heap;

    for (auto element : values) {
        min_heap.push(element);

        //only store top k largest elements
        if (min_heap.size() > k) {
            min_heap.pop();  //remove the smallest number in the vector
        }
    }
    return min_heap.top();
}