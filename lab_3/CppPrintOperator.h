#ifndef CPPPRINTOPERATOR_H
#define CPPPRINTOPERATOR_H

#include "PrintOperatorUnit.h"

class CppPrintOperator : public PrintOperatorUnit {
public:
    CppPrintOperator(const std::string& text) : PrintOperatorUnit(text) {}

    std::string compile( unsigned int level = 0 ) const {
        return generateShift( level ) + "printf( \"" + m_text + "\" );\n";
    }

};


#endif // CPPPRINTOPERATOR_H
