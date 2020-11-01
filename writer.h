#pragma once

#include <cstdint>

#include <stdio.h>
#include <unistd.h>
#include "buffer.h"

class TWriter {
public:
    static void WriteTo(int fd, const TBuffer& buffer) {
        write(fd, buffer, buffer.GetSize());
    }
    static void WriteToStd(const TBuffer& buffer) {
        WriteTo(STDOUT_FILENO, buffer);
    }
};