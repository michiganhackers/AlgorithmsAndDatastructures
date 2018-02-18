## Quick Sort
### Time: Worst O(n²) -- Average O(n log n) ------ Space: O(log n)

Quick sort is one of the most widely used sorting algorithms. This is because of its good performance.
In the worst case it is still a quadratic sort, however, when sorting we typically tend to care more about the
average case, which for quick sort happens to be linear-logarithmic, which is theoretically as fast as a sort can get.

Quick sort is a recurisive divide and conquer algorithm since we start by partitioning the array into two halves,
then recurse on the those halves, and so on.

The way the partition happens is by selecting a pivot, you then move everything less than the pivot to the left of
the pivot, and everything greater than the pivot to the right of the pivot. One __important__ thing to note, is that
the actual sorting is done by this partitioning step, _and_ once a pivot has been selected and the array has been
partitioned the pivot is said to be in the correct position. That is, this same element will no longer move from this
position in other partioning steps.

There are multiple ways to pick this pivot, you want a pivot that partions the arrat into as equal sub-arrays as possible,
but you also need to do this in a reasonable amount of time. The median is the best pivot to pick, but this requires sorting,
and since we're trying to sort to begin with, this doesn't make sense. You can pick the pivot either at random, selecting
the end, or sampling by taking 3, 5, ... , x elements from the array and picking the median of these as the pivot.
This allows for a gurantee that the pivot will at least partion the array by X on both sides.

In these examples, we will simply pick the last element to be the pivot.

An example of this partition step is shown below:

```
arr = [ 5, 3, 4, 11, 10, 7 ]

Pick last element to be pivot --> 7

Now while the left index (0) is less than the pivot we increase the left index

[ 5, 3, 4, 11, 10, 7 ]
           ^        Left now is the index of 11 since 5, 3, 4 are all less than 7.

Now we decrease the right index (5) by 1 whenever the value at the right index is greater than OR equal to the pivot

[ 5, 3, 4, 11, 10, 7 ]
           ^ left
        ^ right -- The right index is now at the index of 4, since 11, 10, 7 are all greater or equal to 7 (pivot)

Since our left index is now greater than OR equal to our right index we will break out of the loop.
And we swap the value at index left with the value index pivot

vec[left] = vec[pivot]

[ 5, 3, 4, 7, 10, 11 ]

As you can see, 7 (our pivot) is now in the correct and final sorted position

We now return our left index (since this tells the caller where our partion occours)

You can visualize the partition like this:

[ 5, 3, 4 ] 7 [ 10, 11 ]

You now sort those 2 sub-arrays (not including 7) and thus why we call this divide and conquer.
```

An implementation in C++ is shown below:

```cpp
// This partition simply picks the pivot to be the end of the vector
// This can be optimized by doing some sampling/picking middle/etc
int partition(std::vector<int> &vec, int left, int right) {
    int pivot = --right;
    while (true) {
        while(vec[left] < vec[pivot])
            ++left;

        while (left < right && vec[right - 1] >= vec[pivot])
            --right;

        if (left >= right) break;

        std::swap(vec[left], vec[right - 1]);
    }

    std::swap(vec[left], vec[pivot]);

    return left;
}

void quick_sort(std::vector<int> &vec, int left, int right) {
    if (left + 1 >= right) return;
    int pivot = partition(vec, left, right);
    quick_sort(vec, left, pivot);
    quick_sort(vec, pivot + 1, right);
}
```

For a live demo of quick sort, visit [here](https://repl.it/@heyluis/quickSort)



