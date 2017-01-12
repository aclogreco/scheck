#ifndef INC_SETTINGS_H
#define INC_SETTINGS_H


#include <string>
#include "cmdline.h"
#include "error.h"


class Settings {

    public:

        enum Report { rtCSV, rtXML };
        Settings (CmdLine &c1);
        Report ReportType() const;
        std::string DictName() const;

    private:

        Report mRepType;
        std::string mDictName;

};


#endif
