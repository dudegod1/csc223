#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;

// Template struct for a Node in the circular linked list
template <class T>
struct Node
{
    T cargo; // Stores the value of the node
    Node<T>* next; // Pointer to the next node in the circular list

    // Constructor to initialize a node with given cargo and next pointer
    Node(T cargo, Node<T>* next)
    {
        this->cargo = cargo;
        this->next = next;
    }
    #include <type_traits> // Needed for std::is_same

    // Converts the cargo into a string representation
    string stringy() const
    {
        if constexpr (std::is_same<T, int>::value) { // Checks if T is an int
            return std::to_string(cargo);
        } else {
            return string(cargo); // Assumes T is std::string or another string-convertible type
        }
    }
};

