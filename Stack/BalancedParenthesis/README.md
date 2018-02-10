## Balanced Parenthesis

### Time: O(n) ----------- Space: O(1) or O(n)

> Given a string of parenthesis that have either '(' or ')' parenthesis, determine whether or not the parenthesis are balanced. Balanced example: "(())", unbalanced example: "()("

This is really fun question since it's sort of programming related and you can even think of it as something practical since it can actually be used to determine if a line of code is valid or not!

The solution is rather simple and elegant. We can walk through each of the characters in the string one-by-one and store it in a stack, remember a stack is LIFO (last in, first out) data structure. Let's walk through an example

```
Given: "(())", read each character...

0: '('
1: '('
2: ')'
3: ')'
```

At first you might think that you can simply count the parenthesis and if, it's an even number, then we have a yes, otherwise no it's not balanced. But this idea doesn't take into account what each parenthesis means. The opening paren '(' means we MUST follow with ')' and the closing ')' means we must precede it with a '('. Using this idea we can take a stack and use it as follows, whenever we see an opening paren, we __push__ it into our stack as it starts a new "scope" and then when we see a closing paren we __pop__ from the stack, walking through the example above we can see this:


```
Given: "(())", read each character...

0: '(' push --> stack: ['(']
1: '(' push --> stack: ['(', '(']
2: ')' pop --> stack: ['(']
3: ')' pop --> stack: [ ]
```

Thus if our stack is empty we know we have a valid string! This however, takes __O(n)__ space in the worst case, example: "((((((((".

We can be clever and not use a stack at all, since really we only care about determining whether or not we are "empty".

We can use a counter, we increase when we see '(' and decrease when we see ')'

```
Given: "(())", read each character...

0: '(' inc --> i = 1
1: '(' inc --> i = 2
2: ')' dec --> i = 1
3: ')' dec --> i = 0
```

Thus if _i_ is 0 at the end, we know we are valid.

This question is fun because it can be extended further, for example, determine if this string is valid: __"{([])}"__, hint: it is.
We simply just need to account for more things, but the main idea holds, I'll leave this addition to the algorithm as a challenge to the reader.

Here is an implementation in C++:

```cpp
// O(n) space
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

// O(1) space
bool is_balanced2(const std::string &str) {
	std::string::size_type i = 0;
		
	for (char c : str) {
		switch (c) {
			case '(':
				++i;
				break;
			case ')':
				// Don't 'underflow'
				if (i == 0) return false;
				--i;
				break;
		}	
	}
	
	return i == 0;
}
```

Live demo can be found [here](https://repl.it/@heyluis/BalanceParenthesis).