#ifndef NODE_H
#define NODE_H

class Node {
private:
    int data;
    Node* link;

public:
    Node(int data, Node* link);

    void setData(int data);
    void setLink(Node* link);

    friend class LinkedList;
};
#endif