#include <iostream>

template <class T>
class ArrayStack {
public: 
// Creates empty stack with capacity of size 8 and size 0
ArrayStack(): _capacity{8}, _size{0}, array{new T[8]} { } 

// Pushes an element onto the stack
void push(T elt) {
    if (_size >= _capacity) { resize(); }		
    array[_size++] = elt;
}

// Removes an element from the stack
void pop() {
    if (_size == 0) { throw "Attempt to pop from empty stack"; }
    --_size;
}

// Returns the top most element in the stack (the newest element inserted)
T top() {
    return array[_size - 1];
}

// Returns the size of the stack
unsigned int size() {
    return _size;
}

// Returns whether or not the stack is empty
bool empty() {
    return _size == 0;
}


private: 
unsigned int _capacity;
unsigned int _size;
T* array;

// Resizes internal array by copying into new array and deleting old one
void resize() {
    _capacity *= 2;
    T *newArr = new T[_capacity];

    for (int i = 0; i < _size; ++i) {
        newArr[i] = array[i];
    }

    delete[] array;
    array = newArr;
}
};


int main() {
// Create a stack of ints
ArrayStack<int> stack;
stack.push(3);
stack.push(2);
stack.push(1);

std::cout << "Top of stack: " << stack.top() << std::endl;

while (!stack.empty()) {
    std::cout << stack.top() << std::endl;
    stack.pop();
}
}