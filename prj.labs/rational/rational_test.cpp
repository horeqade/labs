#include "rational.h";
#include <iostream>

int main() {
  int a = 1;
  int* b = &a;
  int c = *b;
  std::cout << c;
  Rational z;
  z += Rational(8);
  Rational w = Rational(1) - Rational(2);
  w.writeTo(std::cout);
  testParse("{8/9}");
  testParse("{1/3}");
  testParse("{1/0}");
  z.writeTo(std::cout);
  Rational r1 = Rational(1, 2);
  Rational r2 = Rational(1, 3);
  Rational r3 = r1 + r2;
  r3.writeTo(std::cout);
  (r1 + r2).writeTo(std::cout);
  (r1 * r2).writeTo(std::cout);
  (r1 / r2).writeTo(std::cout);
  (r1 - r2).writeTo(std::cout);
  (r2 - r1).writeTo(std::cout);
  return 0;
}