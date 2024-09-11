#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h" // Include the Node class definition
#include <limits> // For std::numeric_limits

class LinkedList {
private:
  Node *head; // Pointer to the first node

public:
  // Default constructor
  LinkedList();

  // Constructor to create a linked list from an array with len
  LinkedList(int *array, int len);

  // Destructor
  ~LinkedList();

  // Insert a node at the front of the list
  void insertAtFront(int newNum);

  // Insert a node at the end of the list
  void insertAtEnd(int newNum);

  // Insert a node at a specific position
  void insertPosition(int pos, int newNum);

  // Delete a node at a specific position
  bool deletePosition(int pos);

  // Get the value at a specific position
  int get(int pos) const;

  // Search for a value and return its position (1-based index)
  int search(int target) const;

  // Print the list
  void printList() const;
};

#endif // LINKEDLIST_H
