#include "parser.h"
#include "error.h"

using std::istream;
using std::string;

Parser :: Parser(istream & is) : mIn(is) {
}

string Parser :: NextWord() {
    string word;

    if (mIn >> word) {
        return word;
    }
    else if (mIn.eof()) {
        return "";
    }
    else {
        throw ScheckError("read error");
    }
}

