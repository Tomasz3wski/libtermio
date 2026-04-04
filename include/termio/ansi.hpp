#pragma once

#include <string>

namespace termio{

enum class Color {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, GRAY, RESET};

std::string colorize(const std::string& text, Color color);

std::string success(const std::string& message);
std::string error(const std::string& message);
std::string info(const std::string& message);
std::string warning(const std::string& message);

}