#include "DynamicArray.h";
#include <iostream>

int main() {
  DynamicArray q;
  q.resize(6);
  std::cout << q.getsize();
  return 0;
}