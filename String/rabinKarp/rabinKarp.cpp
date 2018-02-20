#include <string>
#include <iostream>
#include <cmath>

// Uses the Rabin-Karp algorithm to search for key in given string
int search(const std::string &str, const std::string &key) {
    constexpr int base = 128;
    constexpr int prime = 31;
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

int main() {
    std::string haystack = "This is a hasystack that contains a needle.";
    std::string needle = "needle";

    std::cout << "Index of needle: " << search(haystack, needle) << std::endl;
}
