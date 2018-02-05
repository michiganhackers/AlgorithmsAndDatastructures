## reverseList

### Time O(n) ---- Space O(1)

> Given a singly linked-list, reverse the order and return a pointer to the head of the reversed list.


This a common question asked by interviewers to see if you understand how pointers work. There are several ways to go about doing this. A naive solution would be to create some other container, traverse through the list and add to the container as you go, this way you can access the pointers in random order and fix the references in reverse order. Here is an implementation of this naive solution.

```cpp
// This reverses the list as well but uses O(n) space, no bueno
Node * reverse_list_naive(Node *head) {
    if (!head) return nullptr;
	
    std::vector<Node *> vec;
	
    while (head) {
    	vec.push_back(head);
	head = head->next;
    }

    for (int i = vec.size() - 1; i > 0; --i) {
	vec[i]->next = vec[i - 1];
    }
    // Make old head the new tail
    vec[0]->next = nullptr;

   return vec.back();
}
```

This solution is pretty ugly and not very efficient as it not only requires linear space, but also requires two passes through the list. We can do this without any extra space and in one pass if we think about this more deeply.

If we think about a linked list, that looks like this:

```
(10) --> (30) --> (40) --> null
```

In order to reverse this using one pass we need to reverse at each node until we reach the end.

```
(30) --> (10) --> (40) --> null
(30) --> (40) --> (10) --> null
(40) --> (30) --> (10) --> null
```

Some things to keep in mind are that this is a single linked-list thus, you only have pointers to the next element in the list. You also need to make sure to have a valid list at the end. That is, the tail **must** point to null or else when we go to use the list again we will get undefined behavior.

We can accomplish this by keep 3 pointers. We need a pointer to the *previous* node in the list, the *current* node, and the *next* node in the list.

We then set the *current* nodes next pointer to equal whatever the *previous* node points to, and continue traversing by following the *next* pointer. Here the use of a temporary *next* pointer is **crucial** if we didn't use it, we'd have this behavior:

```cpp
current->next = previous;
current = current->next; // Bug!
```
The above would loop forever, since we are creating a circle, since we assign *current*'s next to be equal to previous we need some way to get back to next and not lose the pointer to it, this is why need to use a *next* temporary pointer.

Here is the above algorithm in code:

```cpp
// Reverses the list and returns a pointer to the new head
Node * reverse_list(Node *head) {
    // Edge case
    if (!head) return nullptr;
    
    Node *prev = nullptr;
    Node *curr = head;
    Node *next = nullptr;
    
    while (curr) {
    	next = curr->next;
	curr->next = prev;
	prev = curr;
	curr = next;
    }
    
    return prev;
}
```

We can walk through an example, using p = previous, c = current, n = next.

```
// 1st iteration
n = c.next

	(10) --> (30) --> (40) --> null
p    c        n

c.next = p
p = c

(10) --> null  
 c
 p
 
(30) --> (40) --> null
 n  

// 2nd iteration
n = c.next

(10) --> null  
 p
 
(30) --> (40) --> null
 c         n

c.next = p
p = c

(30) --> (10) --> null  
 c
 p         
  
(40) --> null
  n
  
// 3rd iteration  
n = c.next

(30) --> (10) --> null  
  p  
  
(40) --> null
  c       n

c.next = p
p = c

(40) --> (30) --> (10) --> null
 p
 
 c = null
 n = null       
```

As you can see, the previous pointer is now the head of our reversed list. So we can just return previous pointer and thats our algorithm!
For a live demo, visit [here](https://repl.it/@heyluis/reverseList)
