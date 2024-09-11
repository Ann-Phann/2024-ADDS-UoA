#include "LinkedList.h"
#include <iostream>
LinkedList::LinkedList() {
    head = nullptr;
}

LinkedList::LinkedList(int* array, int len) {
    if (len < 1) {
        head = nullptr;
        return;
    }

    head = new Node(array[0], nullptr); 
    Node* current = head;

    for (int i = 1; i < len; i++) {
        Node* newNode = new Node(array[i], nullptr);
        current->next = newNode;
        current = newNode;
    }
}

LinkedList::~LinkedList() {
    while (head) {
        Node* temp = head; 
        head = head->next;
        delete temp;
    }
}

void LinkedList:: insertAtFront (int newNum) {
    if (head == nullptr) {
        head = new Node(newNum, nullptr);
    }
    else {
        Node* newNode = new Node(newNum, head); 
        head = newNode;
    }
}

void LinkedList::insertAtEnd(int newNum) {
    Node* newNode = new Node(newNum, nullptr);
    if (head == nullptr) {
        head = newNode;
        return;
    } 

    Node* temp = head; 
    while (temp->next){
        temp = temp->next;
    }
    temp->next = newNode;

}

void LinkedList::insertPosition (int pos, int newNum) {
    if(pos <= 1) {
        insertAtFront(newNum);
    }

    Node* temp = head;
    for (int i = 1; i < pos-1 && temp; i++) {
        temp = temp->next;
    }
    if(!temp) {
        insertAtEnd(newNum);
    }

    Node* newNode = new Node(newNum, temp->next);
    temp->next = newNode;
}

bool LinkedList::deletePosition(int pos) {
    if (pos < 1) {
        return false;
    }

    Node* temp = head;
    for (int i = 1; i < pos -1 && temp; i++) {
        temp= temp->next;
    }

    if(!temp) {
        return false;
    }

    Node* node_delete = temp->next;
    temp->next = node_delete->next;
    delete node_delete;
    return true;
}

int LinkedList::get(int pos) const {
    if (pos < 1) {
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    if(!temp) {
        return;
    }
    return temp->data;
}

int LinkedList::search (int target) const {
    int pos = 1;
    Node* temp = head;
    while (temp) {
        if(temp->data == target) {
            return pos;
        }
        temp = temp->next;
        pos++;

    }
    return -1;
}

void LinkedList::printList() const {
    std::cout<< "[" ;
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " " ;
        temp =temp->next;
    }
    std::cout << "]";
}