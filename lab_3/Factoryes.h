#ifndef FACTORYES_H
#define FACTORYES_H

#include "FactoryLang.h"
#include "CppClass.h"
#include "CppMethod.h"
#include "CppPrintOperator.h"

class CppFactory : public FactoryLang {
public:
    std::shared_ptr< ClassUnit > createClass( const std::string& name ) override {
        return std::make_shared<CppClass>(name);
    }

    std::shared_ptr< MethodUnit > createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override{
        return std::make_shared<CppMethod>(name, returnType, flags );
    }

    std::shared_ptr< PrintOperatorUnit > createPrintOperator( const std::string& text ) override{
        return std::make_shared< CppPrintOperator >(text);
    }
};

#endif // FACTORYES_H
