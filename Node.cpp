#include "Node.h"

Node::Node(int data, Node* link) {
    this->data = data;
    this->link = nullptr;
}

void Node::setData(int data){
    this->data = data;
}

void Node::setLink(Node* link) {
    this->link = link;
}