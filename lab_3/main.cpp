#include <QCoreApplication>

#include "FactoryLang.h"
#include "Factoryes.h"
#include <iostream>

std::string generateProgram(const std::shared_ptr< FactoryLang >& Fact) //Клиентский код
{
    auto myClass = Fact->createClass("MyClass");
    myClass->add(Fact->createMethod( "testFunc1", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE);
    myClass->add(Fact->createMethod( "testFunc2", "int", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);
    auto method = Fact->createMethod( "testFunc3", "void", MethodUnit::STATIC );
    method->add( Fact->createPrintOperator(R"(Hello, world!\n)"));
    myClass->add(method, ClassUnit::PROTECTED );
    myClass->add(Fact->createMethod( "testFunc4", "bool", MethodUnit::CONST ), ClassUnit::PUBLIC);

    return myClass->compile();
}

int main() {
    std::shared_ptr<FactoryLang> factoryCpp = std::make_shared<CppFactory>();
    std::cout << generateProgram(factoryCpp) << std::endl;



    return 0;
}
