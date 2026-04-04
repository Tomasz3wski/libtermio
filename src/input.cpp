#include "termio/input.hpp"

#include "unistd.h"

namespace termio{

Key readKey(){
    char c;
    read(STDIN_FILENO, &c, 1);

    switch (c){
        case '\r': return Key::Enter;
        case 127: return Key::Backspace;
        case '\x1b': {
            char seq[2];
            if (read(STDIN_FILENO, &seq[0], 1) == 0) return Key::Escape;
            if (read(STDIN_FILENO, &seq[1], 1) == 0) return Key::Escape;

            if (seq[0] == '['){
                switch(seq[1]){
                    case 'A': return Key::ArrowUp;
                    case 'B': return Key::ArrowDown;
                    case 'C': return Key::ArrowRight;
                    case 'D': return Key::ArrowLeft;
                }
            }
            return Key::Escape;
        }
        case 3: return Key::CtrlC;
        case 4: return Key::CtrlD;
        case 9: return Key::Tab;
        default: return Key::UNKNOWN;
    }
}

}