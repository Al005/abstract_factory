#ifndef JAVACLASS_H
#define JAVACLASS_H

#include "ClassUnit.h"

class JavaClass : public ClassUnit {
public:
    JavaClass( const std::string& name ) : ClassUnit( name ) {}

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override{
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }

        m_fields[ accessModifier ].push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const override {
        std::string result = generateShift( level ) + "class " + m_name + " {\n";
        for( size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i ) {
            if( m_fields[ i ].empty() ) {
                continue;
            }
            // Модификатор доступа пишется перед каждым методом
            for( const auto& f : m_fields[ i ] ) {
                result += generateShift(level+1) + ACCESS_MODIFIERS[ i ] + f->compile( level + 1 );
            }

            result += "\n";
        }
        result += generateShift( level ) + "};\n";
        return result;
    }

};


#endif // JAVACLASS_H