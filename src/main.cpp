#include "termio/RawTerminal.hpp"
#include "termio/ansi.hpp"

#include <unistd.h>
#include <iostream>

int main(int argc, char* argv[]){
    termio::RawTerminal terminal;

    std::cout << termio::success("libtermio initialized");
    std::cout << termio::info("q to quit");

    char c;
    while(true){
        int n = read(STDIN_FILENO, &c, 1);

        if (n == 0) continue;
        if (c == 'q') break;

        std::cout << termio::colorize("got: ", termio::Color::CYAN) << (int)c << "\r\n";
    }

    return 0;
}