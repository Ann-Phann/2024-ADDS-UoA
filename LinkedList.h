#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList {
private:
    Node* head;

public:
    //constructor
    LinkedList();

    //A constructor that creates a list of from a C-array of length len.
    LinkedList(int* array, int len);

    //destructor
    ~LinkedList();

    //method to insert a new node containing the number newNum into the pos position.
    void insertPosition(int pos, int newNum);

    //method to remove the node at position pos from the list and delete it. If it successfully deletes the node, it should return true. If pos is out-of-bounds, it should return false.
    bool deletePosition(int pos);

    // method that returns pos's Node's data member variable.
    int get(int pos);

    //searches the list for the first occurrence of target in the list and returns the index of where target is. If target does not exist in the list, return -1.
    int search(int target);

    //method that prints the data of all the nodes in the list, separated by spaces and encapsulated by '[' and ']'. In the case of an empty list, it prints nothing.
    void printList();
};
#endif