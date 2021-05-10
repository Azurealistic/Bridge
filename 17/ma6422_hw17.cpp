/*
INSTRUCTIONS
In this assignment, it is required that you fill out areas under comments labeled as "TODO" appropriately based on the accompanying directions. 
You are also required to follow any directions accompanying comments such as "NOTE".
You can add/modify code anywhere, with the exception of the provided "main" (which we will use for testing).
You can use the constants RED and BLACK, instead of the ints 0 and 1, when appropriate.
*/

#include <iostream>
#include <cmath>
#include <cassert>
#include <queue>

using namespace std;

#define RED 0
#define BLACK 1

template <class T>
class RBT;

// swapColor swaps the color from red to black and vice versa
int swapColor(int c) {
    return (c == 0) ? 1 : 0;
}

template <class T>
class RBTNode {
private:
    RBTNode<T> *parent, *left, *right;
    T data;
    int color;

public:
    RBTNode(T data) : data(data), color(RED), parent(nullptr), left(nullptr), right(nullptr) {}
    friend class RBT<T>;
    void prettyPrint(int indent) const;

    template <class T1>
    friend void swapColor(RBTNode<T1> *);
    template <class T1>
    friend int getColor(RBTNode<T1> *);

    int height() const;
};

template <class T>
int RBTNode<T>::height() const {
    int left_h = 0;
    if (left != nullptr) {
        left_h = left->height();
    }
    int right_h = 0;
    if (right != nullptr) {
        right_h = right->height();
    }
    return 1 + max(left_h, right_h);
}

template <class T>
void RBTNode<T>::prettyPrint(int indent) const {
    if (right != nullptr) {
        right->prettyPrint(indent + 1);
    }
    int margin = indent * 2;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "DATA: " << data << endl;
    for (int i = 0; i < margin; ++i) {
        cout << '\t';
    }
    cout << "COLOR: " << (color == RED ? "RED" : "BLACK") << endl;
    if (left != nullptr) {
        left->prettyPrint(indent + 1);
    }
}

template <class T>
void swapColor(RBTNode<T> *node) {
    if (node != nullptr) {
        node->color = swapColor(node->color);
    }
}

// getColor handles null nodes
template <class T>
int getColor(RBTNode<T> *node) {
    if (node != nullptr) {
        return node->color;
    }
    return BLACK;
}

template <class T>
class RBT {
private:
    RBTNode<T> *root;
    void rotateLeft(RBTNode<T> *&point);
    void rotateRight(RBTNode<T> *&point);

public:
    RBT() : root(nullptr) {}

    void insert(const T &);
    void insert(const T &, RBTNode<T> *&point, RBTNode<T> *parent);
    void prettyPrint() const { root->prettyPrint(0); }

    int height() const { return root->height(); }
};

// Ended up re-writing these slightly based on how I ended up using them.
// Not using the initially written grandparent/parent pointers that were here.
// Instead using my own/different pointers essentially.
template <class T>
void RBT<T>::rotateLeft(RBTNode<T> *&point) {
	// Preserve this pointer.
    RBTNode<T> *right_ptr = point->right;
	point->right = right_ptr->left; // Reassign the original point->right.
	if(point->right != nullptr) {
		point->right->parent = point; // Fix the child/parent pointer relationship.
	}
	right_ptr->parent = point->parent; // Set the old right pointer's parent to our current points parent.
	if(point->parent == nullptr) {
		root = right_ptr;
	} else if(point == point->parent->left) {
		point->parent->left = right_ptr;
	} else {
		point->parent->right = right_ptr;
	}
	right_ptr->left = point;
	point->parent = right_ptr;
}

// Mirror of rotateLeft
template <class T>
void RBT<T>::rotateRight(RBTNode<T> *&point) {
    RBTNode<T> *left_ptr = point->left;
	point->left = left_ptr->right; 
	if(point->left != nullptr) {
		point->left->parent = point; 
	}
	left_ptr->parent = point->parent; 
	if(point->parent == nullptr) {
		root = left_ptr;
	} else if(point == point->parent->left) {
		point->parent->left = left_ptr;
	} else {
		point->parent->right = left_ptr;
	}
	left_ptr->right = point;
	point->parent = left_ptr;
}

