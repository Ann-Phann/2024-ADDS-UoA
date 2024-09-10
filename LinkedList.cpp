#include "LinkedList.h"
#include <limits>
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {
    if (len == 0) {
        head = nullptr;
        return;
    }

    //Initialise head node
    head = new Node(array[0], nullptr);

    //Create temporary node to hold 
    Node* temp = head;

    for (int i = 1; i < len; i++) {
        Node* newNode = new Node(array[i], nullptr);
        temp->link = newNode; //link the node previous to the newNode
        temp = newNode; //set temp pointer to the next node
    }
}

LinkedList::~LinkedList(){
    while (head) {
        Node* temp = head;
        head = head->link;
        delete temp;
    }
}

void LinkedList:: insertPosition(int pos, int newNum){
    //if pos <= 1, insert at the front of the list
    if (pos <= 1 || head ==nullptr) {
        Node* newNode = new Node(newNum, head);
        head = newNode;
        return;
    }

    //To get to the position where we want to insert, we have to stop before that position, and if we pass the tail, we stop and insert at the end
    Node* temp = head;
    for (int i = 1; (i < pos - 1) && (temp->link != nullptr); i++) {
        temp = temp->link;
    }
    
    Node* newNode = new Node(newNum, temp->link);
    temp->link = newNode;
}

bool LinkedList:: deletePosition(int pos) {
    //can't delete if the list is empty or invalue input
    if (head == nullptr || pos < 1) {
        return false;
    }

    //consider delete at the front
    if (pos == 1) {
        Node* node_need_to_detele = head;
        head = head->link;
        delete node_need_to_detele;
        return true;
    }

    Node* current = head;
    for (int i = 1; i < pos - 1; i++) {
        current = current->link;
    }

    if (current == nullptr || current->link == nullptr) {
        return false;
    }

    Node* node_need_to_delete = current->link;
    current->link = node_need_to_delete->link;
    delete node_need_to_delete;
    return true;
}

int LinkedList::get(int pos) {
    if (pos < 1) {
        return std::numeric_limits < int >::max();
    }

    Node* temp = head;
    for (int i = 1; i < pos && temp; i++) {
        temp = temp->link;
    }
    if (!temp) {
        return std::numeric_limits < int >::max();
    }

    int data_position = temp->data;
    return data_position;
}

int LinkedList::search(int target) {
    int index = 1;
    Node* temp = head;
    while (temp) {
        if (temp->data == target) {
            return index;
        }
        temp = temp->link;
        index++;
    }

    return -1;
}

void LinkedList::printList() {
    if (head == nullptr) {
        std::cout << "" ;
    }

    Node* temp = head;
    std::cout << "[";
    while (temp) {
        std:: cout << temp->data << " ";
        temp = temp->link;
    }
    std::cout << "]";
}