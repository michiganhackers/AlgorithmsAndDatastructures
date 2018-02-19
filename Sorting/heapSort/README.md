## Heap sort
### Time O(n log n) ---- Space: O(1)

Heap sort is another one of the widely used and efficient sorting algorithms.
It works by cleverly using a heap to perform a sort on the given array.

You start with an unsorted array, say: _[ 5, 10, 7, 23, 21 ]_.
You then build this array into a heap which takes _O(n)_ time, this leaves the max element in the 0th index of the vector.

Now, in a heap whenever we pop (extract max) we do a log(n) operation to fix the heap ordering. Same concept
applies to heap sort. We fisrt build said heap and we then continually pop until we have a sorted array! Hence the
O(n log n) complexity.

However, we don't really want to "pop" from the array, we just want to swap elements around since idealy we want
to be able to do this in-place with no additional space.

To do this we can _pop_ or _extractMax_ from the newly built heap, and swap the last element in our array, with
the head of the array (the max). We then decrease the range of our heap to exclude the end of array, since it is now
in the correct place. We basically, just move the max element to the end of the array each _pop_.

For example:

Give this array -- [ 5, 10, 7, 23, 21 ]

We build it into a heap, and we might get something like this: [ 23, 21, 7, 10, 5 ]
The actual ordering doesn't matter, as long as the max is in the 0th index.
We then swap the 0th index with the Nth index --> [ 5, 21, 7, 10, 23 ]

Next we decrease N by 1, since 23 is now in the right position, we then make sure to fix our heap,
which is a simple O(log n) operation, and continue the process until we're fully sorted.

An implementation in C++ is shown below:

```cpp
// Swaps the largest child with the parent if parent is smaller than child
// O(log n)
void fix_down(std::vector<int> &vec, int k, int depth) {
    // Loop while we have a left child
    while (((k + 1) * 2 - 1) < depth) {
        int c = (k + 1) * 2 - 1;
        // If right child is > left, use that instead
        if (c + 1 < depth && vec[c + 1] > vec[c])
            ++c;

        // If parent is > child, we're done
        if (vec[k] >= vec[c])
            break;

        std::swap(vec[k], vec[c]);
        k = c;
    }
}

// Builds a heap out of a vector
// O(n)
void build_heap(std::vector<int> &vec) {
    for (int i = vec.size() - 1; i >= 0; --i) {
        fix_down(vec, i, vec.size());
    }
}

void heap_sort(std::vector<int> &vec) {
    build_heap(vec);

    // Now loop through the built heap, "extracting" max by putting in end
    // and then fixing
    int k = vec.size() - 1;
    while (k >= 0) {
        std::swap(vec[0], vec[k--]);
        fix_down(vec, 0, k + 1);
    }
}
```

For a live demo of heap sort, follow [this link](https://repl.it/@heyluis/heapSort)
