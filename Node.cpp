#include "Node.h"

// Constructor implementation
Node::Node(int data, Node* link)
    : data(data), link(link) {}

// Getter for data
int Node::getData() const {
    return data;
}

// Setter for data
void Node::setData(int data) {
    this->data = data;
}

// Getter for link
Node* Node::getLink() const {
    return link;
}

// Setter for link
void Node::setLink(Node* link) {
    this->link = link;
}
