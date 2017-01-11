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
    // TODO implement HasOpt method
}


bool CmdLine::ExtractOpt (const string &opt) {
    // TODO implement ExtractOpt method (no option value version)
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
    // TODO implement MoreOpts method
}


int CmdLine::Argc () const {
    // TODO implement Argc method
}


string CmdLine::Argv (unsigned int i) const {
    // TODO implement Argv method
}

