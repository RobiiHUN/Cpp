#include "pstring.h"

PString::PString() : String() {}
PString::PString(const String& s) : String(s) {}

void PString::write(std::ostream& os) const {
    os << size() << c_str();
}


void PString::read(std::istream& is) {
    size_t size = 0;
    is >> size >> std::noskipws;
    char* buffer = new char[size + 1];
    for (size_t i = 0; i < size; i++)
    {
        is >> buffer[i];
    }
    is >> std::skipws;
    buffer[size] = '\0';
    *this = String(buffer);
    delete[] buffer;

    
}