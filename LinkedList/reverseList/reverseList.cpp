#include <iostream>
#include <vector>

// Node object
struct Node {
	int data;
	Node *next;
};


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

void print_list(Node *head) {
	while (head->next) {
		std::cout << head->data << "-";
		head = head->next;
	}
	std::cout << head->data << std::endl;
}


int main() {
	// Create test list
	Node *n3 = new Node({56, nullptr});
	Node *n2 = new Node({40, n3});
	Node *n1 = new Node({30, n2});
	Node *h = new Node({10, n1});
	
	std::cout << "Before reversal: " << std::endl;
	print_list(h);
	
	std::cout << "After reversal: " << std::endl;
 	Node *new_head = reverse_list(h);
 	print_list(new_head);
}