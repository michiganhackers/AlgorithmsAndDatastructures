#include <iostream>
#include <vector>
#include <algorithm>

// Defines a bank item
struct Item {
	Item(int s, int v) : size{s}, value{v} { }

	int size;
	int value;
};

using Bank = std::vector<Item>;

// Returns the most value that can be stolen from a bank
// given a knapsack of size `size`
int steal(int capacity, const Bank &bank) {
	std::vector<int> costs(capacity + 1, 0);

	for (size_t i = 1; i <= capacity; ++i) {
		costs[i] = costs[i - 1];

		for (const auto &item : bank) {
			int space = i - item.size;
			if (space >= 0)
				costs[i] = std::max(costs[i], costs[space] + item.value);
		}
	}

	return costs[capacity];
}

int main() {
	// Initialize items
	Bank bank;
	bank.emplace_back(1, 1);
	bank.emplace_back(2, 6);
	bank.emplace_back(5, 18);
	bank.emplace_back(6, 22);
	bank.emplace_back(7, 28);

	std::cout << "Total value stolen: " << steal(11, bank);
}
