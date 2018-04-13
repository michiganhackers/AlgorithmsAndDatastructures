## Algorithms and Datastructures

A repo for showing off cool and neat datastructures and algorithms.
Either for the purpose of getting better at interviewing or just to learn more.

This repo will contain detailed examples of implementations, as well as reasons for what makes a particular algorithm better than another, or the advantages/disadvantages of different approaches.

I plan for this repo to become a resource for learning about algorthims and datastructures in a particle but also fun way.

I want anyone to be able to contribute and add more interesting algorithms/data structures as the repo grows.
If you're interested in contributing, read the steps outlined [here](#contributing).

The code will be written using whatever language the writer prefers as the main purpose of this isn't about learning a specific programming language but about understanding the concepts behind the algorithms and data structures.

## Table of Contents

### String
- [Determine if string is a plaindrome](/String/isPalindrome)
- [Determine if string is a palindrome with special characters ](/String/isPalindromeExpanded)
- [Are parenthesis balanced](/Stack/BalancedParenthesis)
- [Rabin-Karp Algorithm](/String/rabinKarp)

### Sorting
- [Bubble sort](/Sorting/bubbleSort)
- [Selection sort](/Sorting/selectionSort)
- [Insertion sort](/Sorting/insertionSort)
- [Quick sort](/Sorting/quickSort)
- [Merge sort](/Sorting/mergeSort)
- [Heap sort](/Sorting/heapSort)

### Linked-List
- [Reverse a linked-list](/LinkedList/reverseList)

### Stack
- [Implement a stack using an array](/Stack/ArrayStack)
- [Are parenthesis balanced](/Stack/BalancedParenthesis)

### Graphs
- [Represent a graph using a matrix](/Graph/GraphMatrix)
- [Represent a graph using a list](/Graph/GraphList)

### Trees
- [Binary Search Tree](/Trees/BinarySearchTree)

### Dynamic Programming
- [Best price for rod](/DynamicProgramming/rodCutting)
- [Calculate Binomial Coefficient](/DynamicProgramming/binomialCoeff)
- [0-1 Knapsack](/DynamicProgramming/01Knapsack)

## Contributing

How do I contribute?

We want to keep this project simple, but also organized.
The way we plan to structure this repository is by having subdirectories of over-arching topics.
For example, we have a `String` folder, this folder will contain algorithms/data structures related to strings.
Each algorithm will be contained within it's own folder.

For example, if you were to add `isPalindrome` algorithm, this tends to be related to strings. Thus, you would first either create the `String` subfolder or if it's already there, skip this part. Then you would create a folder with the name of the algorithm __no__ space. That is we would have this folder structure: `String/isPalindrome/` inside of `isPalindrome` you would have the required two files, but you may have more. The two required files are `README.md`, and the source file which contains the code implementation.

_What do I put in the README?_

Simply put an explanation of the algorithm, pretend that the person reading it understands programming but has never seen/heard of the algorithm you are implementing. If you want to put a live demo as well you can share a link to a repl. Here is a good site for that: [Repl.it](https://repl.it).

Start the README with the name of the algorithm using header 2 `##` markdown style, and then underneath use header 3 `###` styling for the time/space complexity of the algorithm, if it's a datastructure you may feel free to skip the complexity calculation at the top. But you __must__ describe the complexity of each function in the data structure.

_What do I put in the source file?_

For this one you can feel free to use whatever language you prefer, as this repo is meant to be language agnostic and more about the actual topics. Just please make sure you have a working implementation that's been tested. Also, try to write your code in a readable manner.

__Just give me a checklist man, I hate reading...__

- [ ] Make sure directories are structured in a clean way, that is, `Topic/algorithm/` example: `String/isPalindrome/`
- [ ] Include a detailed README, take a loot at [this](/String/isPalindrome) for an example.
- [ ] Include a source file with neat code.
- [ ] Update this (main) README file with your changes, that is adding a link to the algorithm.
- [ ] Create a pull request so we can merge your changes!
