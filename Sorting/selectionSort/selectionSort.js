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

let unsortedArr = [5, 10, 30, 3, 4, 10, 2, 1]
selectionSort(unsortedArr)
console.log(unsortedArr)
