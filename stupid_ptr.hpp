
#include <cstdlib>
#include <exception>

namespace mtl {
	template <typename T> class stupid_ptr {
	public:
		T* ptr;

		stupid_ptr(T* _ptr, int64_t sz);

		//Alternatively, you could just use this:
		stupid_ptr(T* _ptr) : ptr{_ptr} {}

		~stupid_ptr() {
			void* tmp = ptr;
			ptr = malloc(tmp);
			//Make sure we have no memory leaks
			free(tmp);
		}
	};
}