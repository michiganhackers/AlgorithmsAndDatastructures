## Selection Sort
### Time: O(n²) ----- Space: O(1)

Selection sort, like bubble sort, is one of the elementary sorts that every programmer should be familiar with.
While it doesn't have much real world use cases, and it's actually less performant than bubble sort in some cases,
selection sort is still an interesting sorting algorithm.

The way it works is by first declaring a part of the array, a subarray, that is sorted. In the initial case,
this subarray is of size 0. You then go and "select" or find the minimum element in the unsorted section of the array.
Then you simply put this minimum element into the sorted subarray.

Selection sort is neat in that, there will be at most a linear amount of swaps. Since you only swap once per iteration,
unlike algorithms like bubble sort where swapping is done at every sub-pair.

An example of seletion sort is detailed below:

```
Arr = [ 5, 10, 30, 20 ]
UnsortedSub = 0 (index)
Min = 0 (index)

findMin(Arr) -> 0, this returns the index of the min element in the array, in this case 0.

Swap: UnsortedSub with Min, in this case nothing happens

Arr = [ 5, 10, 30, 20 ]
UnsortedSub = 1
Min = 1

In this case the same as the previous example happens, 10 is swapped with 10

Arr = [ 5, 10, 30, 20 ]
UnsortedSub = 2
Min = 2

findMin(Arr) -> 3

Thus we now swap UnsortedSub (2) with Min (3), and we get the fully sorted array:

Arr = [ 5, 10, 20, 30 ]
```

An implementation in JavaScript is shown below:

```js
function selectionSort(arr) {
	let sorted = 0

	for (let i = 0; i < arr.length; ++i) {
		let min = i

        for (let j = i + 1; j < arr.length; ++j) {
			if (arr[j] < arr[min]) min = j
		}

		// Swap
		let temp = arr[sorted]
		arr[sorted] = arr[min]
		arr[min] = temp
        // Increase the sorted "sub-array" index
        sorted += 1
	}
}
```

For a live demo, visit [here](https://repl.it/@heyluis/SelectionSort)
