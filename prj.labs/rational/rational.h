#pragma once
#ifndef RATIONAL
#define RATIONAL

#include <iosfwd>
#include <string>

struct Rational {
  Rational() {}
  explicit Rational(const int num);
  Rational(const int num, const unsigned int denum);
  bool operator==(const Rational& rhs) const {
    return (num == rhs.num) && (denum == rhs.denum);
  }
  bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
  Rational& operator*=(const int rhs) { return operator*=(Rational(rhs)); }
  Rational& operator-=(const int rhs) { return operator-=(Rational(rhs)); }
  Rational& operator+=(const int rhs) { return operator+=(Rational(rhs)); }
  Rational& operator/=(const int rhs) { return operator/=(Rational(rhs)); }
  Rational& operator-=(const Rational& rhs);
  Rational& operator+=(const Rational& rhs);
  Rational& operator*=(const Rational& rhs);
  Rational& operator/=(const Rational& rhs) {
    return operator*=(Rational(rhs.denum, rhs.num));
  }
  std::ostream& writeTo(std::ostream& ostrm) const;
  std::istream& readFrom(std::istream& istrm);
  Rational operator+(const Rational& rhs);
  Rational operator-(const Rational& rhs);
  Rational operator/(const Rational& rhs);
  Rational operator*(const Rational& rhs);
  int num{0};
  int denum{1};

  static const char leftBrace{'{'};
  static const char separator{'/'};
  static const char rightBrace{'}'};
};
bool testParse(const std::string& str);
int gcd(int a, int b);

#endif  // RATIONAL