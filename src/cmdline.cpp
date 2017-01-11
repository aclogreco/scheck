#include "cmdline.h"


using std::string;


CmdLine::CmdLine (int argc, char *argv[]) {
    for (int i = 0; i < argc; i++) {
        mArgs.push_back(argv[i]);
    }
}


CmdLine::Iter CmdLine::FindOpt (const string &opt) {
    for (int i = 1; i < Argc(); i++) {
        if (opt == Argv(i)) {
            return mArgs.begin() + i;
        }
    }

    return mArgs.end();
}


bool CmdLine::HasOpt (const string &opt) const {
    return (const_cast<CmdLine*>(this)->FindOpt(opt) != mArgs.end());
}


bool CmdLine::ExtractOpt (const string &opt) {
    Iter pos = FindOpt(opt);

    if (pos != mArgs.end()) {
        mArgs.erase(pos);

        return true;
    }
    else {
        return false;
    }
}


bool CmdLine::ExtractOpt (const string &opt, string &val) {
    Iter pos = FindOpt(opt);
    if (pos != mArgs.end() && pos != mArgs.end() - 1) {
        val = *(pos + 1);
        mArgs.erase(pos, pos + 2);

        return true;
    }
    else {
        return false;
    }
}


bool CmdLine::MoreOpts () const {
    for (int i = 1; i < Argc(); i++) {
        if (Argv(i) != "" && Argv(i).at(0) == '-') {
            return true;
        }
    }

    return false;
}


int CmdLine::Argc () const {
    return mArgs.size();
}


string CmdLine::Argv (unsigned int i) const {
    return mArgs.at(i);
}

