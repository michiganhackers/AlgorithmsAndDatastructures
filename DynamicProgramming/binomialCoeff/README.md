## Binomial Coeffecient

This is a nice problem to introduce dynamic programming.
In math we sometimes want the binomial coefficient when we're counting, or
when we think about the possible combinations of things.

First, let's talk about a brute force way of doing this.
One way to do this is use the definiton of the binomial coefficient, which is
that `N choose M = N! / (M! (N - M)!)`.

So you could imagine that to solve this problem we can simply calculate
N! and M!.

Here is some pseduo code which calculates factorial naively

```
procedure: factorial
    if n equals 0 or 1:
        return 1

    return n * factorial(n - 1)
```

As you can see this code will run exactly, N! amount of times.
Which is pretty bad in terms of complexity and we will quickly reach the
limit of our stack frame, and then bad things happen.

We can, however, rearrange the formula to something which is more recursive
in it's definition:

```
N choose M = (N - 1 choose M - 1) + (N - 1 choose M)

Base case: N choose 0 = N choose N = 1, for N >= 0
```


As you can see this new definition relies on previous values of N and M
to give us our result.
This problem now lends it self nicely to dynamic programming because of it's
recursive nature.

Thus, since we will have overlapping sub-problems when calculating the
binomial coeffecient, we can use dynamic programming to save these calculations
and thus lower our computation cost!

We can do this by creating a 2-D matrix. Where `matrix[n][m]` gives us
the solution for `n choose m`. When we find a solution for a sub-problem,
we save it into our matrix (or memo) and thus can reuse it for later.

Here is a top-down DP solution in C++:

```cpp
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
```

Using dynamic programming or memoization, we went from a N! algorithm,
to a much nicer and much more efficient `O(n * m)` algorithm.

For a live demo, go [here](https://repl.it/@heyluis/BinomialCoef)
