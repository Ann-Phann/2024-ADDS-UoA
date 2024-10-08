#include <iostream>
#include "Autocomplete.h"

int main() {
    Autocomplete complete;
    std::string partial_word = "car";
    complete.insert("car");
    complete.insert("cart");
    complete.insert("care");
    complete.insert("cat");

    std::vector<std::string> allWord = complete.getSuggestions(partial_word);
    
    for (int i = 0; i < allWord.size(); i++) {
        std::cout << allWord[i] << std::endl;
    }
    return 0;
}