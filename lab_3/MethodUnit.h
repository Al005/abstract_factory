#ifndef METHODUNIT_H
#define METHODUNIT_H

#include "Unit.h"

class MethodUnit : public Unit {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4
    };

    MethodUnit( const std::string& name, const std::string& returnType, Flags flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) override{
        m_body.push_back( unit );
    }

protected:
    std::string m_name;  // Имя метода
    std::string m_returnType;  // Тип возвращаемого значения метода
    Flags m_flags;  // Модификаторы метода
    std::vector< std::shared_ptr< Unit > > m_body;  // Вектор в который мы добавляем методы
};

#endif // METHODUNIT_H
