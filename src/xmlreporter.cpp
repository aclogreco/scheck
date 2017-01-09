#include "xmlreporter.h"

using std::string;

static string ToXML(const string & s) {
    return "<td>" + s + "</td>";
}

XMLReporter :: XMLReporter(std::ostream & os) : Reporter(os) {
}

void XMLReporter :: ReportHeader() {
    Out() << "<table>\n";
}

void XMLReporter :: ReportError(const string & word,
                                const string & context,
                                unsigned int line,
                                const string & filename) {
    Out() << "  <tr>\n" 
          << "    " << ToXML(word) << "\n"
          << "    " << ToXML(context) << "\n"
          << "    " << ToXML(string(line)) << "\n"
          << "    " << ToXML(filename) << "\n"
          << "  </tr>\n";
}

void XMLReporter :: ReportFooter() {
    Out() << "</table>\n";
}

