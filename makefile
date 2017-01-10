PRODUCT := scheck.exe
BINDIR := bin
INCDIR := inc
SRCDIR := src
OBJDIR := obj


CXX := g++
LINKER := g++
INCDIRS := -I$(INCDIR)
CXXFLAGS := -std=gnu++11 -Wall -Wextra


SRCFILES := $(wildcard $(SRCDIR)/*.cpp)
OBJFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCFILES))
DEPFILES := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.d,$(SRCFILES))


$(BINDIR)/$(PRODUCT) : $(OBJFILES)
	$(LINKER) $(CXXFLAGS) $^ -o $@


clean:
	rm -f $(OBJDIR)/*.o $(BINDIR)/$(PRODUCT)

depends:
	rm -f $(OBJDIR)/*.d
	$(MAKE) $(DEPFILES)


$(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCDIRS) -c $< -o $@


$(OBJDIR)/%.d : $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(INCDIRS) -MM $< \
		| tr '\\n\\r\\\\' ' ' \
		| sed -e 's%^%$@ %' -e 's% % $(OBJDIR)/%' \
		> $@


-include $(DEPFILES)


#bin/scheck.exe : bin/main.o bin/parser.o bin/dictionary.o bin/csvreporter.o bin/xmlreporter.o
#	g++ --std=gnu++11 bin/xmlreporter.o bin/csvreporter.o bin/dictionary.o \
#		bin/parser.o bin/main.o -o bin/scheck.exe


#bin/dictionary.o : src/dictionary.cpp inc/dictionary.h inc/error.h
#	g++ --std=gnu++11 -I inc -c src/dictionary.cpp -o bin/dictionary.o


#bin/parser.o : src/parser.cpp inc/parser.h inc/error.h
#	g++ --std=gnu++11 -I inc -c src/parser.cpp -o bin/parser.o


#bin/csvreporter.o : src/csvreporter.cpp inc/csvreporter.h inc/reporter.h
#	g++ --std=gnu++11 -I inc -c src/csvreporter.cpp -o bin/csvreporter.o


#bin/xmlreporter.o : src/xmlreporter.cpp inc/xmlreporter.h inc/reporter.h
#	g++ --std=gnu++11 -I inc -c src/xmlreporter.cpp -o bin/xmlreporter.o


#bin/main.o : src/main.cpp inc/dictionary.h inc/parser.h inc/csvreporter.h \
#	inc/xmlreporter.h inc/reporter.h inc/error.h
#	g++ --std=gnu++11 -I inc -c src/main.cpp -o bin/main.o

