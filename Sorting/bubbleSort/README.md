## BubbleSort
### Time: O(n²) ----- Space: O(1)

Bubble sort is one of most basic sorting algorithms to know.
It's simple to understand, and while there aren't a lot of real world use cases for it,
it's definitely something you want to know how to do.

Bubble sort works in place on an array, and sorts the elements.
You start at the first index of the array and compare the next index, if it's
less than the current index, you swap the elements. The important thing to remember about bubble sort
is that you compare pairs of elements and then continue moving down.

For example:

```
[ 5, 20, 10, 40, 30 ]
  ^  ^
No swap occours

[ 5, 20, 10, 40, 30 ]
      ^   ^
Swap

[ 5, 10, 20, 40, 30 ]
              ^  ^
Swap

[ 5, 10, 20, 30, 40 ]

Non-optimized bubble sort would continue again at:

[ 5, 10, 20, 30, 40 ]
     ^   ^
```

Here is a basic implementation of bubble sort

```cpp
void bubble_sort(std::vector<int> &vec) {
	for (int i = 0; i < vec.size() - 1; ++i) {
		for (int j = vec.size() - 1; j > i; --j) {
			if (vec[j] < vec[j - 1]) {
				std::swap(vec[j], vec[j - 1]);
			}
		}
	}
}
```
If we look at the algorithm above, it's pretty easy to determine the complexity, as
the outer loop will run from 0 to N-1, and the inner loop will from 1 to N-1, which
is going to be O(n²).

Even for a completely sorted array this bubble sort implementation will run in quadratic time,
we can optimize this however. To optimize we need to make the realization that if we never swap
in our inner loop, then the array is sorted! This makes sense because if one iteration of the array
has happened and no pairs of elements are out of place, then we are sorted.

The optimization implementation can be seen below:

```cpp
void bubble_sort_optimized(std::vector<int> &vec) {
	for (int i = 0; i < vec.size() - 1; ++i) {
		bool has_swapped = false;
		for (int j = vec.size() - 1; j > i; --j) {
			if (vec[j] < vec[j - 1]) {
				std::swap(vec[j], vec[j - 1]);
				has_swapped = true;
			}
		}

		// If we haven't swapped after one iteration, everything is sorted
		if (!has_swapped) return;
	}
}
```

This optimization brings our best case down to O(n), instead of quadratic.

For a live demo, go [here](https://repl.it/@heyluis/BubbleSort)
