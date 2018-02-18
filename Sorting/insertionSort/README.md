## Insertion sort
### Time: O(n²) ----- Space: O(1)

Insertion sort is one of the 3 elementary sorts. Out of the three it's the best of the quadratic sorts.

It's used inside actual libraries and in the real world. The C++ standard library uses insertion sort in _some_
scenarios.

Insertion sort works by, as the name suggests, inserting an element into the correct position of the _sub-array_.
However, since we usually want to accomplish these tasks in-place, the "insertion" part of insertion sort, can
actually be thought of as more of a swap, than an actual insertion into a new container.

Here is an example run through of the algorithm:

```
arr: [ 5, 3, 10, 7 ]
i = 1
j = 1

We set i = 1, because we start by declaring our "sub-array" to be the first element.


[ 5, 3, 10, 7 ] (top is i, bottom is j)
     ^
     ^

We now check that arr[j - 1] is in the correct position when compared to arr[j], in this case
since arr[j] is to the right of arr[j - 1] and yet, 3 < 5, we swap these elements

[ 3, 5, 10, 7 ]
     ^
  ^

j is now equal to the left of our main array, so break this iteration and go to the next

arr: [3, 5, 10, 7]
i = 2
j = 2

[3, 5, 10, 7]
       ^
       ^

Again, we check that arr[j - 1] > arr[j], if so, we swap, them, in this case its not so we continue

i = 2
j = 1

[3, 5, 10, 7]
       ^
    ^

arr[j - 1] < arr[j] so we're good, and we continue, and thus run into the left of the array and break into next iteration.

arr: [ 3, 5, 10, 7 ]
i = 3
j = 3

[ 3, 5, 10, 7 ]
            ^
            ^

Here we see that arr[j - 1] > arr[j], we swap them:

arr = [ 3, 5, 7, 10 ]

This will continue until j = left, but no swaps will happen since we're all in the correct positon and we're sorted.
```

An example C++ implementation of the above is shown below:

```cpp
// Non-adaptive and non-optimized version of insertion sort
void insertion_sort(std::vector<int> &vec) {
    for (int i = 1; i < vec.size(); ++i) {
        for (int j = i; j > 0; --j) {
            // Swap if left of j is > than j
            if (vec[j - 1] > vec[j]) {
                std::swap(vec[j - 1], vec[j]);
            }
        }
    }
}
```

However, insertion sort can be optimized and made adaptive.
While this doesn't improve the worst case runtime it will improve the real runtime by constant factors,
as well as the amount of checks we do in the inner loop by optimizing for the common case.

We can see above that we check that j > 0 (or the left of the array) this happens only once before we break,
yet we check for it every time we iterate. Another thing to be aware of is that we swap elements, when we can
simply move them.

We can solve the first problem of checking for j > 0, by putting a sentinal in the right most element of the
array, this sentinal will tell us when we're done checking the sub-array. The sentinal we will use, is the
minimum value in the array, since when we finish sorting we expect the min value to be in the left most position.

The second problem can be solved by storing a temp variable at vec[i] then moving vec[j - 1] to vec[j] whenever we
need to insert into the subarray. Then finally move the temp variable back into vec[j] at the end of the outer loop.
This gurantees the correct positon for the temp and only moves one value per "swap".

An implementation of these optimizations is shown below:

```cpp
// Best insertion sort with most optimization
void insertion_sort_best(std::vector<int> &vec) {
    // Find min and put into left (0 index), this also performs some pre-sorting
    for (int i = vec.size() - 1; i > 0; --i) {
        if (vec[i - 1] > vec[i]) {
            std::swap(vec[i - 1], vec[i]);
        }
    }

    // Same loop as before in the optimized, except this time no need to
    // check that j > 0, since the loop invariant handles that because the min
    // value is at the left most index
    for (int i = 2; i < vec.size(); ++i) {
        int val = vec[i], j = i;
        while (vec[j - 1] > val) {
            vec[j] = vec[j - 1];
            --j;
        }

        vec[j] = val;
    }
}
```

A live demo of insertion sort can be found [here](https://repl.it/@heyluis/inerstionSort).



