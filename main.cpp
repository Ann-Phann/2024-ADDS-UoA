// check if DocumentManager class work

#include <iostream>
#include "DocumentManager.h"

int main() {
    DocumentManager manager;
    manager.addDocument("doc1", 1, 2);
    manager.addDocument("doc2", 2, 1);
    manager.addDocument("doc3", 3, 3);

    manager.addPatron(1);
    manager.addPatron(2);
    manager.addPatron(3);

    std::cout << "Search for doc1: " << manager.search("doc1") << std::endl;
}