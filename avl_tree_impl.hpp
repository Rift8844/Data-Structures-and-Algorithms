
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
					current->daughter = newNode;

					return  newNode;
				}


				current = current->daughter;
			} else {
				if (current->son == nullptr || 
				current->son->value < newNode->value) {

					newNode->son = current->son;
					current->son = newNode;

					return newNode;
				}

				current = current->son;
			}

			//updateBal();
		}
	}

	Node* avl_tree::updateBal(Node* node) {};

	Node::~Node() {
		if (daughter != nullptr)
			delete daughter;

		if (son != nullptr)
			delete son;

		return;
	}
}