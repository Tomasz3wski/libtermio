#include "termio/RawTerminal.hpp"

#include <unistd.h>
#include <iostream>

int main(int argc, char* argv[]){
    termio::RawTerminal terminal;

    char c;
    while(true){
        int n = read(STDIN_FILENO, &c, 1);

        if (n == 0) continue;
        if (c == 'q') break;

        std::cout << "got: " << (int)c << "\r\n";
    }

    return 0;
}