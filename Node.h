#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node {
private:
    int data;          // Data stored in the node
    Node* link;        // Pointer to the next node

public:
    // Constructor to initialize the node with given data and link
    Node(int data, Node* link = nullptr);

    // Getter for data
    int getData() const;

    // Setter for data
    void setData(int data);

    // Getter for link
    Node* getLink() const;

    // Setter for link
    void setLink(Node* link);
};

#endif // NODE_H
