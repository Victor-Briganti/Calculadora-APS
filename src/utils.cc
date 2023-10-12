#include "calculadora.hpp"

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
    switch(dg) {
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