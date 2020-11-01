#include "input_stream.h"

TInputStream::TInputStream()
: Begin(0)
{
    TReader::ReadFromStd(Buffer);
}

char TInputStream::GetChar() {
    if (Begin == Buffer.GetSize()) {
        TReader::ReadFromStd(Buffer);
        Begin = 0;
    }
    if (isEOF()) return -1;
    return Buffer[Begin++];
}

void TInputStream::Unget() {
    if (Begin > 0) --Begin;
}

void TInputStream::SkipSpaces() {
    for (;;) {
        if (isEOF()) return;
        while (Begin < Buffer.GetSize() && std::isspace(Buffer[Begin])) ++Begin;
        if (Begin < Buffer.GetSize()) return;
        TReader::ReadFromStd(Buffer);
        Begin = 0;
    }
}


TInputStream& operator>>(TInputStream& is, char& c) {
    c = is.GetChar();
    return is;
}

TInputStream& operator>>(TInputStream& is, int& v) {
    v = 0;
    int c;
    is.SkipSpaces();
    bool neg = is.GetChar() == '-';
    if (!neg) is.Unget();
    while ((c = is.GetChar()) != is.IS_EOF && std::isdigit(c)) {
        v = v * 10 + c - '0';
    }
    if (c != is.IS_EOF) is.Unget();
    v *= (neg ? -1 : 1);
    return is;
}