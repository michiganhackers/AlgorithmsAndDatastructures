## isPalindromeExpanded
### Time: O(n) ----- Space: O(1)

This is an extension to the question answered [here](https://github.com/luispadron/AlgorithmsAndDatastructures/tree/master/String/isPalindrome).

This is another popular interview question asked by a lot of companies. It takes the _isPalindrome_ question and further expands upon it by making it a bit trickier. In the normal question you would be given input such as _"racecar"_ and asked to determine whether or not that is a palindrome, in this version you might be given something like _"Eva, Can I Stab Bats In A Cave?"_ which is also a palindrome.

The things to note here are:

1. Special characters such as _?_ and _,_ do not count when determining if something is a palindrome. 
2. Space doesn't count either
3. Upper and lower case characters are still equal, that is, `'E' == 'e'`

Using our old algorithm found [here](https://github.com/luispadron/AlgorithmsAndDatastructures/tree/master/String/isPalindrome), we can expand upon it by adding a few simple checks. We must skip over any character that is not an alphabetic character. We must also consider both the uppercase and lowercase versions of a character to be equal.

Here is an implementation of this algorithm in C++

```cpp
#include <iostream>
#include <string>
#include <cctype>

bool is_palindrome(const std::string &str) {
   if (str.size() == 0) return true;
   
   unsigned b = 0;
   unsigned e = str.size() - 1;
   while (b < e) {
       while (!isalpha(str[b]) && b < e) ++b;
       while (!isalpha(str[e]) && b < e)--e;
       if (tolower(str[b]) != tolower(str[e])) return false;
       ++b; --e;
   }
	return true;
}
```
Here we are using the standard libraries `isalpha` function which returns true if a character is an alphabetic character that is `Aa-Zz`. If the character is not alphabetic we want to skip it until it is. This must be done for both the begin and end characters, because once we check for equality, they must both be alphabetic. 

Next we check for equality between the begin and end indices of the given substring. We use the `tolower` method which just lowercases the given character since we do not want to consider casing.

Some caveats to consider when writing this algorithm:

1. When writing the inner while loops you need to make sure to check that `b < e` since the outer loop exits when `b < e`, so to should the inner. Otherwise you risk running off the end of the string.
2. Depending on the question you may be asked to consider special characters, or numbers, this is a simple modification to the algorithm, you may have to write some function which returns whether or not a character fits into the specifications given to you.

Measuring the time and space, we still have constant space or `O(1)` since we do not create copies of the string. We still have a `O(n)` but the constant is a bit bigger since we must perform more checks inside of the loop, however, do not be confused that there are multiple while loops. This does __not__ mean we have a quadratic complexity, since at most we will visit __n__ characters in the string.

For a live demo, go [here](https://repl.it/@heyluis/isPalindromeExpanded).





