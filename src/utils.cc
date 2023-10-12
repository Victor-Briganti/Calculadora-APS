#include "calculadora.hpp"
#include <string>

Digit char_to_digit(char c) {
  switch (c) {
  case '0':
    return ZERO;
    break;
  case '1':
    return ONE;
    break;
  case '2':
    return TWO;
    break;
  case '3':
    return THREE;
    break;
  case '4':
    return FOUR;
    break;
  case '5':
    return FIVE;
    break;
  case '6':
    return SIX;
    break;
  case '7':
    return SEVEN;
    break;
  case '8':
    return EIGHT;
    break;
  case '9':
    return NINE;
    break;
  }
}

char digit_to_char(Digit dg) {
  switch (dg) {
  case ZERO:
    return '0';
    break;
  case ONE:
    return '1';
    break;
  case TWO:
    return '2';
    break;
  case THREE:
    return '3';
    break;
  case FOUR:
    return '4';
    break;
  case FIVE:
    return '5';
    break;
  case SIX:
    return '6';
    break;
  case SEVEN:
    return '7';
    break;
  case EIGHT:
    return '8';
    break;
  case NINE:
    return '9';
    break;
  }
}

Operator str_to_op(std::string op) {
  if (op == "+")
    return SUM;
  if (op == "-")
    return SUBTRACTION;
  if (op == "/")
    return DIVISION;
  if (op == "*")
    return MULTIPLICATION;
  if (op == "%")
    return PERCENTAGE;
  if (op == "sqrt")
    return SQUARE_ROOT;
}

std::string op_to_str(Operator op) {
  if (op == SUM)
    return "+";
  if (op == SUBTRACTION)
    return "-";
  if (op == DIVISION)
    return "/";
  if (op == MULTIPLICATION)
    return "*";
  if (op == PERCENTAGE)
    return "%";
  if (op == SQUARE_ROOT)
    return "sqrt";
}

Control str_to_ctrl(std::string ctrl) {
  if (ctrl == "off")
    return OFF;
  if (ctrl == "clear")
    return CLEAR_ERROR;
  if (ctrl == "mr")
    return MEMORY_READ;
  if (ctrl == "mc")
    return MEMORY_CLEAR;
  if (ctrl == "msum")
    return MEMORY_SUM;
  if (ctrl == "msub")
    return MEMORY_SUBTRACTION;
  if (ctrl == "=")
    return EQUAL;
  if (ctrl == ".")
    return DECIMAL_SEPARATOR;
}

std::string ctrl_to_str(Control ctrl) {
  if (ctrl == OFF)
    return "off";
  if (ctrl == CLEAR_ERROR)
    return "clear";
  if (ctrl == MEMORY_READ)
    return "mr";
  if (ctrl == MEMORY_CLEAR)
    return "mc";
  if (ctrl == MEMORY_SUM)
    return "msum";
  if (ctrl == MEMORY_SUBTRACTION)
    return "msub";
  if (ctrl == EQUAL)
    return "=";
  if (ctrl == DECIMAL_SEPARATOR)
    return ".";
}
