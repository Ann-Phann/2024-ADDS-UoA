#include <iostream>
#include "Heap.tpp"

int main() {
    // Explicitly declare heap type
    Heap<int> heap;

    // Insert elements
    heap.insert(3);
    heap.insert(2);
    heap.insert(15);
    heap.insert(5);
    heap.insert(4);

    // Print heap elements
    std::cout << "Heap elements: ";
    heap.printHeap();

    return 0;
}
