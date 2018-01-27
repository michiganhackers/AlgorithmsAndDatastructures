#include <iostream>
#include <string>

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

int main() {
  std::cout << "Reverse vowels 'Hello': " << reverse_vowels("Hello") << std::endl;
  std::cout << "Reverse vowels 'VOwEls': " << reverse_vowels("VOwEls") << std::endl;
  std::cout << "Reverse vowels: 'EECS 281': " << reverse_vowels("EECS 281") << std::endl;
}