#include "mtl.hpp"
#include <vector>
#include <iostream>
#include <string>

struct TestType {
	int itemNo;
	std::string str;
};

std::ostream& operator<<(std::ostream& os, TestType const& tt) {
	return os << "Item no: " << tt.itemNo <<
	"\nItem content: " << tt.str;
}


void printRecursive(mtl::Node* node) {
	if (node->son != nullptr)
		printRecursive(node->son);

	if (node->daughter != nullptr)
		printRecursive(node->daughter);

	std::cout << "Node val: " << node->value <<
	"\nNode balance: " << (int) node->balance << '\n' << std::endl;
}

int main() {
	mtl::dynamic_array<TestType> myArr;
	//mtl::stupid_ptr<int> horrendousMess(new int[64], 64);
	mtl::avl_tree tree;

	tree.insert(20);
	tree.insert(15);
	tree.insert(25);
	tree.insert(10);
	tree.insert(7);
	tree.insert(18);
	tree.insert(12);
	tree.insert(11);


	//Expected output: 5, 7, 9, 10, 12, 13, 19

	printRecursive(tree.root);

	/*while (current->son != nullptr) {
		current = current->son;
	}

	while(current->parent != nullptr) {
		std::cout << "Node value: " << current->value <<
		"\nNode balance: " << (int) current->balance << '\n' << std::endl;
		current = current->parent;
	}


	current = tree.root;
	while (current != nullptr) {
		std::cout << "Node value: " << current->value <<
		"\nNode balance: " << (int) current->balance << '\n' << std::endl;

		current = current->daughter;
	}*/

	return 0;
}