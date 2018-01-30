package main

import (
	"fmt"
	"unicode"
)

func isPalindromeExpanded(str string) bool {
	runes := []rune(str)
	front := 0
	back := len(runes) - 1
	for front < back {
		for !unicode.IsLetter(runes[front]) {
			front++
		}
		for !unicode.IsLetter(runes[back]) {
			back--
		}
		if unicode.ToLower(runes[front]) != unicode.ToLower(runes[back]) {
			return false
		}
		front++
		back--
	}
	return true
}

func main() {
	isPalindromePrint("racecar")                          // true
	isPalindromePrint("	Eva, Can I Stab Bats In A Cave?") // true
	isPalindromePrint("Not a palindrome")                 // false
	isPalindromePrint("r131221a353c31234//326e001-car")   // true
}

func isPalindromePrint(str string) {
	fmt.Printf("Is \"%s\" a palindrome: %t\n", str, isPalindromeExpanded(str))
}
