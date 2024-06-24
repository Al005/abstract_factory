#ifndef CSHARPPRINTOPERATOR_H
#define CSHARPPRINTOPERATOR_H

#include "PrintOperatorUnit.h"

class CSharpPrintOperator : public PrintOperatorUnit {
public:
    CSharpPrintOperator(const std::string& text) : PrintOperatorUnit(text) {}

    std::string compile( unsigned int level = 0 ) const override {
        return generateShift( level ) + "Console.WriteLine(\"" + m_text + "\" );\n";
    }
};

#endif // CSHARPPRINTOPERATOR_H
