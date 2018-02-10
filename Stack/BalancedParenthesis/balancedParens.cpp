#include <iostream>
#include <stack>
#include <string>

bool is_balanced(const std::string &str) {
	std::stack<char> stack;
	
	for (char c : str) {
		switch (c) {
			case '(':
				stack.push(c);
				break;
			case ')':
				// Don't pop from empty stack
				if (stack.empty()) return false;
				stack.pop();
				break;
		}	
	}
	
	return stack.size() == 0;
}

bool is_balanced2(const std::string &str) {
	std::string::size_type i = 0;
		
	for (char c : str) {
		switch (c) {
			case '(':
				++i;
				break;
			case ')':
				// Don't underflow
				if (i == 0) return false;
				--i;
				break;
		}	
	}
	
	return i == 0;
}

int main() {
	std::cout << "Testing is_balanced:\n";
	std::cout << "Is '()' balanced?: " << (is_balanced("()") ? "true" : "false") << std::endl;
	std::cout << "Is '(()' balanced?: " << (is_balanced("(()") ? "true" : "false") << std::endl;
	std::cout << "Is '((test))' balanced?: " << (is_balanced("(())") ? "true" : "false") << std::endl;
	std::cout << "Is '(()))' balanced?: " << (is_balanced("(()))") ? "true" : "false") << std::endl;
	
	std::cout << "\nTesting is_balanced2:\n";
	std::cout << "Is '()' balanced?: " << (is_balanced2("()") ? "true" : "false") << std::endl;
	std::cout << "Is '(()' balanced?: " << (is_balanced2("(()") ? "true" : "false") << std::endl;
	std::cout << "Is '((test))' balanced?: " << (is_balanced2("(())") ? "true" : "false") << std::endl;
	std::cout << "Is '(()))' balanced?: " << (is_balanced2("(()))") ? "true" : "false") << std::endl;
}