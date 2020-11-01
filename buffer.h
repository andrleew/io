#pragma once

#include <cstdlib>
#include <cstdint>

class TBuffer {
public:
    TBuffer()
    : Size(0){
        Buffer = reinterpret_cast<char*>(malloc(PAGE_SIZE));
    }

    ~TBuffer() {
        free(Buffer);
    }

    inline bool Empty() const {
        return Size == 0;
    }

    inline const size_t& GetSize() const {
        return Size;
    }

    inline size_t& GetSize() {
        return Size;
    }

    inline operator char*() {
        return Buffer;
    }

    inline operator char*const() const {
        return Buffer;
    }

    inline char operator[](size_t id) const {
        return Buffer[id];
    }

    inline char& operator[](size_t id) {
        return Buffer[id];
    }

public:
    static const size_t PAGE_SIZE = 4096;


private:
    size_t Size;
    char* Buffer;
};