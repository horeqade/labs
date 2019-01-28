#include "StackOnList.h"
#include <iostream>

template <typename T>
StackOnList<T>::StackOnList()
    : top(nullptr) {}

template <typename T>
void StackOnList<T>::pushback(const T pushed) {
  node* newTop = new node;
  if (top == nullptr) {
    newTop->data = pushed;
    newTop->next = top;
    top = newTop;
    count++;
  } else {
    newTop->data = pushed;
    newTop->next = top;
    top = newTop;
    count++;
  }
}

template <typename T>
T StackOnList<T>::pop() {
  if (top == nullptr) {
    std::cout << "Error";
  } else {
    node* old = top;
    top = top->next;
    count--;
    return old->data;
  }
}

template <typename T>
bool StackOnList<T>::isEmpty() {
  return (top == nullptr);
}

template <typename T>
T StackOnList<T>::head() {
  return top->data;
}

template <typename T>
StackOnList<T>::~StackOnList() {
  node* current = top;

  while (current) {
    node* next = current->next;
    delete current;
    current = next;
  }

  top = nullptr;
}
