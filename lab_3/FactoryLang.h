#ifndef FACTORYLANG_H
#define FACTORYLANG_H

#include "Unit.h"
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

class FactoryLang {
public:
    virtual ~FactoryLang() = default;

    virtual std::shared_ptr< ClassUnit > createClass( const std::string& name ) = 0;

    virtual std::shared_ptr< MethodUnit > createMethod(const std::string& name,const std::string& returnType,Unit::Flags flags) = 0;

    virtual std::shared_ptr< PrintOperatorUnit > createPrintOperator( const std::string& text ) = 0;
};

#endif // FACTORYLANG_H
