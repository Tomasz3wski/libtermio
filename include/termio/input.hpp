#pragma once


namespace termio{

enum class Key {ArrowUp, ArrowDown, ArrowLeft, ArrowRight, Enter, Backspace, Escape, Tab, CtrlC, CtrlD, UNKNOWN};

Key readKey();

}