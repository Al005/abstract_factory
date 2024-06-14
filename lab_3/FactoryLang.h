#ifndef FACTORYLANG_H
#define FACTORYLANG_H

#include "Unit.h"
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

class FactoryLang {
public:
    virtual std::shared_ptr< ClassUnit > createClass(const std::string& name) const = 0;

    virtual std::shared_ptr< MethodUnit > createMethod(const std::string& name,const std::string& returnType,Unit::Flags flags) const = 0;

    virtual std::shared_ptr< PrintOperatorUnit > createPrintOperator(const std::string& text) const = 0;
};

#endif // FACTORYLANG_H
