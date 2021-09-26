#include "mtl.hpp"
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
	mtl::DynamicArray<TestType> myArr;

	myArr.pushBack({-1, "I shouldn't be printed"});
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
	}


	return 0;
}