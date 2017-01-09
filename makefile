bin/scheck : main.o parser.o dictionary.o
	g++ bin/main.o bin/parser.o bin/dictionary.o -o bin/scheck


dictionary.o : src/dictionary.cpp inc/dictionary.h inc/error.h
	g++ -I inc -c src/dictionary.cpp -o bin/dictionary.o


parser.o : src/parser.cpp inc/parser.h inc/error.h
	g++ -I inc -c src/parser.cpp -o bin/parser.o


main.o : src/main.cpp inc/dictionary.h inc/parser.h inc/error.h
	g++ -I inc -c src/main.cpp -o bin/main.o

