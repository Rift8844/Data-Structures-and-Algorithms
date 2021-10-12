
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

		current = newNode;
		//update balance factors for all ascending nodes
		while (current != nullptr && current->parent != nullptr) {
			if (current == current->parent->daughter)
				current->parent->balance++;
			else
				current->parent->balance--;

			current = current->parent;
		}

		return newNode;
	}

	//sNode* avl_tree::updateBal(Node* node) {};

	Node::~Node() {
		if (daughter != nullptr)
			delete daughter;

		if (son != nullptr)
			delete son;

		return;
	}
}