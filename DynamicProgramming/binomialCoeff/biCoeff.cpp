#include <iostream>
#include <vector>

using Memo = std::vector<std::vector<long>>;

// Returns the binomial coefficient of n choose m
long binomial(long n, long m, Memo &memo) {
	// Base case
	if (n == m || m == 0)
		return 1;

	// Use memo!
	if (memo[n][m] != 0)
		return memo[n][m];

	// Calculate
	long b1 = binomial(n - 1, m - 1, memo);
	long b2 = binomial(n - 1, m, memo);

	// Store result (memoize)
	memo[n - 1][m - 1] = b1;
	memo[n - 1][m] = b2;

	return b1 + b2;
}

int main() {
	// Input
	long n = 20, m = 12;

	// Initialize memo to be N x N matrix
	Memo memo{static_cast<size_t>(n + 1),
			  std::vector<long>(static_cast<size_t>(n + 1))};

	std::cout << n << " choose " << m << " = " << binomial(n, m, memo);
}
