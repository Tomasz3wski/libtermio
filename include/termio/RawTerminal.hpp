
#include <termios.h>

namespace termio{

class RawTerminal{
public:
    RawTerminal();
    ~RawTerminal();

    RawTerminal(const RawTerminal&) = delete;
    void operator=(const RawTerminal&) = delete;
    RawTerminal& operator=(RawTerminal&&) = delete;
    RawTerminal(RawTerminal&&) = default;

private:
    struct termios orgTermios;
    int ttyfd;
    bool active;
};

}