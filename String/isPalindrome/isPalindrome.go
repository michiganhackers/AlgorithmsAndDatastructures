package main

import (
	"fmt"
)

func isPalindrome(str string) bool {
	front := 0
	back := len(str) - 1
	for front < back {
		if str[front] != str[back] {
			return false
		}
		front++
		back--
	}
	return true
}

func main() {
	isPalindromePrint("racecar") // true
	isPalindromePrint("abccba")  // true
	isPalindromePrint("nope")    // false
}

func isPalindromePrint(str string) {
	fmt.Printf("Is \"%s\" a palindrome: %t\n", str, isPalindrome(str))
}
