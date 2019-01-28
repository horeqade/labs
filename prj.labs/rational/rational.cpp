#include "rational.h"
#include <iostream>
#include <sstream>

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) {
  return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) {
  return rhs.readFrom(istrm);
}

bool testParse(const std::string& str) {
  std::istringstream istrm(str);
  Rational z;
  istrm >> z;
  if (istrm.good()) {
    std::cout << "Read success: " << str << " -> " << z << std::endl;
  } else {
    std::cout << "Read error : " << str << " -> " << z << std::endl;
  }
  return istrm.good();
}

int gcd(int a, int b) {
  a = abs(a);
  b = abs(b);
  while (a != b) {
    if (a > b) {
      long tmp = a;
      a = b;
      b = tmp;
    }
    b = b - a;
  }
  return a;
}

Rational::Rational(const int num) : Rational(num, 1) {}

Rational::Rational(const int num1, const unsigned int denum1)
    : num(int(num1 / gcd(num1, denum1))),
      denum(int(denum1 / gcd(num1, denum1))) {
  if (denum < 0) {
    num *= -1;
    denum *= -1;
  }
  if (denum == 0) {
  }
}

Rational& Rational::operator*=(const Rational& rhs) {
  int temp_gcd = gcd(num * rhs.num, denum * rhs.denum);
  num = num * rhs.num / temp_gcd;
  denum = denum * rhs.denum / temp_gcd;
  return *this;
}

Rational Rational::operator+(const Rational& rhs) {
  Rational sum(*this);
  sum += rhs;
  return sum;
}

Rational Rational::operator-(const Rational& rhs) {
  Rational diff(*this);
  diff -= rhs;
  return diff;
}

Rational Rational::operator/(const Rational& rhs) {
  Rational div(*this);
  div /= rhs;
  return div;
}

Rational Rational::operator*(const Rational& rhs) {
  Rational mult(*this);
  mult *= rhs;
  return mult;
}

Rational& Rational::operator-=(const Rational& rhs) {
  bool sgn;
  if (num == rhs.num && denum == rhs.denum) {
    num = 0;
    denum = 1;
    return *this;
  }
}

Rational& Rational::operator+=(const Rational& rhs) {
  int lcm = denum * rhs.denum / gcd(denum, rhs.denum);
  int temp_num = (num * lcm / denum) + (rhs.num * lcm / rhs.denum);
  int temp_gcd = gcd(temp_num, lcm);
  num = int(temp_num / temp_gcd);
  denum = int(lcm / temp_gcd);
  return *this;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
  ostrm << leftBrace << num << separator << denum << rightBrace;
  return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
  char leftBrace(0);
  int nume(0);
  char comma(0);
  unsigned int denume(1);
  char rightBrace(0);
  istrm >> leftBrace >> nume >> comma >> denume >> rightBrace;
  if (istrm.good()) {
    if ((Rational::leftBrace == leftBrace) && (Rational::separator == comma) &&
        (Rational::rightBrace == rightBrace)) {
      num = nume;
      denum = denume;
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}
