# Intro:
- Implementation of Queue and Priority Queue in C++
- Uses Linked List and Array for queue operations

---

# Queue Implementation:
## LinkedList based Queue
- Uses a Linkedlist for dynamic size
- Methods:
    - 'enqueue(T cargo)': Adds to end
    - 'dequeue()': Removes from front
    - 'empty()': Checks if queue is empty

## Array Based Queue:
- Fixed size ('MAX_ITEMS=10')
- Circular queue approach
- Handles overflow and underflow errors
