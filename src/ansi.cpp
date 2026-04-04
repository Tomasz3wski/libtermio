#include "termio/ansi.hpp"

#include <string>
#include <unordered_map>

namespace termio{

std::string colorize(const std::string& text, Color color){
    static const std::unordered_map<Color, std::string> colorMap {
        {Color::RED,        "\033[31m"},
        {Color::GREEN,      "\033[32m"},
        {Color::YELLOW,     "\033[33m"},
        {Color::BLUE,       "\033[34m"},
        {Color::MAGENTA,    "\033[35m"},
        {Color::CYAN,       "\033[36m"},
        {Color::WHITE,      "\033[37m"},
        {Color::GRAY,       "\033[90m"},
        {Color::RESET,      "\033[0m"}
    };

    return colorMap.at(color) + text + colorMap.at(Color::RESET);
}

std::string success(const std::string& message){
    return "\u2713 " + colorize(message, Color::GREEN) + "\r\n";
}

std::string error(const std::string& message){
    return "\u2717 " + colorize(message, Color::RED) + "\r\n";
}

std::string info(const std::string& message){
    return "\u2192 " + colorize(message, Color::BLUE) + "\r\n";
}

std::string warning(const std::string& message){
    return "\u26A0 " + colorize(message, Color::YELLOW) + "\r\n";
}

}