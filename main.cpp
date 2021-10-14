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

int main() {
	mtl::dynamic_array<TestType> myArr;
	//mtl::stupid_ptr<int> horrendousMess(new int[64], 64);
	mtl::avl_tree tree;

	tree.root->value = 10;
	tree.insert(9);
	tree.insert(7);
	tree.insert(5);
	//This will make the tree unbalanced
	tree.insert(12);
	tree.insert(13);
	tree.insert(19);

	//Print out all nodes
	mtl::Node* current = tree.root;

	//Expected output: 5, 7, 9, 10, 12, 13, 19

	while (current->son != nullptr) {
		current = current->son;
	}

	while(current->parent != nullptr) {
		std::cout << "Node value: " << current->value <<
		"\nNode balance: " << (int) current->balance << std::endl;
		current = current->parent;
	}


	current = tree.root;
	while (current != nullptr) {
		std::cout << "Node value: " << current->value <<
		"\nNode balance: " << (int) current->balance << std::endl;

		current = current->daughter;
	}

	

	/*myArr.pushBack({-1, "I shouldn't be printed"});
	myArr.pushBack({-1, "Nor should I"});
	myArr.clear();

	myArr.pushBack({0, "Print test one"});
	myArr.insert({1, "Print test two"}, 0);

	myArr.pushBack({-1, "I shouldn't be printed"});
	myArr.popBack();
	myArr.pushBack({-1, "Me neither"});
	myArr.erase(myArr.size() - 1);

	myArr.pushBack({2, "Test"});
	myArr.shrinkToFit();

	for (int i = 0; i < myArr.size() - 1; i++) {
		std::cout << myArr.get(i) << std::endl;
	}*/

	return 0;
}