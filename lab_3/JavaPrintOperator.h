#ifndef JAVAPRINTOPERATOR_H
#define JAVAPRINTOPERATOR_H

#include "PrintOperatorUnit.h"

class JavaPrintOperator : public PrintOperatorUnit {
public:
    JavaPrintOperator(const std::string& text) : PrintOperatorUnit(text) {}
    std::string compile( unsigned int level = 0 ) const override {
        return generateShift( level ) + "System.out.println(\"" + m_text + "\" );\n";
    }
};

#endif // JAVAPRINTOPERATOR_H
