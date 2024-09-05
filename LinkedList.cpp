#include "LinkedList.h"
#include <iostream>
#include <limits> // Include this header for std::numeric_limits

// LinkedList class implementation

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::LinkedList(int *array, int len) : head(nullptr) {
    for (int i = 0; i < len; ++i) {
      insertAtEnd(array[i]);
    }
}

LinkedList::~LinkedList() {
    while (head) {
      Node *temp = head;
      head = head->getLink();
      delete temp;
  }
}

void LinkedList::insertAtFront(int newNum) {
    Node *newNode = new Node(newNum, head);
    head = newNode;
}

// void LinkedList::insertAtFront(int newNum) {
//     Node *newNode = new Node(newNum);
//     newNode->setLink(head);
//     head = newNode;
// }
void LinkedList::insertAtEnd(int newNum) {
    Node *newNode = new Node(newNum, nullptr);

    //Check if the list is empty
    if (!head) {
      head = newNode;
      return;
    }

    Node *temp = head;

    //Traverse the list to the end
    while (temp != nullptr) {
      temp = temp->getLink();
    }
    // Set the link of the last node to the new node
    temp->setLink(newNode); //temp at last node
}

void LinkedList::insertPosition(int pos, int newNum) {
    if (pos <= 1) {
      insertAtFront(newNum);
      return;
    }

    Node *temp = head;
    for (int i = 1; i < pos - 1 && temp; ++i) {
      temp = temp->getLink();
    }

    if (!temp) {
      insertAtEnd(newNum);
      return;
    }
    
    // Insert the new node between temp and the next node
    Node *newNode = new Node(newNum, temp->getLink()); //This means the new node's link will be set to what the current temp node was previously pointing to.
    temp->setLink(newNode);
}

bool LinkedList::deletePosition(int pos) {
  if (pos < 1 || !head) {
    return false;
  }

  if (pos == 1) {
    Node *nodeToDelete = head;
    head = head->getLink();
    delete nodeToDelete;
    return true;
  }

  Node *temp = head;
  for (int i = 1; i < pos - 1 && temp; ++i) {
    temp = temp->getLink();
  }

  if (!temp || !temp->getLink()) {
    return false;
  }

  Node *nodeToDelete = temp->getLink();
  temp->setLink(nodeToDelete->getLink());
  delete nodeToDelete;
  return true;
}

int LinkedList::get(int pos) const {
  if (pos < 1) {
    return std::numeric_limits<int>::max(); // Use
                                            // std::numeric_limits<int>::max()
  }

  Node *temp = head;
  for (int i = 1; i < pos && temp; ++i) {
    temp = temp->getLink();
  }

  // if (!temp) {
  //   return std::numeric_limits<int>::max(); // Use
  //                                           // std::numeric_limits<int>::max()
  // }

  return temp->getData();
}

int LinkedList::search(int target) const {
  Node *temp = head;
  int index = 1;
  while (temp) {
    if (temp->getData() == target) {
      return index;
    }
    temp = temp->getLink();
    ++index;
  }
  return -1; // Not found
}

void LinkedList::printList() const {
  if (!head) {
    std::cout << "List is empty." << std::endl;
    return;
  }

  Node *temp = head;
  std::cout << "[" << std::endl;
  while (temp) {
    std::cout << temp->getData() << " ";
    temp = temp->getLink();
  }
  std::cout << "]" << std::endl;
}
