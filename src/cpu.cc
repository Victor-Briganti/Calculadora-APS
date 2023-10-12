#include "calculadora.hpp"
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <string>

//============================================================================//
//                                      Private                               //
//============================================================================//

//*********************************** HELPERS ********************************//

void Cpu::result() {
  if (displ == nullptr)
    return;
  if (errorFlag) {
    displ->error();
    return;
  }
  displ->clear_buffer();
  if (reg1.size() < 8) {
    for (size_t i = 0; i < reg1.size(); i++) {
      if (reg1[i] == '.')
        displ->decimal_separator();
      else
        displ->add(reg1[i]);
    }
  } else {
    for (size_t i = 0; i < 8; i++) {
      if (reg1[i] == '.')
        displ->decimal_separator();
      else
        displ->add(reg1[i]);
    }
  }
  displ->print();
}

void Cpu::error() {
  reg1.clear();
  reg2.clear();
  if (displ != nullptr)
    displ->error();
}

double Cpu::reg1_to_double() {
  if (reg1Sign == NEGATIVE)
    return (std::atof(reg1.c_str()) * -1);
  return std::atof(reg1.c_str());
}

double Cpu::reg2_to_double() {
  if (reg2Sign == NEGATIVE)
    return (std::atof(reg2.c_str()) * -1);
  return std::atof(reg2.c_str());
}

//*********************************** OPERATORS ******************************//
void Cpu::add() {
  auto result = reg2_to_double() + reg1_to_double();
  if (result < 0) {
    if (displ != nullptr)
      displ->set_negative();
    reg1Sign = NEGATIVE;
    result *= -1;
  }
  reg1 = std::to_string(result);
}

void Cpu::sub() {
  auto result = reg2_to_double() - reg1_to_double();
  if (result < 0) {
    if (displ != nullptr)
      displ->set_negative();
    reg1Sign = NEGATIVE;
    result *= -1;
  }
  reg1 = std::to_string(result);
}

void Cpu::div() {
  auto reg1_double = reg1_to_double();
  if (reg1_double == 0) {
    errorFlag = true;
    return;
  }
  auto result = reg2_to_double() / reg1_double;
  if (result < 0) {
    if (displ != nullptr)
      displ->set_negative();
    reg1Sign = NEGATIVE;
    result *= -1;
  }
  reg1 = std::to_string(result);
}

void Cpu::mult() {
  auto result = reg2_to_double() * reg1_to_double();
  if (result < 0) {
    if (displ != nullptr)
      displ->set_negative();
    reg1Sign = NEGATIVE;
    result *= -1;
  }
  reg1 = std::to_string(result);
}

void Cpu::sqrt() {
  if (reg1Sign == NEGATIVE) {
    errorFlag = true;
    return;
  }
  auto reg1_double = reg1_to_double();
  reg1 = std::to_string(std::sqrt(reg1_double));
}

void Cpu::percen() {
  auto result = reg1_to_double() / 100;
  if (result < 0) {
    if (displ != nullptr)
      displ->set_negative();
    reg1Sign = NEGATIVE;
    result *= -1;
  }
  reg1 = std::to_string(result);
}

//******************************** MEMORY CONTROL ****************************//
// TODO: Precisamos revisar o que a memória faz
void Cpu::mem_read() { mem = reg1; }

void Cpu::mem_sum() {
  mem = std::to_string(std::atof(mem.c_str()) + reg1_to_double());
}

void Cpu::mem_sub() {
  mem = std::to_string(std::atof(mem.c_str()) - reg1_to_double());
}

void Cpu::mem_clear() { mem = "0"; }

//************************************ OTHERS ********************************//
void Cpu::decimal_separator() { displ->decimal_separator(); }

void Cpu::clear() {
  reg1 = "0";
  reg2 = "0";
  if (displ != nullptr)
    displ->clear();
}

void Cpu::equal() {
  switch (currentOp) {
  case SUM:
    add();
    break;
  case SUBTRACTION:
    sub();
    break;
  case DIVISION:
    div();
    break;
  case MULTIPLICATION:
    mult();
    break;
  case PERCENTAGE:
    percen();
    break;
  case SQUARE_ROOT:
    sqrt();
    break;
  default:
    break;
  }
  result();
}

//============================================================================//
//                                      Public                                //
//============================================================================//
Cpu::Cpu() {
  reg1Sign = POSITIVE;
  reg2Sign = POSITIVE;
  errorFlag = false;
}

Cpu::~Cpu() { delete displ; }

void Cpu::set_display(Display *ds) { displ = ds; }

void Cpu::receive_digit(Digit dg) {
  char c = digit_to_char(dg);
  reg1.push_back(c);
  if (displ != nullptr) {
    displ->add(c);
    displ->print();
  }
}

void Cpu::receive_control(Control ctrl) {
  switch (ctrl) {
  case CLEAR_ERROR:
    clear();
    break;
  case MEMORY_READ:
    mem_read();
    break;
  case MEMORY_CLEAR:
    mem_clear();
    break;
  case MEMORY_SUM:
    mem_sum();
    break;
  case MEMORY_SUBTRACTION:
    mem_sub();
    break;
  case EQUAL:
    equal();
    break;
  case DECIMAL_SEPARATOR:
    decimal_separator();
    break;
  case OFF:
    off();
  }
}

void Cpu::receive_operator(Operator op) {
  if (reg1.empty() && reg2.empty()) {
    if (op == SUBTRACTION) {
      if (displ != nullptr)
        displ->set_negative();
      reg1Sign = NEGATIVE;
    } else
      error();
    return;
  }
  if (reg2.empty() && !reg1.empty()) {
    switch (op) {
    case SUM:
    case SUBTRACTION:
    case DIVISION:
    case MULTIPLICATION:
      reg2 = std::move(reg1);
      reg2Sign = reg1Sign;
      reg1Sign = POSITIVE;
      reg1.clear();
      if (displ != nullptr)
        displ->clear_buffer();
      break;
    default:
      break;
    }
  }
  currentOp = op;
}

void Cpu::receive_error() { error(); }