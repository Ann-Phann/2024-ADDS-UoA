#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include <vector>
#include <string>
#include "Node.h"
class Autocomplete {
private: 
    Node* root;
    Node* createNewNode();
    void searchPrefix(Node* currentNode, std::string prefix, std::vector<std::string>& result);

public:
    Autocomplete();
    void insert(std::string word);
    std::vector<std::string> getSuggestions(std::string partialWord); 
};
#endif