#pragma once
#ifndef QueueONLIST
#define QueueONLIST

template <typename T>
class QueueOnList {
 public:
  QueueOnList();
  ~QueueOnList();
  void insert(T pushed);
  bool isEmpty();
  T pop();
  T head();

 private:
  struct node {
    T data;
    node* next;
  };
  node* first{nullptr};
  node* last{nullptr};
};
#endif  // QueueONLIST