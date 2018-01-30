package main

import (
	"bytes"
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
	fmt.Printf(isPalindromePrint("racecar"))                          // true
	fmt.Printf(isPalindromePrint("	Eva, Can I Stab Bats In A Cave?")) // true
	fmt.Printf(isPalindromePrint("Not a palindrome"))                 // false
	fmt.Printf(isPalindromePrint("r131221a353c31234//326e001-car"))   // true
}

func isPalindromePrint(str string) string {
	var buffer bytes.Buffer
	buffer.WriteString(fmt.Sprintf("Is \"%s\" a palindrome: ", str))
	if isPalindromeExpanded(str) {
		buffer.WriteString("true")
	} else {
		buffer.WriteString("false")
	}
	buffer.WriteString("\n")
	return buffer.String()
}
