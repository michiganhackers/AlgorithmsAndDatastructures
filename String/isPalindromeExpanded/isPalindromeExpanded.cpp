#include <iostream>
#include <string>
#include <cctype>

bool is_palindrome(const std::string &str) {
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

int main() {
	std::cout << "Is \"racecar\" a palindrome: " 
				<< (is_palindrome("racecar") ? "true":"false") 
				<< std::endl; 

	std::cout << "Is \"Eva, Can I Stab Bats In A Cave?\" a palindrome: " 
				<< (is_palindrome("	Eva, Can I Stab Bats In A Cave?") ? "true":"false") 
				<< std::endl;
				
	std::cout << "Is \"Not a palindrome\" a palindrome: " 
				<< (is_palindrome("Not a palindrome") ? "true":"false") 
				<< std::endl; 
				
	// If we consider only alphabetic characters, then this is palindrome
	// since 'racecar' is the only thing here.
	std::cout << "Is \"r131221a353c31234//326e001-car\" a palindrome: " 
				<< (is_palindrome("r131221a353c31234//326e001-car") ? "true":"false") 
				<< std::endl; 
}