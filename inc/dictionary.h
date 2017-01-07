#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H


#include <string>
#include <set>


class Dictionary {
    public:
        Dictionary( const std::string & fname ) {
            mWords.insert("dog");
        }

        bool Check( const std::string & word  ) const {
            return mWords.find(word) != mWords.end();
        }

    private:
        std::set <std::string> mWords;
};


#endif
