#ifndef BAGOFHOLDING_H
#define BAGOFHOLDING_H
#include <vector>
#include <iostream>

template <class T>

class BagOfHolding {
    private:
    std::vector<T> items;
    public:
    void addItem(T item);
    T removeItem(T item);
    T removeItem();
};

#endif