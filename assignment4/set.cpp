#include "set.h"

// Type used to create nodes of a binary search tree for our set
// implementation
// struct treenode {
// 	int value;
// 	treenode* left;
// 	treenode* right;

// 	treenode(int val)
// 		: value(val),
// 		  left(nullptr),
// 		  right(nullptr)
//    { }

// };

// This is a recursive helper function that should create and return an exact
// copy of the tree structure rooted at original
treenode* copynodes(treenode* original) {
	if(original == NULL) return NULL;	
	treenode *new_tree = new treenode(0);
	new_tree->value = original->value; 
	if(original->left) new_tree->left = copynodes(original->left);
	if(original->right) new_tree->right = copynodes(original->right);
	return new_tree;
}

// This is a recursive helper function that should deallocate all of the nodes
// in the tree structure rooted at node
void deallocatenodes(treenode* node) {
	if(node != nullptr) {
		if(node->left) deallocatenodes(node->left);
		if(node->right) deallocatenodes(node->right);
		delete node;
	}
}
	bool containshelper(treenode *cur, int val) {
		if(cur == nullptr) {
			return 0;
		}
		if(cur->value == val) return 1;
		bool left = false;
		bool right = false;
		if(val > cur->value) left = containshelper(cur->right, val);
		if(val < cur->value) right = containshelper(cur->left, val);
		return (left || right);
	}
	// Returns true if the value i is in the ordered set
	bool set::contains(int i) const {
		return containshelper(root, i);
	}
	
	// If the value i is not previously in the ordered set,
	// insert it preserving the ordering and return true;
	// Otherwise return false (indicating the value was already
	// in the set)
	
	bool inserthelper(treenode **cur, int val) {
		if((*cur) == nullptr) {
			treenode *new_node = new treenode(0);
			(*cur) = new_node;
			(*cur)->value = val;
			return 1;
		}
		if(val > (*cur)->value) inserthelper(&((*cur)->right), val);
		if(val < (*cur)->value) inserthelper(&((*cur)->left), val);
		return 1;
	}
	bool set::insert(int i) {
		if(contains(i)) return 0;
		++set_size;
		bool res = inserthelper(&root, i);
		return res;
	}
	// If the value i is in the ordered set, remove it and return true;
	// Otherwise return false (indicating the value was not in the set)
	//
	// WE WILL NOT IMPLEMENT THIS FOR THE ASSIGNMENT

	// Remove everything from the set
	void set::clear() {
		set_size = 0;
		deallocatenodes(root);
		root = nullptr;
	}

	// Returns the number of items in the set
	size_t set::size() const {
		return set_size;
	}

	// Returns whether or not the set is currently empty
	bool set::empty() const {
		return(set_size == 0);
	}


