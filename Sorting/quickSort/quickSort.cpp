#include <vector>
#include <iostream>
#include <utility>


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


int main() {
    std::vector<int> vec1 = {5, 3, 10, 7, 30, 30, 23, 21 };
    std::cout << "Before: " << std::endl;
    for (int n : vec1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    quick_sort(vec1, 0, vec1.size());
    std::cout << "After quick_sort: " << std::endl;
    for (int n : vec1) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
