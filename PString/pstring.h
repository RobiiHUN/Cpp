#ifndef PSTRING_H
#define PSTRING_H
#include "string5.h"
#include "serializable.h"


class PString : public String, public Serializable{
public:
            PString(const char* s = "");
            PString(char c);
            PString(const String& s);

            void write(std::ostream& os) const;
            void read(std::istream& is);

};

std::ostream& operator<<(std::ostream& os, const PString& s);
std::istream& operator>>(std::istream& is, PString& s);

#endif // PSTRING_H

