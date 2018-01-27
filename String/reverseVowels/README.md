## reverseVowels

### Time: O(n) ---- Space: O(1)

This is another common interview question. The questions asks:

> Given a string, _str_, reverse only the vowels of the string.

That is, if you are given __"hello"__, you should return __"holle"__. Since the only vowels are e and o, thus you swap them.

This algorithm can be written fairly easily if you consider a few things.

1. Know your vowels, that is, __AEIOU__ and __aeiou__.
2. When you reverse you are technically swapping, consider the example of "hello", we swapped the _e_ and _o_. If there were anymore vowels we would continue through the string and swapping __without__ considering the already swapped _e_ and _o_.
3. When we swap once we don't consider those characters anymore.
4. If you've ever implemented a reverse string function, think back to that but just now only consider vowels.

So we can start with two pointers, or indices, one to the front of the string and one to back of the string.
Let's think about a string as an array of characters to make this explanation easier:


```cpp
['h',  'e',  'l',  'l',  'o']
  ^                       ^
```

We can then, using our two pointers, look for any two vowels in that range, the range between the first and end pointers.

So starting from the first pointer we scan until we find a vowel:

```cpp
['h',  'e',  'l',  'l',  'o']
        ^                 ^
```
And it's found at the 2nd character.

Now scanning _from_ the end of the string we look again for another vowel:

```cpp
['h',  'e',  'l',  'l',  'o']
        ^                 ^
```

It's found immediately at the current position of end.

We now swap these two characters:

```cpp
['h',  'o',  'l',  'l',  'e']
        ^                 ^
```

We continue the process again, first with the begin pointer, __however__ we must decrease our range this time.
We do not want to check starting at the current position, or else we would never move since it would find the vowel instantly.
We need to check from [begin + 1, size]

```cpp
['h',  'o',  'l',  'l',  'e']
                          ^
                          ^
```

You'll notice now that begin index now points at the same vowel as end, we'll see why this matters below.

We then try with the end pointer to find a vowel, __however__ like above, we must first only consider from [0, end - 1] since we do not want to find the character we currently are pointing at.


```cpp
['h',  'o',  'l',  'l',  'e']
        ^                 ^
        e                 b
```

As you can see end now points to o, and begin now points to e, if we were to swap them again this would loop forever! Thus our exit condition can be found when end index is less than or equal to begin index! Since that would mean we are out of vowels in the range we're looking for.

We can write this in C++ and take advantage of the standard library, however, if you aren't using C++ or are allowed to use the STL, you can simply write a quick method to find the first/last of a given character.

```cpp
std::string reverse_vowels(std::string str) {
	if (str.size() == 0) return str; // Edge case since we are using size_type (unsigned)
	
	typedef std::string::size_type str_size;
	str_size i = 0;
	str_size j = str.size() - 1;
	
	while (i < j) {
		i = str.find_first_of("aeiouAEIOU", i);
		j = str.find_last_of("aeiouAEIOU", j);
		// Make sure we swap from left to right only
		if (i < j) {
			char temp = str[i];
			str[i] = str[j];
			str[j] = temp;
			++i; ++j;
		}
	}
	
	return str;
}
```

Let's think about the complexity of this, because at first glance it may not seem linear.

As seen in the example above we traverse the given string with two pointers, from begin to end. We stop when begin is greater than or equal to end. Thus, our outer while loop (not considering anything else) will run for at most `roof(n/2)` operations, if all we do is increase and decrease the begin and end indices respectively. 

If you notice the function `find_first_of` and `find_last_of`, these functions take string of characters and a start/end index respectively. Thus given `"hello".find_first_of("aeiou", 0);` it returns `e`, given `"hello".find_last_of("aeiou", 4);` it returns `o`. This is a linear time function, with respect to the characters in the given string, since it would at most need to look through the whole string.

Thus you might be tempted to say that this algorithm is `n/2 * n`, but the crucial line is that i and j are set to whatever the function returns. That is, we increase i and j, to be the index of the next found vowel. So it would follow the exact algorithm we saw in the demonstration above which at most visited each character twice, or `2n`, which in terms of big-oh, is just `O(n)`. 

For the space complexity, this is constant or `O(1)` if we don't consider the input (passed by value), this algorithm could also work with a reference or pointer to a string, I used value to make it easier to understand and use in the demo.

__Lingering question:__ What about the time to check each character in the string for "aeiouAEIOU"?

Since we are talking about `O(n)` where `n` is the size of the given string, then we know for a fact that for any given string, even if it has 1 million characters. We know that "aeiouAEIOU" does not change. That is, they're constant and independent of input size, thus would not factor into time complexity. They do matter in practice since at every character in the string we must check if it one of "aeiouAEIOU", however, for big-oh analysis this would just amount to another extra constant factor in front of the `n`.

Check out a live demo [here](https://repl.it/@heyluis/reverseVowels).
