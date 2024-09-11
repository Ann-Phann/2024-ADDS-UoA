#ifndef NODE_H
#define NODE_H

class Node {
private: 
    int data;
    Node* next;

public:
    Node(int data, Node* next = nullptr);
    ~Node();
    friend class LinkedList;
};
#endif