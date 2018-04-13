## Zero-one Knapsack

Imagine you are a bank robber in the 1800's, you are in the middle of robbing
a bank. You have a bag or knapsack, and you want to collect as many items
from the bank as possible, but, you also want to maximize your total value
stolen. Afterall, you are a bank robber. How do you go about making sure
to fit your bag to the brim while also maximizing the amount of value stolen?

This problem is asked by a lot of companies and is a classic Dynamic Programming
problem. There are several forms of it, for this problem, we will be doing
the "zero-one knapsack" problem, 0-1 because you either take an item (1) or
leave the item (0).

### Brute force

Let's look at a brute force solution for this algorith, this is one
of those cases where a brute force makes little sense and might even be
harder to come up with than the simple dynamic programming solution.

For the brute force solution, we would simply generarte all possible subsets
of the items, that is if we had item `[A, B, C]`, we would try
`[A], [B], [C], [A, B], [A, C], [B, C], [A, B, C]`, then we would go through
all our subsets and figure out which one gives us our best value AND fits in
our bag. As you can see, the brute force is pretty bad and does a lot of
un-needed work, which is why it's `O(n * 2^n)`.

### Greedy

We can try to solve this problem using a greedy algorithm. We can
start by sorting the items in the bank by a ratio of their weight and values,
then go through each item, starting at the most dense, and if it fits in our bag,
we put it in. This algorithm would be `O(n log n)` since we need to sort,
but other wise this is a much better run-time than our brute force! However,
like the issue with greedy algorithms is that we're not guranteed an optimal
solution (i.e. the most value in our knapsack). Thus, if our problem required
the absolute value then this greedy algorithm would not work. This is however,
a good heuristic to know.

### Optimal solution

For the optimal solution we will use dynamic programming. And like all dynamic
programming problems, knowing the trick makes it super easy to code.

The trick for this problem is to realize that the max value of a knapsack
of capacity, `N`, is, `max(N - 1) + x`, where `N - 1` is how much value
we could fit in a knapsack of less size, because at the end of the day, we could
always fit a knapsack of size 6 in a knapsack of size 7. Thus, if we know
the value for size 6, the value for size 7 is going to be size 6 + whatever
else we can fit into the remaining space.

This relation allows us to store the previous values of our knapsacks, which
means we do not need to recompute these values and we save a lot of computations!

Here it is written in C++:

```cpp
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
```

For a live demo, go [here](https://repl.it/@heyluis/Zero-One-Knapsack)
