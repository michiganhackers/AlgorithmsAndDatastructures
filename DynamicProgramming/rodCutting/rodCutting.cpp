#include <iostream>
#include <vector>
#include <algorithm>

// Complexity: O(n^2)
int max_price_dp(int rodlen, const std::vector<int> &prices) {
	std::vector<int> computed;
	computed.reserve(rodlen + 1);
	computed[0] = 0;

	for (int i = 1; i <= rodlen; ++i) {
		int best_price = 0;

		for (int j = 0; j < i; ++j) {
			best_price = std::max(best_price, prices[j] + computed[i - j - 1]);
		}

		computed[i] = best_price;
	}

	return computed[rodlen];
}

// Complexity: O(2^n)
int max_price_exponential(int rodlen, const std::vector<int> &prices) {
	if (rodlen == 0) return 0;

	int best_price = 0;

	for (int i = 0; i < rodlen; ++i) {
		best_price = std::max(best_price, prices[i] + max_price_exponential(rodlen - i - 1, prices));
	}

	return best_price;
}

int main() {
	std::vector<int> prices = { 1, 5, 8, 9, 10, 17, 17, 20 };
	std::cout << "Best price for cutting a rod of length 8 is: " << max_price_exponential(8, prices) << std::endl;
	std::cout << "Best price for cutting a rod of length 8, using DP, is: " << max_price_dp(8, prices) << std::endl;
}
