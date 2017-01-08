#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H


#include <string>
#include <set>
#include <fstream>


class Dictionary {
    public:
        Dictionary( const std::string & fname ) {
            std::ifstream wlist(fname.c_str());
            std::string word;

            while (std::getline(wlist, word)) {
                mWords.insert(word);
            }
        }

        bool Check( const std::string & word  ) const {
            return mWords.find(word) != mWords.end();
        }

    private:
        std::set <std::string> mWords;
};


#endif
