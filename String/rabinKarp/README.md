## Rabin-Karp String Search
### Time: O(n) ---- Space: O(1)

The Rabin-Karp algorithm is a very interesting algorithm for finding a substring in a string.
This is popularized by the problem of finding a needle in a haystack. Given some key, how can we efficientaly find
if the key is in the given string.

An obvious solution to this would be to search through each character in the given string (haystack) and
for each character iterate through each character in the needle to see if they match.

For example given the haystack: "This is a haystack", and the needle: "is", the naive solution works like this:

```
This is a haystack
^

is
^

The characters don't match so you continue with the haystack

This is a haystack
 ^

is
^

Again, they don't match

This is a haystack
  ^

is
^

We have an initial match, thus we now iterate BOTH the haystack and need

This is a haystack
   ^

is
 ^

And here we find the needle since we have exhausted our enedle and all characters were found.
```

Some things to note, is that we look for the first occourence of needle, which is why it'll return the "is" in
"This" as opposed to the lone "is". While this example worked out fairly quickly, what if we were given:
"aaaaaaaaaaaaaaaaaab" as a haystack and "aaaab" as a needle, here at every position we would iterate through both
the needle and the haystack without much luck up until the very last 4 "a"'s where we find an absolute match. Thus,
this naive solution is O(n * m) where n is the size of the haystack and m is the size of the needle.

The Rabin-Karp solution works much faster by doing something known as string finger printing. We can take the string
"aaaaaab" and figure out an integer value for it. We usually get the value from its ASCI code times some _2^n_ base
and finally modulo some prime number, to save us from overflows. This gives a fairly unique string fingerprint.
Which allows us to, instead of comparing linearly all the characters in both needle and haystack, just compare two numbers
which is a constant time operation.

An example of how this work is shown below:

```
haystack = "This is a haystack"
needle  = "is"

Let's assume the fingerprint for needle gave us a value of 36 for the finger print of "is"
we then finger print the first two characters in our haystack and get a finger print of 20, for example.

This is a haystack
^^
20 != 36

Since our haystack finger print doesn't equal our needle finger print we subtract the value of the first character 'T'
from the 20 finger print and add the next character 'i', and lets say we now get 29

This is a haystack
 ^^
 29 != 36

Again, this doesnt equal 36, so we do the same, and calculate the new finger print by doing a constant time
operation of subtracting and adding thus we now have the finger print for "is" which will return the same thing always,
thus it returns 36 for our haystack finger print

This is a haystack
  ^^ 36 == 36

Thus we found a match, however, we're not done yet, we now need to iterate through both the "is" and needle ("is")
to verify we have the exact same characters since we could've had a collision when finger printing (same value given to different strings)
In this case we dont, so we're good and have found our needle!
```

The Rabin-Karp takes us from an O(n * m) solution to a O(n) solution where n is the size of the haystack.

An example implementation is shown in C++ below:

```cpp
// Uses the Rabin-Karp algorithm to search for key in given string
int search(const std::string &str, const std::string &key) {
    constexpr int base = 128;
    constexpr int prime = 181;
    const long long z = static_cast<long long>(std::pow(base, key.size() - 1)) % prime;

    // Get finger prints of key
    long fp_str = 0, fp_key = 0;
    for (int i = 0; i < key.size(); ++i) {
        fp_str = (base * fp_str + str[i]) % prime;
        fp_key = (base * fp_key + key[i]) % prime;
    }

    for (int i = 0; i <= str.size() - key.size(); ++i) {
        if (fp_str == fp_key) {
            // Make sure actualy valid strings, (i.e no collisions)
            int j = 0;
            for (; j < key.size(); ++j) {
                if (str[i + j] != key[j])
                    break;
            }

            if (j == key.size())
                return i;
        }

        if (i < str.size() - key.size()) {
            // Calculate the new finger print, by removing the 0th character
            // and adding the next character
            fp_str = (base * (fp_str - str[i] * z) + str[i + key.size()]) % prime;
            // Handle negatives
            if (fp_str < 0) fp_str = (fp_str + prime);
        }
    }
    // Not found
    return -1;
}
```

For a live demo, visit [here](https://repl.it/@heyluis/Rabin-Karp-Search)
