
#include "dynArr.hpp"

using namespace mtl;


/*template <class T> T const& DynamicArray<T>::get(int i) const {
	if (i > idx)
		throw std::exception();

	return ptr[i]; 
}*/

template <class T> T DynamicArray<T>::get(int i) {
	if (i > idx - 1)
		throw std::exception();
	
	return ptr[i]; 
}



template <class T> void DynamicArray<T>::expand() {
	sz *= 2;
	T* oldPtr = ptr;
	ptr = new T[sz];

	//Allocation error
	if (ptr == nullptr)
		throw std::exception();

	for (int i = 0; i < sz/2; i++)
		ptr[i] = oldPtr[i];

	delete[] oldPtr;
}

template <class T> void DynamicArray<T>::push(T val) {
	if (idx > sz - 1)
		expand();

	ptr[idx] = val;
	idx++;
}

template <class T> T DynamicArray<T>::pop() {
	idx--;
	return ptr[idx + 1];
}

template <class T> void DynamicArray<T>::insert(T val, int i) {
	
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

