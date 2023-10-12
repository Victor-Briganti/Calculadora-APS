#include "../src/calculadora.hpp"
#include <iostream>

void test1(Display &ds) {
  ds.clear();
  ds.add(ZERO);
  ds.add(ONE);
  ds.add(TWO);
  ds.decimal_separator();
  ds.add(SIX);
  ds.print();
}
void test2(Display &ds) {
  ds.clear();
  ds.add(SIX);
  ds.add(SEVEN);
  ds.decimal_separator();
  ds.add(TWO);
  ds.decimal_separator();
  ds.add(SIX);
  ds.add(EIGHT);
  ds.print();
}

void test3(Display &ds) {
  ds.clear();
  ds.add(SIX);
  ds.decimal_separator();
  ds.add(ZERO);
  ds.add(ONE);
  ds.add(TWO);
  ds.decimal_separator();
  ds.add(SIX);
  ds.decimal_separator();
  ds.add(SIX);
  ds.add(EIGHT);
  ds.print();
}

void test_error(Display &ds) {
  ds.clear();
  ds.error();
  ds.print();
}
int main() {
  Display ds;
  test1(ds);
  test2(ds);
  test3(ds);
  test_error(ds);
  ds.clear();
}