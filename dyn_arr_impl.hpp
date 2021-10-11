
#include "dyn_arr.hpp"

namespace mtl {
	template <typename T> T const& dynamic_array<T>::get(int i) const {
		if (i > idx)
			throw std::exception();

		return ptr[i]; 
	}

	template <typename T> T dynamic_array<T>::get(int i) {
		if (i > idx - 1)
			throw std::exception();
		
		return ptr[i]; 
	}

	template <typename T> void dynamic_array<T>::realloc(int newSz) {
		T* oldPtr = ptr;
		ptr = new T[newSz];

		//Allocation error
		if (ptr == nullptr)
			throw std::exception();

		if (newSz < idx + 1)
			idx = newSz - 1;

		for (int i = 0; i < idx; i++)
			ptr[i] = oldPtr[i];

		sz = newSz;

		delete[] oldPtr;
	}

	template <typename T> void dynamic_array<T>::pushBack(T val) {
		if (idx > sz - 1)
			expand();

		ptr[idx] = val;
		idx++;
	}

	template <typename T> T dynamic_array<T>::popBack() {
		idx--;
		return ptr[idx + 1];
	}

	template <typename T> void dynamic_array<T>::insert(T val, int i) {
		
		/*Make sure we have enough room for one more
		item on the top of the stack!*/
		if (idx > sz - 2)
			expand();

		//Push an item onto the stack
		for (int j = idx; j >= i; j--) {
			ptr[j+1] = ptr[j];
		}

		idx++;

		ptr[i] = val;
	}

	template <typename T> void dynamic_array<T>::erase(int i) {

		for (int j = i; j < idx - 1; j++)
			ptr[j] = ptr[j+1];

		idx--;
	}

	template <typename T> void dynamic_array<T>::clear() {
		delete[] ptr;
		ptr = new T[4];
		idx = 0;
		sz = 4;
	}
}
