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
	std::cout << "Hello mtl world!" << std::endl;

	mtl::DynamicArray<TestType> myArr;

	//Item 0
	myArr.push(TestType {0, "HELLO TEMPLATED WORLD!"});

	//Item 1
	myArr.push(TestType {1, "THREE BEDROOMS IN A GOOD NEIGHBORHOOD YAAHHHHHHHH!!!"});

	//Item 2
	myArr.insert(TestType {2, "I'M A GENIUS AHAHHAHAHHAHA"}, 0);

	for (int i = 0; i < myArr.getSize() - 1; i++) {
		std::cout << myArr.get(i) << std::endl;
	}

	return 0;
}