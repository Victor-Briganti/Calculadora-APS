#include "calculadora.hpp"
#include <string>

//============================================================================//
//                                      Public                                //
//============================================================================//

void Key::set_keyboard(Keyboard *kbrd) {
    keybrd = kbrd;
}

void KeyDigit::press(std::string str) {
    if (keybrd != nullptr &&str == symbol)
        keybrd->receive_digit(char_to_digit(str[0]));
}

void KeyOperator::press(std::string str) {
    if (keybrd != nullptr &&str == symbol)
        keybrd->receive_operator(str_to_op(str));
}

void KeyControl::press(std::string str) {
    if (keybrd != nullptr &&str == symbol)
        keybrd->receive_control(str_to_ctrl(str));
}
