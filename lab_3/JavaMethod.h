#ifndef JAVAMETHOD_H
#define JAVAMETHOD_H

#include "MethodUnit.h"

class JavaMethod : public MethodUnit {
public:
    JavaMethod(const std::string& name, const std::string& returnType, Flags flags) : MethodUnit (name, returnType, flags) {}

    std::string compile( unsigned int level = 0 ) const {
        std::string result = generateShift( level );
        if ( m_flags & STATIC) {
            result += "static ";
        }
        else if (m_flags & FINAL) {
            result += "final ";
        }
        else if (m_flags & ABSTRACT) {
            result += "abstract ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        result += " {\n";

        for( const auto& b : m_body ) { // вывод в result тела метода, которое будет состоять из ранее добавленных метода
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }

};

#endif // JAVAMETHOD_H
