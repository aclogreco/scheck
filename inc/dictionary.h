#include <string>

class Dictionary {
    public:
        Dictionary( const std::string & fname );
        bool Check( const std::string & word  ) const;
};
