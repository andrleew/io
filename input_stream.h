#pragma once

#include "reader.h"
#include "buffer.h"

#include <cctype>
#include <string>

class TInputStream {
public:
    TInputStream();
    char GetChar();
    void Unget();
    void SkipSpaces();

public:
    inline bool isEOF() const {
        return Buffer.Empty();
    }

public:
    operator bool() const {
        return !isEOF();
    }

public:
    static const int IS_EOF = -1;

private:
    TBuffer Buffer;
    size_t Begin;

};

TInputStream& operator>>(TInputStream& is, char& c);

TInputStream& operator>>(TInputStream& is, int& v);