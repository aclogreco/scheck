#ifndef INC_DICTIONARY_H
#define INC_DICTIONARY_H


#include <string>
#include <set>
#include <fstream>
#include "error.h"


class Dictionary {
    public:
        Dictionary( const std::string & fname );
        bool Check( const std::string & word  ) const;

    private:
        std::set <std::string> mWords;
};


#endif
