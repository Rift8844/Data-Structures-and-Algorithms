
#include "avl_tree.hpp"

namespace mtl {
	struct Node;

	Node* avl_tree::insert(int val) {
		Node* newNode = new Node;
		newNode->value = val;

		if (root == nullptr) {
			root = newNode;
			return newNode;
		}

		Node* current = root;
		
		while (true) {
			if (newNode->value >= current->value) {
				if (current->daughter == nullptr) {
					current->daughter = newNode;
					newNode->parent = current;
					break;
				} else {
					current = current->daughter;
				}
			} else {
				if (current->son == nullptr) {
					current->son = newNode;
					newNode->parent = current;
					break;
				} else {
					current = current->son;
				}
			}
		}

		return updateBal(newNode);
	}

	/*The pointer the parent holds to access
	this node, either node->parent->son or
	node->parent->daughter*/
	Node*& Node::parents_ptr() {
		return parent->son == this ? parent->son : parent->daughter;
	}

	void avl_tree::rotRight(Node* node) {
		//pretty sure this is illegal...
		node->son->parent = node->parent;
		node->parents_ptr() = node->son;

		Node* newGrandson = node->son->daughter;

		node->son->daughter = node;
		node->parent = node->son;

		node->son = newGrandson;
		newGrandson->parent = node;
	}

	void avl_tree::rotLeft(Node* node) {
		node->daughter->parent = node->parent;
		node->parents_ptr() = node->daughter;

		Node* newGranddaughter = node->daughter->son;

		node->daughter->son = node;
		node->parent = node->daughter;

		node->daughter = newGranddaughter;
		newGranddaughter->parent = node;
	}

	//Only balances ascending nodes
	//I think this is broken now...
	Node* avl_tree::updateBal(Node* node) {

		//update balance factors for all ascending nodes
		while (node->parent != nullptr) {
			if (node == node->parent->daughter)
				node->parent->balance++;
			else
				node->parent->balance--;

			node = node->parent;
		}
	};

	Node::~Node() {
		if (daughter != nullptr)
			delete daughter;

		if (son != nullptr)
			delete son;

		return;
	}
}