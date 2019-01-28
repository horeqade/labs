#pragma once
#ifndef STACKONLIST
#define STACKONLIST

template <typename T>
class StackOnList {
 public:
  StackOnList();
  StackOnList(size_t size);
  ~StackOnList();
  void pushback(T pushed);
  bool isEmpty();
  T pop();
  T head();

 private:
  struct node {
    T data;
    node* next;
  };
  node* top{nullptr};
};
#endif  // STACKONLIST