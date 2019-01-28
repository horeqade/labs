#include "QueueOnList.h"
#include <iostream>

template <typename T>
QueueOnList<T>::QueueOnList()
    : first(nullptr), last(nullptr) {}

template <typename T>
void QueueOnList<T>::insert(const T pushed) {
  node* newTop = new node;
  if (first == nullptr) {
    newTop->data = pushed;
    newTop->next = nullptr;
    first = last = newTop;
  } else {
    newTop->data = pushed;
    newTop->next = nullptr;
    last->next = newTop;
    last = newTop;
  }
}

template <typename T>
T QueueOnList<T>::pop() {
  if (first == nullptr) {
    std::cout << "Error";
  } else {
    T data = first->data;
    first = first->next;
    return data;
  }
}

template <typename T>
bool QueueOnList<T>::isEmpty() {
  return (first == nullptr);
}

template <typename T>
T QueueOnList<T>::head() {
  return first->data;
}

template <typename T>
QueueOnList<T>::~QueueOnList() {
  node* current = first;

  while (current) {
    node* next = current->next;
    delete current;
    current = next;
  }

  first = nullptr;
}
