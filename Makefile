CXX = g++
#CPPFLAGS = -c
CXXFLAGS = -c -g -fpermissive
LDFLAGS = -o elseqdemo

elseqdemo: main.o mtl.o
	$(CXX) $(LDFLAGS) main.o mtl.o


mtl.o: mtl.hpp mtl.cpp
	$(CXX) $(CXXFLAGS) mtl.hpp mtl.cpp
mtl.cpp:
	echo "//This is literally just so the (word that rhymes with trucking)\
	program will build properly\n//Now that I spent like an hour creating this\
	stupid makefile on a friday night I can actually get to work on my programming lol XD" > mtl.cpp


main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp


clean:
	rm *.o *.gch mtl.cpp elseqdemo