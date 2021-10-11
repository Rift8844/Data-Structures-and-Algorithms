
#include <cstdlib>
#include <exception>

namespace mtl {
	template <typename T> class StupidPtr {
	public:
		T* ptr;

		StupidPtr(T* _ptr, int64_t sz);

		//Alternatively, you could just use this:
		StupidPtr(T* _ptr) : ptr{_ptr} {}

		~StupidPtr() {
			void* tmp = ptr;
			ptr = malloc(tmp);
			//Make sure we have no memory leaks
			free(tmp);
		}
	};
}