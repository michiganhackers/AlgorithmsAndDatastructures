#include <iostream>
#include <string>

bool is_palindrome(const std::string &str) {
	unsigned b = 0;
	unsigned e = str.size() - 1;
	while (b < e) {
		if (str[b] != str[e]) return false;
		++b; --e;
	}
	
	return true;
}

int main() {
	std::cout << "Is \"racecar\" a palindrome: " 
				<< (is_palindrome("racecar") ? "true":"false") 
				<< std::endl; 
				
	std::cout << "Is \"abccba\" a palindrome: " 
				<< (is_palindrome("abccba") ? "true":"false") 
				<< std::endl; 
				
	std::cout << "Is \"nope\" a palindrome: " 
				<< (is_palindrome("nope") ? "true":"false") 
				<< std::endl; 
}