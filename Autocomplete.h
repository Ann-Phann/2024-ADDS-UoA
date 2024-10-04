#ifndef AUTOCOMPLETE
#define AUTOCOMPLETE

#include <vector>
#include <unordered_map>
#include <iostream>
struct Node {
    /* nodes store a map to child node */
    std::unordered_map <char, Node*> children;
    bool isEnd = false;
};

class Autocomplete {
private:
    Node* root;
    Node* createNewNode();

    // Helper function to recursively collect all words from a given node
    void searchPrefix(Node* node, std::string prefix, std::vector<std::string>& result);
public:
    Autocomplete();
    std::vector<std::string> getSuggestions(std::string partialWord); // return the known words that start with partialWord
    void insert(std::string word); // add a word to the known words
};

#endif