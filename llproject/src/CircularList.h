#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// Template struct for a Node in the circular linked list
template <class T>
struct Node
{
    T cargo; // Stores the value of the node
