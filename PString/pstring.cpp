#include "pstring.h"

PString::PString(const char* s) : String(s) {}
PString::PString(char c) : String(c) {}
PString::PString(const String& s) : String(s) {}

void PString::write(std::ostream& os) const {
    os << c_str();
}

std::ostream& operator<<(std::ostream& os, const PString& s) {
    s.write(os);
    return os;
}

std::istream& operator>>(std::istream& is, PString& s) {
    int size;
    is >> size;
    char* buffer = new char[size];
    is >> buffer;
    s = PString(buffer);
    delete[] buffer;
    return is;
}

void PString::read(std::istream& is) {
    int size;
    is >> size;
    char* buffer = new char[size];
    is >> buffer;
    *this = PString(buffer);
    delete[] buffer;
}