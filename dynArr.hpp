
#include <cstdlib>
#include <exception>


#pragma once

namespace mtl {
	//A funky nickname I thought of for a vector lmfao
	template <class T> class DynamicArray {
		int sz = 4;
		int idx = 0;

		T* ptr = new T[sz];

		void expand();
		/*Maybe implement this
		later for fun*/
		//void shrink();

	public:
		/*Note: the actual size, the sz variable,
		is the amount of objects the current
		memory allocation can hold. The idx
		variable is the effective size, which is how
		many initialized objects lay in memory.*/
		int getSize() const { return idx + 1; };

		void push(T val);
		T pop();
		void insert(T val, int i);

		T& operator[](int i) { return ptr[i]; }
		//Does this syntax work?
		T const& operator[](int i) const { return ptr[i]; }

		T get(int i);
		//T const& get(int i) const;

	};
}
