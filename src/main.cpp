#include "termio/RawTerminal.hpp"
#include "termio/ansi.hpp"
#include "termio/input.hpp"

#include <iostream>

// testing helper
std::string keyName(termio::Key k) {
    switch(k) {
        case termio::Key::ArrowUp:    return "ArrowUp";
        case termio::Key::ArrowDown:  return "ArrowDown";
        case termio::Key::ArrowLeft:  return "ArrowLeft";
        case termio::Key::ArrowRight: return "ArrowRight";
        case termio::Key::Enter:      return "Enter";
        case termio::Key::Backspace:  return "Backspace";
        case termio::Key::Escape:     return "Escape";
        case termio::Key::Tab:        return "Tab";
        case termio::Key::CtrlC:      return "CtrlC";
        case termio::Key::CtrlD:      return "CtrlD";
        default:                      return "Unknown";
    }
}

int main(int argc, char* argv[]){
    termio::RawTerminal terminal;

    std::cout << termio::success("libtermio initialized");
    std::cout << termio::info("Ctrl + C to quit");

    while(true){
        termio::Key k = termio::readKey();

        if (k == termio::Key::UNKNOWN) continue;
        if (k == termio::Key::CtrlC) break;
        std::cout << termio::colorize("got: ", termio::Color::CYAN) << keyName(k) << "\r\n";
    }

    return 0;
}