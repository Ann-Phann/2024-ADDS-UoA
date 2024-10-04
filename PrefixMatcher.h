#ifndef PREFIXMATCHER
#define PREFIXMATCHER

#include <unordered_map>
#include <string>

struct Node {
    /* nodes store a map to child node */
    std::unordered_map <char, Node*> children;
    bool isEnd = false;
    int routerNumber;

    Node(): routerNumber(-1), isEnd(false) {}
};

class PrefixMatcher {
private:
    Node* root;
    Node* createNewNode();

public:
    PrefixMatcher();

    //add a router address
    void insert(std::string address, int routerNumber);

    int selectRouter(std::string networkAddress);
};

#endif