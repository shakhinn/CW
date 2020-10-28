all: lab3

lab3: main.o InOut.o Node.o Tree.o
	x86_64-w64-mingw32-g++ -static-libgcc -static-libstdc++ -o aisd_lb3 main.o InOut.o Node.o Tree.o
main.o: main.cpp
	x86_64-w64-mingw32-g++ -static-libgcc -static-libstdc++ -c main.cpp
InOut.o: InOut.cpp
	x86_64-w64-mingw32-g++ -static-libgcc -static-libstdc++ -c InOut.cpp
Node.o: Node.cpp
	x86_64-w64-mingw32-g++ -static-libgcc -static-libstdc++ -c Node.cpp
Tree.o: Tree.cpp
	 x86_64-w64-mingw32-g++ -static-libgcc -static-libstdc++ -c Tree.cpp    
clean: 
	rm -rf *.o 
