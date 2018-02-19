## Merge sort
### Time: O(n log n) ----- Space: O(n)

Merge sort is another popular sorting algorithm. It's widely used just like quick sort.
It is a bit slower than quick sort (by a constant factor) on average. However, unlike quick sort, merge sort is a
stable sorting algorithm, so if stability is something you care about then merge sort is great for this!

Merge sort is a recursive divide and conquer algorithm, which is why we get the n log n complexity.
However, since the merge step must create a new array and merge the divided sub-arrays, this gives us a space complexity
of O(n). Which is less than ideal if memory is an issue.

Merge sort works by dividing the array into ever smaller sub-arrays, until they're of size one, since it's of size 1
we know it's sorted. You then merge these sub-arrays into bigger sub-arrays and thus where the sorting happens.

Here is an implementation of merge sort in C++:

```cpp
// Time: O(n), Space: O(n)
void merge(std::vector<int> &vec, int left, int mid, int right) {
    int size = right - left + 1;
    // New merged vector
    std::vector<int> merged(size);

    for (int i = left, j = mid + 1, k = 0; k < size; ++k) {
        if (i > mid)
            merged[k] = vec[j++];
        else if (j > right)
            merged[k] = vec[i++];
        else
            merged[k] = (vec[i] <= vec[j]) ? vec[i++] : vec[j++];
    }

    std::copy(merged.begin(), merged.end(), vec.begin() + left);
}


void merge_sort(std::vector<int> &vec, int left, int right) {
    if (right <= left) return;

    // Recurse
    int mid = (right + left) / 2; // Possible case of overflow here
    merge_sort(vec, left, mid);
    merge_sort(vec, mid + 1, right);

    merge(vec, left, mid, right);
}
```

For a live demo of Merge sort, visit [here](https://repl.it/@heyluis/mergeSort)
