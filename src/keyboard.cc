#include "calculadora.hpp"
#include <string>

//============================================================================//
//                                      Public                                //
//============================================================================//

Keyboard::Keyboard() {
  for (int dg = ZERO; dg != NINE; dg++)
    keyArray[dg] = new KeyDigit(std::to_string(digit_to_char((Digit)dg)), (Digit)dg);

  for (int op = SUM; op != SQUARE_ROOT; op++)
    keyArray[op] = new KeyOperator(op_to_str((Operator)op), (Operator)op);

  for (int ctrl = ON; ctrl != DECIMAL_SEPARATOR; ctrl++)
    keyArray[ctrl] = new KeyControl(ctrl_to_str((Control)ctrl), (Control)ctrl);
}

Keyboard::~Keyboard() {
  for (int i = 0; i < 24; i++)
    delete keyArray[i];
}

void Keyboard::set_cpu(Cpu *cp) { cpu = cp; }

void Keyboard::receive_digit(Digit dg) {
  if (cpu != nullptr)
    cpu->receive_digit(dg);
}

void Keyboard::receive_operator(Operator op) {
  if (cpu != nullptr)
    cpu->receive_operator(op);
}

void Keyboard::receive_control(Control ctrl) {
  if (cpu != nullptr)
    cpu->receive_control(ctrl);
}

void Keyboard::receive_error() {
  if (cpu != nullptr)
    cpu->receive_error();
}