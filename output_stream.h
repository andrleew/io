#pragma once

#include "buffer.h"
#include <string>

class TOutputStream {
public:
    TOutputStream();
    ~TOutputStream();

    void PutChar(char c);

private:
    TBuffer Buffer;
    uint64_t Begin;
};

TOutputStream& operator<<(TOutputStream& os, char c);

TOutputStream& operator<<(TOutputStream& os, int v);