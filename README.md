# Mediocre Template Library (aka. elseq)w

*Here's a nice picture to show how seriously I take my work. I put a lot of effort into it!*
![Image](https://repository-images.githubusercontent.com/408642469/ea77857d-380e-4d00-8bb8-c3a2a99b2627)

Looking for an alternative template library with superior performance and features? Look ~~no~~ further than here, because this is just mediocre! This is elseq, a mediocre template library. This will probably be nowhere near the gold standard C++ Standard Template Library in terms of the likes of performance, memory usage, and most noticeably, features. It's more of a learning expereince for me, especially since my OOP programming got rusty after working on my emulator for so long.

## Implemented Structures:
- [ ] Dynamic Array (partially done)
- [ ] Singly and Doubly Linked Lists
- [ ] Stack
- [ ] Queue
- [ ] Pair
I don't know if I'll do all of these or not, as I really haven't done any planning. However, a Dynamic Array should be (by far) the most complex, so it shouldn't take me too long to get the others done if I implement a Dynamic Array in a reasonable amount of time.

## Building on Linux
Clone into the repository:
`git clone https://github.com/Rift8844/elseq`\
Build the code
`cd elseq & make`\
Run the program
`./elseqdemo` 

## Building on Windows
Get a real operating system, loser

## Usage

Make sure to `#include "mtl.h"`!
### Dynamic Array
```
//Only blank initialization... for now!
mtl::DynamicArray<YourType> arr;
//Push onto dynamic array
arr.push(YourType());
//Pop off of dynamic array
YourType obj = arr.pop();

//Insert at index idx
int idx = 5;
arr.insert(obj, 5);
//Remove at index idx
obj = arr.remove(5);

//Get size
arr.getSize();
//You can access with .get() or operator[]
arr[0] = arr[1];
arr.get(0) = arr.get(1);
```

