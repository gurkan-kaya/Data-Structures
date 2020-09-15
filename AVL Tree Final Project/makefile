hepsi: derle calistir

derle:
	g++ -I ./include -o ./lib/AVL.o -c ./src/AVL.cpp
	g++ -I ./include -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include -o ./lib/Kisi.o -c ./src/Kisi.cpp
	g++ -I ./include -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include -o ./lib/StackDugum.o -c ./src/StackDugum.cpp
	g++ -I ./include -o ./bin/main.exe ./lib/AVL.o ./lib/Dugum.o ./lib/Kisi.o ./lib/Stack.o ./lib/StackDugum.o ./src/main.cpp 
calistir:
	./bin/main.exe
	