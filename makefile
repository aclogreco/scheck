
bin/scheck.exe : bin/main.o bin/parser.o bin/dictionary.o
	g++ bin/dictionary.o bin/parser.o bin/main.o -o bin/scheck.exe


bin/dictionary.o : src/dictionary.cpp inc/dictionary.h inc/error.h
	g++ -I inc -c src/dictionary.cpp -o bin/dictionary.o


bin/parser.o : src/parser.cpp inc/parser.h inc/error.h
	g++ -I inc -c src/parser.cpp -o bin/parser.o


bin/main.o : src/main.cpp inc/dictionary.h inc/parser.h inc/error.h
	g++ -I inc -c src/main.cpp -o bin/main.o

