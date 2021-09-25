#include "mtl.hpp"
#include <iostream>
#include <string>

struct Type {
	int x, y, z;
	std::string str;
};

int main() {
	std::cout << "Hello mtl world!" << std::endl;

	mtl::DynamicArray<Type> myObj;
	myObj.push({0, 1, 2, "HELLO TEMPLATED WORLD!"});
	myObj.push({1, 2, 999, "THREE BEDROOMS IN A GOOD NEIGHBORHOOD YAAHHHHHHHH!!!"});
	myObj.insert({3, 4, 5, "I'M A GENIUS AHAHHAHAHHAHA"}, 0);

	std::cout << myObj[0].str << std::endl;

	return 0;
}