#include "calculadora.hpp"
#include <iostream>

//============================================================================//
//                                      Private                               //
//============================================================================//

void Display::flush() {
  sizeBuffer = 0;
  decimalFlag = 0;
  memFlag = 0;
  negativeFlag = 0;
}

//============================================================================//
//                                      Public                                //
//============================================================================//

Display::Display() { 
  this->clear_buffer();
  this->print();
}

void Display::add(char c) {
  if (clearedFlag) {
    buffer[0] = c;
    clearedFlag = 0;
    sizeBuffer++;
    return;
  }
  if (sizeBuffer == 8)
    return;
  buffer[sizeBuffer++] = c;
}

void Display::decimal_separator() {
  if (decimalFlag || sizeBuffer == 8)
    return;

  decimalFlag++;
  buffer[sizeBuffer++] = '.';
}

void Display::print() {
  for (int i = 0; i < (8 - sizeBuffer); i++)
    std::cout << ' ';
  for (int i = 0; i < sizeBuffer; i++)
    std::cout << buffer[i];
  std::cout << std::endl;
}

void Display::clear() {
  this->flush();
  this->print();
}

void Display::clear_buffer() {
  this->flush();
  buffer[0] = '0';
  clearedFlag = 1;
}

void Display::error() {
  this->flush();
  buffer[0] = 'E';
  buffer[1] = 'R';
  buffer[2] = 'R';
  buffer[3] = 'O';
  buffer[4] = 'R';
  sizeBuffer = 5;
  this->print();
}

void Display::set_negative() { this->negativeFlag = 1; }

void Display::set_mem() { this->memFlag = 1; }