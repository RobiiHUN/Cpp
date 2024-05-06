#ifndef PSTRING_H
#define PSTRING_H
#include "string5.h"
#include "serializable.h"


class PString : public String, public Serializable{
public:
            PString();
            PString(const String& s);
            ~PString(){}

            void write(std::ostream& os) const;
            void read(std::istream& is);

};


#endif // PSTRING_H

