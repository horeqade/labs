#include "QueueOnList.h";
#include "QueueOnList.hpp"
#include <iostream>

int main() {
  QueueOnList<int> queue;
  queue.insert(1);
  queue.insert(2);
  std::cout << queue.head();
  std::cout << queue.pop();
  std::cout << queue.head();
  std::cout << queue.isEmpty();
  std::cout << queue.pop();
  std::cout << queue.isEmpty();
  return 0;
}