package main

import "fmt"

func reverseVowels(s string) string {
	if len(s) <= 1 {
		return s
	}
	runes := []rune(s)
	front, back := 0, len(runes)-1
	for front < back {
		for !isVowel(runes[front]) {
			front++
		}
		for !isVowel(runes[back]) {
			back--
		}
		if front < back {
			temp := runes[front]
			runes[front] = runes[back]
			runes[back] = temp
			front++
			back--
		}
	}
	return string(runes)
}

func isVowel(r rune) bool {
	switch r {
	case 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U':
		return true
	}
	return false
}

func main() {
	reverseVowelsPrint("Hello")    // Holle
	reverseVowelsPrint("VOwEls")   // VEwOls
	reverseVowelsPrint("EECS 281") // EECS 281
}

func reverseVowelsPrint(s string) {
	fmt.Printf("Reverse vowels %s: %s\n", s, reverseVowels(s))
}
