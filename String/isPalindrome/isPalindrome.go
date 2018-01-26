package main

import (
	"bytes"
	"fmt"
)

func isPalindrome(str string) bool {
	front := 0
	end := len(str) - 1
	for front < end {
		if str[front] != str[end] {
			return false
		}
		front++
		end--
	}
	return true
}

func main() {
	fmt.Printf(isPalindromePrint("racecar")) // true
	fmt.Printf(isPalindromePrint("abccba"))  // true
	fmt.Printf(isPalindromePrint("nope"))    // false
}

func isPalindromePrint(str string) string {
	var buffer bytes.Buffer
	buffer.WriteString(fmt.Sprintf("Is \"%s\" a palindrome: ", str))
	if isPalindrome(str) {
		buffer.WriteString("true")
	} else {
		buffer.WriteString("false")
	}
	buffer.WriteString("\n")
	return buffer.String()
}
