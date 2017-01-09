#ifndef INC_XMLREPORTER_H
#define INC_XMLREPORTER_H

#include "reporter.h"

class XMLReporter : public Reporter {
    public:
        XMLReporter(std::ostream & os);
        void ReportHeader();
        void ReportError(const std::string & word,
                         const std::string & context,
                         unsigned int line,
                         const::string & filename);
        void ReportFooter();
};

#endif

