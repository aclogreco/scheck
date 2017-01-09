#ifndef INC_CSVREPORTER_H
#define INC_CSVREPORTER_H

#include "reporter.h"

class CSVReporter : public Reporter {
    public:
        CSVReporter(std::ostream & os);
        void ReportHeader();
        void ReportError(const std::string & word,
                         const std::string & context,
                         unsigned int line,
                         const std::string & filename);
        void ReportFooter();
};

#endif

