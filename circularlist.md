# Circular linked lists in C++

## Overview

A **circular linked list** is a variation of a linked list where all nodes are connected in a circular manner. The last node points back to the first node, creating a loop.

### Types of Circular Linked Lists
- **Singly Circular Linked List**: Each node points to the next node, and the last node points back to the first.

## Structure in C++
### Node Structure
```cpp
struct Node {
    int data;
    Node* next;
};
```

### Creating a Circular Linked List
```cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};


