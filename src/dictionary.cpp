#include "dictionary.h"

Dictionary :: Dictionary(const std::string & fname) {
    std::ifstream wlist(fname.c_str());
    if (!wlist.is_open()) {
        // report open error
        throw ScheckError("Could not open dictionary file " + fname);
    }
    
    std::string word;
    
    while (std::getline(wlist, word)) {
        mWords.insert(word);
    }
    
    if (!wlist.eof()) {
        // report read error
        throw ScheckError("Error reading dictionary file " + fname);
    }
}

bool Dictionary :: Check( const std::string & word  ) const {
    return mWords.find(word) != mWords.end();
}

