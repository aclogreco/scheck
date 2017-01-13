#include "settings.h"


const char * const DEF_DICT = "dictionary.dat";
const char * const DICT_OPT = "-d";
const char * const CSV_OPT  = "-csv";
const char * const XML_OPT  = "-xml";


Settings::Settings (CmdLine &c1) : mRepType(rtCSV), mDictName(DEF_DICT) {
    if (c1.HasOpt(CSV_OPT) && c1.HasOpt(XML_OPT)) {
        throw ScheckError("Only one output type can be specified.");
    }

    if (c1.ExtractOpt(CSV_OPT)) {
        mRepType = rtCSV;
    }

    if (c1.ExtractOpt(XML_OPT)) {
        mRepType = rtXML;
    }

    c1.ExtractOpt(DICT_OPT, mDictName);

    if (c1.MoreOpts()) {
        throw ScheckError("Invalid command line option.");
    }
}


Report Settings::ReportType () const {
    return mRepType;
}


std::string Settings::DictName () const {
    return mDictName;
}

