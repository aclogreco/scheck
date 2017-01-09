#include <iostream>
#include <string>
#include "dictionary.h"
#include "parser.h"
#include "reporter.h"
#include "csvreporter.h"
#include "xmlreporter.h"

using namespace std;

int main(int argc, char *argv[]) {
    try {
        cout << "scheck version 0.7" << endl;

        Dictionary d("data/mydict.dat");
        //Dictionary d("data/not-there.dat");
        //Dictionary d("data/dict.dat");
        
        //const char* subtext = "data/sub1.txt";
        const char* subtext = "data/sub2.txt";
        
        ifstream sub(subtext);
        if (!sub.is_open()) {
            throw ScheckError(string("cannot open ") + subtext);
        }
        
        
        Parser p(sub);

        Reporter *rep = 0;
        if (argc == 1) {
            rep = new CSVReporter(cout);
        }
        else {
            rep = new XMLReporter(cout);
        }
        
        string word;
        rep->ReportHeader();
        while ((word = p.NextWord()) != "") {
            if (!d.Check(word)) {
                rep->ReportError(word, p.Context(), p.LineNo(), subtext);
            }
        }
        rep->ReportFooter();

        delete rep;

        return 0;
    }

    catch (const ScheckError & e) {
        cerr << "Error: " << e.what() << endl;

        return 1;
    }

    catch (...) {
        cerr << "Error: unknown exception" << endl;

        return 2;
    }
}
