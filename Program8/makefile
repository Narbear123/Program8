final: main.o HashTable.o HashEntry.o
	g++ -o plagiarismCatcher  main.o HashTable.o HashEntry.o
main.o: main.cpp HashTable.h HashEntry.h
	g++ -c main.cpp
HashTable.o: HashTable.h HashEntry.h
	g++ -c HashTable.h
HashEntry.o: HashEntry.h
	g++ -c HashEntry.h