#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher() {
    root = createNewNode();
}

Node* PrefixMatcher::createNewNode() {
    Node* newNode = new Node();
    newNode->isEnd = false;
    return newNode;
}

void PrefixMatcher:: insert(std::string address, int routerNumber) {
        Node* current = root;
        for (char bit : address) {
            if (current->children.find(bit) == current->children.end()) {
                current->children[bit] = createNewNode();  // Create new node if it doesn't exist
            }
            current = current->children[bit];  // Move to the next node
        }
        current->isEnd = true;             // Mark the end of the router address
        current->routerNumber = routerNumber;  // Store the router number
}

// Find the router with the longest matching prefix for a given network address
int PrefixMatcher:: selectRouter(std::string networkAddress) {
    Node* current = root;
    int longestMatchingRouter = -1;  // Stores the router with the longest match
    Node* lastRouterNode = nullptr;

    for (char bit : networkAddress) {
        if (current->children.find(bit) == current->children.end()) {
            break;  // Stop if no further matching bit is found
        }
        current = current->children[bit];  // Move to the next node

        if (current->isEnd) {
            lastRouterNode = current;  // Track the deepest router node found
        }
    }

    if (lastRouterNode) {
        longestMatchingRouter = lastRouterNode->routerNumber;  // Return the router with the longest match
    }

    return longestMatchingRouter;  // Return -1 if no matching router is found
}