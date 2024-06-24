#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "Unit.h"

class ClassUnit : public Unit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        INTERNAL,
        PROTECTED_INTERNAL
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;


    explicit ClassUnit( const std::string& name ) : m_name( name ) {  // Исключаем неявный вызов конструктора
        m_fields.resize(ACCESS_MODIFIERS.size());
    }


protected:
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::string m_name; // Имя класса
    std::vector< Fields > m_fields;  // Контейнер хранящий поля класса по модификаторам доступа
};

const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public", "protected", "private", "private protected", "file", "internal", "protectetd internal" };


#endif // CLASSUNIT_H
