
#include "avl_tree.hpp"

namespace mtl {
	struct Node;

	Node* avl_tree::insert(int val) {
		Node* newNode = new Node;
		newNode->value = val;

		Node* current = root;
		
		while (true) {
		 	if (newNode->value >= current->value) {

				if (current->daughter == nullptr || 
					current->daughter->value >= newNode->value) {

				 	newNode->daughter = current->daughter;
				 	newNode->parent = current;
					current->daughter = newNode;

					break;
				}


				current = current->daughter;
			} else {
				if (current->son == nullptr || 
				current->son->value < newNode->value) {

					newNode->son = current->son;
					newNode->parent = current;
					current->son = newNode;

					break;
				}

				current = current->son;
			}
		}

		return updateBal(newNode);
	}

	//Only balances ascending nodes
	Node* avl_tree::updateBal(Node* node) {

		//update balance factors for all ascending nodes
		while (node != nullptr && node->parent != nullptr) {
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