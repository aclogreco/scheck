#include <iostream>
#include <string>
#include <memory>

#include "error.h"
#include "dictionary.h"
#include "parser.h"
#include "reporter.h"
#include "csvreporter.h"
#include "xmlreporter.h"
#include "cmdline.h"
#include "settings.h"


using namespace std;


Reporter* MakeReporter (Settings::Report rt) {
    if (rt == Settings::rtCSV) {
        return new CSVReporter(cout);
    }
    else {
        return new XMLReporter(cout);
    }
}


void CheckSubmission (const Dictionary &d, istream &sub,
                      const std::string &subname, Reporter &rep) {
    Parser p(sub);
    string word;

    rep.ReportHeader();
    
    while ((word = p.NextWord()) != "") {
        if (!d.Check(word)) {
            rep.ReportError(word, p.Context(), p.LineNo(), subname);
        }
    }

    rep.ReportFooter();
}



int main(int argc, char *argv[]) {
    try {
        cout << "scheck version 0.9" << endl;
        
        CmdLine c1(argc, argv);
        Settings s(c1);
        Dictionary d(s.DictName());
        unique_ptr<Reporter> rep(MakeReporter(s.ReportType()));

        if (c1.Argc() == 1) {
            CheckSubmission(d, cin, "stdin", *rep);
        }
        else {
            for (int i = 1; i < c1.Argc(); i++) {
                ifstream sub(c1.Argv(i).c_str());

                if (!sub.is_open()) {
                    throw ScheckError("Can not open file " + c1.Argv(i));
                }

                CheckSubmission(d, sub, c1.Argv(i), *rep);
            }
        }

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

