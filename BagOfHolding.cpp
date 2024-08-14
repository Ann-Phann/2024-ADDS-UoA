#include "BagOfHolding.h"
#include <iostream>
#include <vector>

template<class T> void BagOfHolding<T>::addItem(T item) {
    items.push_back(T item)
}

template<class T> T BagOfHolding<T>::removeItem(T item) {
    auto search = std::find(items.begin(), items.end(), items);
    if (search != items.end()) {
        items.erase();
        return T;
    }
}

template<class T> T BagOfHolding<T>::removeItem() {
    int num = rand(0, items.length()-1);
    T item = items[num];
    items.erase(num);
    return item;
}