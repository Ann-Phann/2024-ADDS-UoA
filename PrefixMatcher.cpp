#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() {
    root = createNewNode();
}

Node* PrefixMatcher::createNewNode() {
    Node* NewNode = new Node(); 
    return NewNode;
}

void PrefixMatcher::insert(std::string address, int routerNumber) {
    Node* current = root;
    for (auto bit : address) {
        if(current->children.find(bit) == current->children.end()) {
            current->children[bit] = createNewNode();
        }
        current = current->children[bit];
    }
    current->isEnd = true;
    current->routerNumber = routerNumber;
}

int PrefixMatcher:: selectRouter(std::string networkAddress){
    Node* current = root;
    int longestMatchingRouter = -1;
    Node* lastRouter = nullptr;

    for (auto bit : networkAddress) {
        if (current->children.find(bit) == current->children.end()) {
            break;
        }
        current = current->children[bit];

        if(current->isEnd) {
            lastRouter = current;
        }
    }
    if (lastRouter) {
        longestMatchingRouter = lastRouter->routerNumber;
    }
    return longestMatchingRouter;
}