#include "termio/RawTerminal.hpp"

#include <termios.h>
#include <unistd.h>

namespace termio{

RawTerminal::RawTerminal() : ttyfd(STDIN_FILENO){
    if (tcgetattr(ttyfd, &orgTermios) == -1) return;
    active = true;

    struct termios raw = orgTermios;

    raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
    raw.c_oflag &= ~(OPOST);
    raw.c_cflag |= (CS8);
    raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

    raw.c_cc[VMIN] = 0; raw.c_cc[VTIME] = 1;

    tcsetattr(ttyfd, TCSAFLUSH, &raw);
}

RawTerminal::~RawTerminal(){
    if(active) tcsetattr(ttyfd, TCSAFLUSH, &orgTermios);
}


}