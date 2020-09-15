hepsi: derle calistir

derle:
	g++ -I ./include -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include -o ./lib/Iterator.o -c ./src/Iterator.cpp
	g++ -I ./include -o ./lib/CircularDoublyLinkedList.o -c ./src/CircularDoublyLinkedList.cpp
	g++ -I ./include -o ./bin/main.exe ./lib/Node.o ./lib/Iterator.o ./lib/CircularDoublyLinkedList.o ./src/main.cpp 
calistir:
	./bin/main.exe
	