## Dynamic Programming - Rod Cutting

### Time: O(n²) ---- Space: O(n²)


> Given a rod of length, __n__, how can you split it into the most optimal amount of pieces to get the best price for the rod?

This is the question we will answer.
Here is a more in depth explanation of the question:

Let's imagine we have this rod: `0-0-0-0-0-0-0-0`, that is, a rod of length `n = 8`, this means we can split the rod into at most `n - 1` or 7, possible rods. Our task is to figure out how to split the rod so that we get the best price, because not each length is the same price. Suppose we're given a price sheet that looks like this:

```
1: $1
2: $5
3: $8
4: $9
5: $10
6: $17
7: $17
8: $20
```
That is, a rod of length 2 is worth $5. So given a rod of length 8 `0-0-0-0-0-0-0-0 = $20`, our best price would be to split it into a rod of length 6 `0-0-0-0-0-0 = $17` and another rod of length 2 `0-0 = $5`, for a total of $22 which is better then just selling the 8 length rod outright for $20.

We can think about this problem recursively, since for each link `-`, we can either split it there or keep the length. 

A naive solution might look something like this:

```cpp
int max_price(int rodlen, const std::vector<int> &prices) {
	if (rodlen == 0) return 0;
	
	int best_price = 0;
	
	for (int i = 0; i < rodlen; ++i) {
		best_price = std::max(best_price, prices[i] + max_price_exponential(rodlen - i - 1, prices));
	}
	
	return best_price;
}
```

If we think about the complexity, we are, at each step in the link `n - 1`, either cutting or keeping the length. So we can think of our rod as a bit string of 1's & 0's, a 0 for keeping and 1 for cutting. There are 2<sup>n</sup> possible ways to arrange the bit string, thus that's how many ways there are to cut a rod. 

This means our algorithm runs in exponential time, which is usually very, very slow. However, if we look closer out our recursion tree, we will see that we end up asking for the price of similar lengths.

```
                                         n=4
                                         /  \
                                        n=3 n=2
                                        /     \
                                       n=2    n=1
                                       /
                                      n=1
									
```

As you can see there is repeated work and calculations, thus this is a job for __Dynamic Programming__.

If we instead stored the optimal price each time we calculated a length, we could reduce the number of repeated computations we make. We can build a table, where each index is a length and the value at that index is the __best__ price for a rod of that length.

```cpp
int max_price(int rodlen, const std::vector<int> &prices) {
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
```

So given the code above we can compute the best price for a given rod in simple quadratic time! Which is, for most applications, faster than exponential time.

As you can see we slowly build the map of prices, starting at 0, since that is a base case we know, since a rod of length 0 = $0. So if we step through this for a couple of iterations we can see how it works:

```
computed = [ 0 ]
i = 1, j = 0
best_price = 0 or 1 + 0 = 1

computed = [ 0, 1 ] // Rod of length 1, best price = $1
i = 2, j = 0
best_price = 0 or 1 + 1 = 2
j = 1
best_price = 2 or 5 + 0 = 5

computed = [ 0, 1, 5 ] // Best price for rod of length 2 = $5
i = 3, j = 0
best_price = 0 or 1 + 5 = 5
j = 1
best_price = 5 or 5 + 1 = 6
j = 2
best_price = 6 or 8 + 0 = 8

computed = [ 0, 1, 5, 8 ] // Best price for rod of length 3 = $8
...
..
.
```

And this would continue until we reach a rod of length N, and we know our answer. The key to optimization here is that we are reducing our computations needed by remembering information.

For a live demo go [here](https://repl.it/@heyluis/rodCutting).

For a great video on this algorithm go [here](https://youtu.be/0y5UkZc-C8Y?t=5m).

