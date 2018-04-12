## Binary Search Tree

| Function | Best | Average  | Worst |
|----------|------|----------|-------|
| insert   | O(1) | O(log n) | O(n)  |
| find     | O(1) | O(log n) | O(n)  |
| remove   | O(1) | O(log n) | O(n)  |

Binary search trees are a common data structure used for a lot of purposes. For example, the C++ standard library uses binary search trees, or BSTs for their `std::map` container.

Binary search trees are nice because they're a specialization on a normal binary tree which allows for faster average times. A normal binary tree, specifies that each internal node may have at most 2 children. A binary _search_ tree specifies that each internal node's left child must be *less* than itself and each internal node's right child must be *greater than or equal* to itself. 

This special property of the BST allows us to quickly find a given node since at each sub-tree we can cut our search path in half since we know in which side of the tree the search node must lie in. This is similar to how binary search works, hence the name.

However, a binary search tree by itself still has linear O(n) worst time complexity for the common operations. This is due to the fact that the tree may not stay balanced and can become a stick structure, which basically just ends up becoming a linked list.

```
Insert 10 20 30 40 in that order

		10   // insert 20 to the right of 10 since >
		   \ 
		    20 // insert 30 to the right of 20 since >
		      \
		       30 // etc.. 
		         \
		          40 // ..... and we have a linked list!
```

Here is an implementation of a Binary Search Tree in C++:

```cpp
#include <iostream>
#include <cassert>

template<class T>
class BinarySearchTree {
private:
    struct Node {

        Node(T data) : left{}, right{}, datum{data} { }

        Node *left;
        Node *right;
        T datum;
    };

public:
    using size_type = size_t;


    BinarySearchTree() : root{}, sz{0} { }

    // Inserts the given data into the tree.
    // MODIFIES: this
    void insert(const T &data) {
        insert_node(new Node(data), root);
        ++sz;
    }

    // Returns whether or not a given data value exists in the tree
    bool exists(const T &data) const {
        return exists_helper(data, root);
    }

    // Removes the first node with the given data
    // MODIFIES: this
    void remove(const T &data) {
        assert(sz > 0);

        remove_helper(data, root);
        --sz;
    }

    // Returns the size of the tree
    size_type size() const {
        return sz;
    }

    // Does a pre-order print of the tree
    void pre_order_print() const {
    	std::cout << "Pre-order Tree:\n";
    	pre_order(root, [] (const T &data) {
    		std::cout << data << " ";
    	});
    	std::cout << "\n";
    }

    void in_order_print() const {
    	std::cout << "In-order Tree:\n";
    	in_order(root, [] (const T &data) {
    		std::cout << data << " ";
    	});
    	std::cout << "\n";
    }

private:
    Node *root;

    size_type sz;

    // Recursively inserts a given node starting at the given root
    static void insert_node(Node *n, Node *&root) {
        if (!root)
            root = n;
        else if (n->datum < root->datum)
            insert_node(n, root->left);
        else
            insert_node(n, root->right);
    }

    // Recursively searches the tree, starting at the given root,
    // for the given item. Returns true if found, false otherwise.
    static bool exists_helper(const T &data, const Node *root) {
        if (!root)
            return false;
        else if (data < root->datum)
            return exists_helper(data, root->left);
        else if (data > root->datum)
            return exists_helper(data, root->right);
        else
            return true;
    }

    // Removes the first node with given data, rooted at root
    static void remove_helper(const T &data, Node *&root) {
        if (!root) return;

        if (data < root->datum)
            remove_helper(data, root->left);
        else if (data > root->datum)
            remove_helper(data, root->right);
        else if (data == root->datum) {
            if (!root->left) {
                root = root->right;
                delete root;
            } else if (!root->right) {
                root = root->left;
                delete root;
            } else {
                // Use inorder successor since the node were
                // deleting has two children
                const Node *successor = inorder_successor(root);
                // Swap successor with node were deleting
                root->datum = successor->datum;
                // Delete 'successor' duplicate since we swapped it
                remove_helper(successor->datum, root->right);
            }
        }
    }

    // Returns the inorder successor rooted at the given node
    static const Node * inorder_successor(const Node *root) {
        if (!root) return nullptr;
        if (!root->right) return nullptr;

        root = root->right;
        while (root->left)
            root = root->left;

        return root;
    }

    // Does a pre-order traversal and performs a given action on nodes
    template<typename Action>
    static void pre_order(const Node *node, const Action &action) {
    	if (!node) return;

    	action(node->datum);
    	pre_order(node->left, action);
    	pre_order(node->right, action);
    }

    // Does in-order traversal and performs given action on nodes
    template<typename Action>
    static void in_order(const Node *node, const Action &action) {
    	if (!node) return;

    	in_order(node->left, action);
    	action(node->datum);
    	in_order(node->right, action);
    }

    // Does a post-order traversal and performs action on nodes
    template<typename Action>
    static void post_order(const Node *node, const Action &action) {
        if (!node) return;

        post_order(node->left, action);
        post_order(node->right, action);
        action(node->datum);
    }
};

```

For a live demo go [here](https://repl.it/@heyluis/BinarySearchTree).