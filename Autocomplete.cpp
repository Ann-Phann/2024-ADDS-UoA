#include "Autocomplete.h"

Autocomplete::Autocomplete() {
    root = createNewNode();
    root->isEnd = false;
}

Node* Autocomplete::createNewNode() {
    Node* newNode = new Node();
    newNode->isEnd = false;
    return newNode;
}

void Autocomplete::insert(std::string word) {
    if (root == nullptr) {
        root = createNewNode();
    }

    Node* current = root;
    for (auto c : word) {
        if (current->children.find(c) == current->children.end()) {
            current->children[c] = createNewNode();
        }
        current = current->children[c]; 
    }
    current->isEnd = true;
}

void Autocomplete::searchPrefix(Node* currentNode, std::string prefix, std::vector<std::string>& result) {
    if(currentNode->isEnd) {
        result.push_back(prefix);
    }
    for (auto const&[key, child] : currentNode->children) {
        searchPrefix(child, prefix + key, result);
    }
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    Node* current = root;
    std::vector<std::string> result;
    std::string traverseUntil = "";

    for (auto c : partialWord) {
        if (current->children.find(c) == current->children.end()) {
            break;
        } else {
            traverseUntil += c;
            //get to that position
            current = current->children[c];
        }
    }
    if (traverseUntil == partialWord) {
        searchPrefix(current, partialWord, result);
    }
    return result;
}