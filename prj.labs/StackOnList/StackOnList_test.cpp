#include "StackOnList.h";
#include "StackOnList.hpp"
#include <iostream>

int main() {
  StackOnList<int> stack(StackOnList<int>(5));
  stack.pushback(1);
  std::cout << stack.head();
  std::cout << stack.pop();
  std::cout << stack.isEmpty();
  return 0;
}