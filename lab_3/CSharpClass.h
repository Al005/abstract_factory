#ifndef CSHARPCLASS_H
#define CSHARPCLASS_H

#include "ClassUnit.h"

class CSharpClass : public ClassUnit {
public:
    CSharpClass( const std::string& name ) : ClassUnit( name ) {}

    void add( const std::shared_ptr< Unit >& unit, Flags flags ) override {
        int accessModifier = PRIVATE;
        if (flags == PROTECTED) {
            accessModifier = PROTECTED;
        }
        else if (flags == PUBLIC){
            accessModifier = PUBLIC;
        }
        else if (flags == INTERNAL){
            accessModifier = INTERNAL;
        }
        else if (flags == FILE){
            accessModifier = FILE;
        }
        else if (flags == PRIVATE_PROTECTED){
            accessModifier = PRIVATE_PROTECTED;
        }
        else if (flags == PROTECTED_INTERNAL){
            accessModifier = PROTECTED_INTERNAL;
        }
        m_fields[ accessModifier ].push_back( unit );
    }

    std::string compile (unsigned int level = 0) const override {
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

#endif // CSHARPCLASS_H
