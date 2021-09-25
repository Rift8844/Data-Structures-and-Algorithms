
#include <cstdlib>
#include <exception>


#pragma once

namespace mtl {
	//A funky nickname I thought of for a vector lmfao
	template <class T> class DynamicArray {
		int sz = 4;
		int idx = 0;

		T* ptr = new T[sz];

		void realloc(int newSz);
		void expand() { realloc(sz*2); }
		/*Maybe implement this
		later for fun*/
		//void shrink();

	public:
		/*Note: the actual size, the sz variable,
		is the amount of objects the current
		memory allocation can hold. The idx
		variable is the effective size, which is how
		many initialized objects lay in memory.*/
		int size() const { return idx + 1; }
		int capacity() const { return sz; }
		bool empty()  const { return idx == 0; }
		void shrinkToFit() { realloc(size()); }


		void pushBack(T val);
		T popBack();
		void insert(T val, int i);
		T erase(int i);
		void clear() { idx = 0; }

		T& operator[](int i) { return ptr[i]; }
		//Does this syntax work?
		T const& operator[](int i) const { return ptr[i]; }

		T get(int i);
		T const& get(int i) const;

		~DynamicArray() { delete[] ptr; }
	};
}
