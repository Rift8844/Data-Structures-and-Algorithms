#include <cstdlib>
#include <exception>


namespace mtl {
	//A funky nickname I thought of for a vector lmfao
	template <class T> class DynamicArray {
		T* ptr;
		int sz, idx;

		void expand();
		/*Maybe implement this
		later for fun*/
		//void shrink();

	public:
		int getSize() const { return sz; };

		void push(T val);
		T pop();

		void insert(T val, int i);

		T& operator[](int i) {
			if (i > idx)
				throw std::exception();

			return ptr[i]; 
		}
		//Does this syntax work?
		T const& operator[](int i) const {
			if (i > idx)
				throw std::exception();

			return ptr[i]; 
		}
	};
}
