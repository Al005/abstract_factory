#ifndef FACTORYLANG_H
#define FACTORYLANG_H

#include "Unit.h"
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

class LangFactory {
public:
    virtual ~LangFactory() = default;

    virtual std::unique_ptr< ClassUnit > createClass( const std::string& name ) = 0;

    virtual std::unique_ptr< MethodUnit > createMethod(
        const std::string& name,
        const std::string& returnType,
        Unit::Flags flags) = 0;

    virtual std::unique_ptr< PrintOperatorUnit > createPrintOperator( const std::string& text ) = 0;
};

#endif // FACTORYLANG_H
