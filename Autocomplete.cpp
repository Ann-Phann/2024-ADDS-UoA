#include "Autocomplete.h"

Autocomplete::Autocomplete () :root(nullptr){}

Node* Autocomplete:: createNewNode(){
    Node* newNode = new Node();
    newNode->isEnd = false;
    return newNode;
}

void Autocomplete:: insert(std::string word){
    if (root == nullptr)
    {
        root = createNewNode();
    }

    int word_length = word.length();
    Node* current = root;

    //get each character in the word
    for (int i = 0; i < word_length; i++){
        char character = word[i];

        //if reach 'end' and can't find that character: add new character in
        if (current->children.find(character) == current->children.end()) {

            //inserting values by using [] operator 
            current->children[character] = createNewNode();
        }
        //if find out, get into that character/that spot
        current = current->children[character];
    }
    current->isEnd = true;
}

void Autocomplete::searchPrefix(Node* node, std::string prefix, std::vector<std::string>& result) {
    if (node->isEnd) {
        result.push_back(prefix);
    }

    for (auto const& [key, child] : node->children) {
        searchPrefix(child, prefix + key, result);
    }
}

std::vector<std::string> Autocomplete::getSuggestions(std::string partialWord) {
    std::vector<std::string> result;
    Node* current = root;
    std::string traverseUntil = "";

    //get each character in the word
    for (auto character : partialWord) {

        //if reach 'end' and can't find that character: add new character in
        if (current->children.find(character) == current->children.end()) {
            break;
        } else {
            traverseUntil += character;
        //if find out, get into that character/that spot
            current = current->children.find(character)->second;
        }
    }
    if (traverseUntil == partialWord) {
        searchPrefix(current, partialWord, result);
    }
    return result;
}

