#include<iostream>
#include<vector>
#include <utility>

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

int main() {
    std::vector<int> vec = { 5, 10, 7, 23, 21 };
    std::cout << "Before:" << std::endl;
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    heap_sort(vec);
    std::cout << "After: " << std::endl;
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

}

