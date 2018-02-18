#include <vector>
#include <iostream>
#include <utility>

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

// Adaptive and optimized version of insertion sort
void insertion_sort_optimized(std::vector<int> &vec) {
    for (int i = 1; i < vec.size(); ++i) {
        int val = vec[i], j = i;
        while ((j > 0) && (vec[j - 1] > val)) {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = val;
    }
}

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

int main() {
    std::vector<int> arr1 = { 5, 3, 10, 7, 30, 30, 23, 21 };
    std::vector<int> arr2 = { 5, 3, 10, 7, 30, 30, 23, 21 };
    std::vector<int> arr3 = { 5, 3, 10, 7, 30, 30, 23, 21 };
    std::cout << "Before" << std::endl;

    for (int n : arr1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    insertion_sort(arr1);
    std::cout << "After insertion_sort" << std::endl;
    for (int n : arr1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    insertion_sort_optimized(arr2);
    std::cout << "After insertion_sort_optimized" << std::endl;
    for (int n : arr2) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    insertion_sort_best(arr3);
    std::cout << "After insertion_sort_best" << std::endl;
    for (int n : arr3) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

