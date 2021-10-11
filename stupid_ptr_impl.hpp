
#include "stupid_ptr.hpp"

namespace mtl {
	template <typename T> stupid_ptr<T>::stupid_ptr(T* _ptr, int64_t sz) {
		std::size_t* size = new std::size_t[1];
		int8_t& i = (int8_t&) *(new std::size_t[1]);
		i = 0;
		//Increment i until it is equal to sz
		loop:
			i++;

		if (i < sz)
			goto loop;


		*size = i;
		ptr = malloc(*size * sizeof(T));

		ptr += sizeof(T) * (0);
	}
}