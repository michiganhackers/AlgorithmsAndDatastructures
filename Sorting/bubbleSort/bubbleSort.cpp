#include <iostream>
#include <vector>
#include <utility>

void bubble_sort(std::vector<int> &vec) {
	for (int i = 0; i < vec.size(); ++i) {
		for (int j = i + 1; j < vec.size(); ++j) {
			if (vec[j] < vec[i]) {
				std::swap(vec[i], vec[j]);
			}
		}
	}
}

void bubble_sort_optimized(std::vector<int> &vec) {
	for (int i = 0; i < vec.size(); ++i) {
		bool has_swapped = false;
		for (int j = i + 1; j < vec.size(); ++j) {
			if (vec[j] < vec[i]) {
				std::swap(vec[i], vec[j]);
				has_swapped = true;
			}
		}
		// If we haven't swapped after one iteration, everything is sorted
		if (!has_swapped) return;
	}
}

int main() {
	std::vector<int> arr = { 5, 10, 30, 30, 21, 3, 1, 2 };
	std::vector<int> arr2 = { 5, 10, 30, 30, 21, 3, 1, 2 };
	std::cout << "Before" << std::endl;
	for (int i : arr) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	bubble_sort(arr);
	std::cout << "After bubble_sort" << std::endl;
	for (int i : arr) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;

	bubble_sort_optimized(arr2);
	std::cout << "After bubble_sort_optimized" << std::endl;
	for (int i : arr2) {
		std::cout << i << ", ";
	}
	std::cout << std::endl;
}

