#ifndef INC_CMDLINE_H
#define INC_CMDLINE_H

#include <string>

class CmdLine {
    public:
        CmdLine (int argc, char *argv[]);
        bool HasOpt (const std::string &opt) const;
        bool ExtractOpt (const std::string &opt);
        bool ExtractOpt (const std::string &opt, std::string &val);
        bool MoreOpts () const;
        int Argc () const;
        std::string Argv (unsigned int i) const;
    private:
        typedef std::vector<std::string> ArgVec;
        typedef ArgVec::iterator Iter;
        Iter FindOpt (const std::string &opt);
        ArgVec mArgs;
};

#endif
