#include <QCoreApplication>

#include "FactoryLang.h"
#include "Factoryes.h"
#include <iostream>

//
std::string generateProgram(const std::shared_ptr< FactoryLang >& Fact)
{
    auto myClass = Fact->createClass("MyClass");
    myClass->add(Fact->createMethod( "testFunc1", "void", MethodUnit::ABSTRACT ), ClassUnit::PRIVATE);
    myClass->add(Fact->createMethod( "testFunc2", "int", MethodUnit::FINAL), ClassUnit::PUBLIC);
    auto method = Fact->createMethod( "testFunc3", "void", MethodUnit::STATIC );
    method->add( Fact->createPrintOperator(R"(Hello, world!\n)"));
    myClass->add(method, ClassUnit::PROTECTED );
    myClass->add(Fact->createMethod( "testFunc4", "void", MethodUnit::CONST ), ClassUnit::PUBLIC);
    myClass->add(Fact->createMethod( "testFunc5", "string", MethodUnit::FINAL ), ClassUnit::INTERNAL);

    return myClass->compile();
}
//

std::string generateProgramCpp(const std::shared_ptr<FactoryLang>& Fact) //Клиентский код
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

std::string generateProgramJava(const std::shared_ptr<FactoryLang>& Fact)
{
    auto myClass = Fact->createClass("MyClass");
    myClass->add(Fact->createMethod( "testFunc1", "void", MethodUnit::STATIC ), ClassUnit::PRIVATE);
    myClass->add(Fact->createMethod( "testFunc2", "int", MethodUnit::VIRTUAL | MethodUnit::CONST), ClassUnit::PUBLIC);
    auto method = Fact->createMethod( "testFunc3", "void", MethodUnit::STATIC );
    method->add( Fact->createPrintOperator(R"(Hello, world!\n)"));
    myClass->add(method, ClassUnit::PROTECTED );
    myClass->add(Fact->createMethod( "testFunc4", "bool", MethodUnit::CONST ), ClassUnit::PUBLIC);
    myClass->add(Fact->createMethod( "testFunc5", "string", MethodUnit::FINAL ), ClassUnit::PROTECTED);

    return myClass->compile();
}

std::string generateProgramCSharp(const std::shared_ptr<FactoryLang>& Fact)
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

    std::cout << generateProgram(std::make_shared<CppFactory>()) << std::endl;
    std::cout << std::endl << generateProgram(std::make_shared<JavaFactory>()) << std::endl;
    std::cout << std::endl <<generateProgram(std::make_shared<CSharpFactory>()) << std::endl;


    //std::shared_ptr<FactoryLang> factoryJava = std::make_shared<JavaFactory>();
    //std::cout << generateProgramJava(factoryJava) << std::endl;


    return 0;
}
