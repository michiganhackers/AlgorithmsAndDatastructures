#include <iostream>
#include <vector>

// Merges the vector into a new vector
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

int main() {
    std::vector<int> vec = { 5, 3, 10, 7, 30, 30, 23, 21 };
    std::cout << "Before:" << std::endl;
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    merge_sort(vec, 0, vec.size() - 1);
     std::cout << "After:" << std::endl;
    for (int n : vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
