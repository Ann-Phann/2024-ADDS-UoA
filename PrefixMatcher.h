#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include <unordered_map>
#include <string>

struct Node {
    bool isEnd = false;
    std::unordered_map<char, Node*> children;
    int routerNumber;

    Node() : routerNumber(-1), isEnd(false){};
};

class PrefixMatcher {
private:
    Node* root; 
    Node* createNewNode();

public:
    PrefixMatcher();
    int selectRouter(std::string networkAddress);
    void insert(std::string address, int routerNumber); // add a router address
};
#endif