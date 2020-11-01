#include <iostream>

#include "input_stream.h"

int main() {
    TInputStream is;
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    int v, b = 1;
    // std::cout << 0;
    while (is >> v){
        // std::cout << v << "\n";
        ++b;
    }
    return 0;
}
