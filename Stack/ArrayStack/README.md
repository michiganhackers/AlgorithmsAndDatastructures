## ArrayStack

| Function  	| Complexity 	|
|-----------	|------------	|
| push(val) 	| Amortized O(1) 	|
| pop()     	| O(1)       	|
| empty()   	| O(1)       	|
| size()    	| O(1)       	|

Most people know how to implement a stack using a linked list. However, there are reasons you sometimes may not want to use a linked list. Due to locality of reference linked lists are often slower than contiguous memory like arrays. There is also the memory overhead of using a linked list since each node must store a pointer to the next node (and/or previous node) plus the value itself.

For performance tests visit [this site](https://baptiste-wicht.com/posts/2012/12/cpp-benchmark-vector-list-deque.html) which benchmarked the performance of arrays vs linked lists.

The basic gist of an array based stack implementation is rather simple as well.

Given a stack:

```
[]
```

When we insert, we will insert at the back, when we go to access we also will access from the back, and finally to pop we also "delete" from the back. This gives us a nice "constant" runtime complexity since operations on the back of arrays do not require shifting the elements in the array.

Here is an example run through of a stack:

```
// Empty stack

[]

// Insert 1

[1]

// Insert 0

[1, 0]

// Insert 3

[1, 0, 3]

// Remove top

[1, 0]
```

As you can see this is fairly straight forward!

Here is an implementation in C++:

```cpp
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
```

One important thing to note is I didn't implement copy/assignment constructors/operators. I'll leave this up to the reader, remember deep copies of the members will be required here.
