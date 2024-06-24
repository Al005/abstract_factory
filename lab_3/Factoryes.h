#ifndef FACTORYES_H
#define FACTORYES_H

#include "FactoryLang.h"

#include "CppClass.h"
#include "CppMethod.h"
#include "CppPrintOperator.h"

#include "JavaClass.h"
#include "JavaMethod.h"
#include "JavaPrintOperator.h"

#include "CSharpClass.h"
#include "CSharpMethod.h"
#include "CSharpPrintOperator.h"

class CppFactory : public FactoryLang {
public:
    std::shared_ptr< ClassUnit > createClass( const std::string& name ) const override{
        return std::make_shared<CppClass>(name);
    }

    std::shared_ptr< MethodUnit > createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override {
        return std::make_shared<CppMethod>(name, returnType, flags );
    }

    std::shared_ptr< PrintOperatorUnit > createPrintOperator( const std::string& text ) const override {
        return std::make_shared< CppPrintOperator >(text);
    }
};


class JavaFactory : public FactoryLang {
public:
    std::shared_ptr< ClassUnit > createClass( const std::string& name ) const override {
        return std::make_shared<JavaClass>(name);
    }

    std::shared_ptr< MethodUnit > createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override {
        return std::make_shared<JavaMethod>(name, returnType, flags );
    }

    std::shared_ptr< PrintOperatorUnit > createPrintOperator( const std::string& text ) const override{
        return std::make_shared< JavaPrintOperator >(text);
    }
};


class CSharpFactory : public FactoryLang {
public:
    std::shared_ptr< ClassUnit > createClass( const std::string& name ) const override {
        return std::make_shared<CSharpClass>(name);
    }

    std::shared_ptr< MethodUnit > createMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const override {
        return std::make_shared<CSharpMethod>(name, returnType, flags );
    }

    std::shared_ptr< PrintOperatorUnit > createPrintOperator( const std::string& text ) const override{
        return std::make_shared< CSharpPrintOperator >(text);
    }
};

#endif // FACTORYES_H
