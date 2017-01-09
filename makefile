
bin/scheck.exe : bin/main.o bin/parser.o bin/dictionary.o bin/csvreporter.o bin/xmlreporter.o
	g++ bin/csvreporter.o bin/dictionary.o bin/parser.o bin/main.o -o bin/scheck.exe


bin/dictionary.o : src/dictionary.cpp inc/dictionary.h inc/error.h
	g++ -I inc -c src/dictionary.cpp -o bin/dictionary.o


bin/parser.o : src/parser.cpp inc/parser.h inc/error.h
	g++ -I inc -c src/parser.cpp -o bin/parser.o


bin/csvreporter.o : src/csvreporter.cpp inc/csvreporter.h inc/reporter.h
	g++ -I inc -c src/csvreporter.cpp -o bin/csvreporter.o


bin/xmlreporter.o : src/xmlreporter.cpp inc/xmlreporter.h inc/reporter.h
	g++ -I inc -c src/xmlreporter.cpp -o bin/xmlreporter.cpp


bin/main.o : src/main.cpp inc/dictionary.h inc/parser.h inc/csvreporter.h \
	inc/xmlreporter.h inc/error.h
	g++ -I inc -c src/main.cpp -o bin/main.o

