#ifndef NODE_H
#define NODE_H

#include <unordered_map>
class Node { 
private: 
    bool isEnd;
    std::unordered_map<char, Node*> children;
    
public:
    friend class Autocomplete;
};
#endif