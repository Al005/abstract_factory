#ifndef CPPCLASS_H
#define CPPCLASS_H

#include "ClassUnit.h"

class CppClass : public ClassUnit {
public:
    CppClass( const std::string& name ) : ClassUnit( name ) {
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override{
        int accessModifier = PRIVATE;
        if (flags == PROTECTED) {
            accessModifier = PROTECTED;
        } else if (flags == PUBLIC) {
            accessModifier = PUBLIC;
        }
        m_fields[ accessModifier ].push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const override{
        std::string result = generateShift( level ) + "class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {  // Пробегаемся по всем модификаторам доступа
            if( m_fields[i].empty() ) {
                continue;
            }

            result += ACCESS_MODIFIERS[ i ] + ":\n";
            for( const auto& f : m_fields[i] ) {  // Проверяем, какие еще есть объекты с данным модификатором
                result += f->compile( level + 1 );  // Если нашелся, вызываем метод compile данного объекта
            }

            result += "\n";
        }
        result += generateShift( level ) + "};\n";

        return result;
    }
};

#endif // CPPCLASS_H
