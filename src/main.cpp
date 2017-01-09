#include <iostream>
#include <string>
#include "dictionary.h"
#include "parser.h"
#include "csvreporter.h"

using namespace std;

int main() {
    try {
        cout << "scheck version 0.6" << endl;

        Dictionary d("data/mydict.dat");
        //Dictionary d("data/not-there.dat");
        //Dictionary d("data/dict.dat");
        
        const char* subtext = "data/sub1.txt";
        ifstream sub(subtext);
        if (!sub.is_open()) {
            throw ScheckError(string("cannot open ") + subtext);
        }
        
        
        Parser p(sub);
        CSVReporter rep(cout);
        
        string word;
        rep.ReportHeader();
        while ((word = p.NextWord()) != "") {
            if (!d.Check(word)) {
                rep.ReportError(word, p.Context(), p.LineNo(), subtext);
            }
        }
        rep.ReportFooter();
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