template <class T>
void RBT<T>::insert(const T &toInsert, RBTNode<T> *&point, RBTNode<T> *parent) {
    if (point == nullptr) { // See if the location we are at is null-ptr, if it is, insert in this specific location.               
        point = new RBTNode<T>(toInsert); // By default the constructor for the Node function marked this node as RED.                            
        point->parent = parent;
        RBTNode<T> *curr_node = point; 

		// Helper pointers to keep track of various nodes/locations within the tree.
		RBTNode<T> *parent_ptr = nullptr;
		RBTNode<T> *grandparent_ptr = nullptr;

        // -------------------------------------------------------------------- //
        // Check to see if this newly inserted node was the root node of the tree?
        if(curr_node->parent == nullptr) {
            swapColor(curr_node); // If it is, we swap the colour to black.
        }

		// In this section we account for the various rules we have to process and work through.
		// We need to keep looping through this until the current node is either root, the curr_node is RED or the parent node is black.
		while(curr_node != root && curr_node->color != BLACK && curr_node->parent->color == RED) {
			// We can now assign the pointers for the parent and grandparent.
			parent_ptr = curr_node->parent;
			grandparent_ptr = parent_ptr->parent;
			// Now there are 5 cases, 1 that requires recolouring, and 4 that require rotations.
			// However it might be easier to split it up such that we base this structure on the fact where our parent_ptr is compared to the grandparent_ptr.
			if(parent_ptr == grandparent_ptr->left) { // Our parent_ptr can be either the left or the right child of the grandparent.
				// Assign another pointer that makes it easier on us.
				RBTNode<T> *uncle_ptr = grandparent_ptr->right; // Opposite of parent!
				// Now we check for the recolouring case where uncle is red (but not a nullptr)!
				// During recolouring we need to do the following:
				// 1. Mark both the parent and uncle node as black.
				// 2. Mark grandparent as red.
				// 3. Set current to grandparent, and then loop starts over from that point on!
				if(uncle_ptr != nullptr && uncle_ptr->color == RED) {
					// We can use the swap colour function cause we know what the colour of each node will be already!
					swapColor(grandparent_ptr);
					swapColor(parent_ptr);
					swapColor(uncle_ptr);
					curr_node = grandparent_ptr;
				} else {
					// We have to now handle the two rotation cases that may be possible.
					// One is going to be a single rotation, and the other is going to be a double rotation!
					// It might just be easier to write this in terms of only using the rotateRight & rotateLeft functions however.
					// Reasoning being that it is much much easier to handle the extra work that may be needed between & post rotation.
					// That being said let's begin:
					// In this first case, if the curr_node is the parent's right child, we need to rotate left. Which would be CCR rotation.
					if(curr_node == parent_ptr->right) {
						rotateLeft(parent_ptr);
						// After we rotate we need to just reassign our relative pointers to make sure future rotations are correct.
						curr_node = parent_ptr;
						parent_ptr = curr_node->parent; // We actually can't assume this is the grandparent_ptr, due to the rotation above.
					}

					// This will always run, and is under the assumption that curr_node is left child of parent_ptr.
					// Doing it this way allows us to do both the left-left and the left-right cases.
					rotateRight(grandparent_ptr);
					// These colours need to be swapped from what they were before for rebalancing purposes.
					swapColor(grandparent_ptr);
					swapColor(parent_ptr);
					curr_node = parent_ptr; // Go up another level.
				}
			} else {
				RBTNode<T> *uncle_ptr = grandparent_ptr->left; // Opposite of parent!
				// Now we check for the recolouring case where uncle is red (but not a nullptr)! (Same as above!)
				// I realize this is duplicated logic, but it was the best way I could come up with.
				if(uncle_ptr != nullptr && uncle_ptr->color == RED) {
					swapColor(grandparent_ptr);
					swapColor(parent_ptr);
					swapColor(uncle_ptr);
					curr_node = grandparent_ptr;
				} else {
					// Similar concept to above! But essentially flipped in it's rotation order/rules.
					if(curr_node == parent_ptr->left) {
						rotateRight(parent_ptr);
						curr_node = parent_ptr;
						parent_ptr = curr_node->parent;
					} 
					rotateLeft(grandparent_ptr);
					swapColor(grandparent_ptr);
					swapColor(parent_ptr);
					curr_node = parent_ptr; 
				}
			}
		}
		root->color = BLACK;
        // -------------------------------------------------------------------- //
    } else if (toInsert < point->data) { 
        insert(toInsert, point->left, point); // Go down the left side of the tree to find spot to insert.
    } else { 
        insert(toInsert, point->right, point); // Go down the right side of the tree to find spot to insert.
    }
}

template <class T>
void RBT<T>::insert(const T &toInsert) {
    insert(toInsert, root, nullptr);
}

// NOTE: DO NOT MODIFY THE MAIN FUNCTION BELOW
int main() {
    RBT<int> b;
    int count = 10;
    for (int i = 0; i < count; i++) {
        b.insert(i);
    }
    b.prettyPrint();
    /* EXPECTED OUTPUT:
                                                                    Data: 9
                                                                    COLOR: RED
                                                    Data: 8
                                                    COLOR: BLACK
                                    Data: 7
                                    COLOR: RED
                                                    Data: 6
                                                    COLOR: BLACK
                    Data: 5
                    COLOR: BLACK
                                    Data: 4
                                    COLOR: BLACK
    Data: 3
    COLOR: BLACK
                                    Data: 2
                                    COLOR: BLACK
                    Data: 1
                    COLOR: BLACK
                                    Data: 0
                                    COLOR: BLACK
    */

    // TEST
    // the below tests the validity of the height of the RBT
    // if the assertion fails, then your tree does not properly self-balance
    int height = b.height();
    assert(height <= 2 * log2(count));
}