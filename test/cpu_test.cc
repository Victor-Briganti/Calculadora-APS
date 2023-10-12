#include "../src/calculadora.hpp"

void test_sum(Cpu &cp) {
  cp.send_digit(ONE);
  cp.send_operator(SUM);
  cp.send_digit(ONE);
  cp.send_control(EQUAL);
}

void test_sum_negative(Cpu &cp) {
  cp.send_operator(SUBTRACTION);
  cp.send_digit(ONE);
  cp.send_operator(SUM);
  cp.send_digit(ONE);
  cp.send_control(EQUAL);
}

void test_sub(Cpu &cp) {
  cp.send_digit(TWO);
  cp.send_operator(SUBTRACTION);
  cp.send_digit(NINE);
  cp.send_control(EQUAL);
}

void test_mult(Cpu &cp) {
  cp.send_digit(THREE);
  cp.send_operator(MULTIPLICATION);
  cp.send_digit(FOUR);
  cp.send_control(EQUAL);
}

void test_div(Cpu &cp) {
  cp.send_digit(THREE);
  cp.send_digit(FOUR);
  cp.send_digit(SIX);
  cp.send_operator(DIVISION);
  cp.send_digit(TWO);
  cp.send_control(EQUAL);
}

void test_percentage(Cpu &cp) {
  cp.send_digit(ONE);
  cp.send_digit(ZERO);
  cp.send_digit(ZERO);
  cp.send_operator(PERCENTAGE);
  cp.send_control(EQUAL);
}

void test_sqrt(Cpu &cp) {
  cp.send_digit(FOUR);
  cp.send_operator(SQUARE_ROOT);
  cp.send_control(EQUAL);
}

void test_sqrt_error(Cpu &cp) {
  cp.send_operator(SUBTRACTION);
  cp.send_digit(FIVE);
  cp.send_operator(SQUARE_ROOT);
  cp.send_control(EQUAL);
}

void test_div_error(Cpu &cp) {
  cp.send_digit(FIVE);
  cp.send_operator(DIVISION);
  cp.send_digit(ZERO);
  cp.send_control(EQUAL);
}

int main() {
  Cpu cp;
  cp.set_display(new Display);
  //   test_sum(cp);
  //   test_sum_negative(cp);
  //   test_sub(cp);
  //   test_mult(cp);
  //   test_div(cp);
  //   test_percentage(cp);
  //   test_sqrt(cp);
  //   test_sqrt_error(cp);
  test_div_error(cp);
}