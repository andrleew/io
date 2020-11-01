#pragma once

#include "buffer.h"

#include <cstdint>
#include <unistd.h>
#include <utility>

class TReader {
public:
    static const uint64_t PAGE_SIZE = 4096;

public:
    static void ReadFrom(int fd, TBuffer& buffer) {
        // if (buffer.GetSize() < PAGE_SIZE) {
        //     buffer.GetSize() = 0;
        //     return;
        // }
        buffer.GetSize() = static_cast<size_t>(read(fd, buffer, buffer.PAGE_SIZE));
    }
    inline static void ReadFromStd(TBuffer& buffer) {
        ReadFrom(STDIN_FILENO, buffer);
    }
};
