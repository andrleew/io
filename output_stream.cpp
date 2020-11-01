#include "output_stream.h"

#include "writer.h"

TOutputStream::TOutputStream()
{}

TOutputStream::~TOutputStream() {
    if (Buffer.GetSize() != 0) TWriter::WriteToStd(Buffer);
}

void TOutputStream::PutChar(char c) {
    Buffer[Buffer.GetSize()++] = c;
    if (Buffer.GetSize() == Buffer.PAGE_SIZE) {
        TWriter::WriteToStd(Buffer);
        Buffer.GetSize() = 0;
    }
}

TOutputStream& operator<<(TOutputStream& os, char c) {
    // os.PutChar(c);
    putchar_unlocked(c);
    return os;
}


TOutputStream& operator<<(TOutputStream& os, int v) {
    // for (const auto& c : std::to_string(v)) putchar_unlocked(c);
    uint64_t p = 1;
    if (v < 0) {
        os.PutChar('-');
        v *= -1;
    }
    while (v / p) p *= 10;
    p /= (p == 1 ? 1 : 10);
    while (p) {
        putchar_unlocked((v / p) % 10 + '0');
        // os.PutChar((v / p) % 10 + '0');
        p /= 10;
    }
    return os;
}

// #include <iostream>

//int main() {
//    std::ios::sync_with_stdio(false);
//    std::cin.tie(nullptr);
//    TOutputStream os;
//    int a = 0;
//    while (a < 1000000) {
//        os << a << '\n';
//        ++a;
//    }
//    return 0;
//}
