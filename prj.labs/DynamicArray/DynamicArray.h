#pragma once
#ifndef DYNAMICARRAY
#define DYNAMICARRAY

// template <typename T>
class DynamicArray {
 public:
  DynamicArray() {}  // default ?
  DynamicArray(const int size) : data(new int[size]), size(size) {}
  DynamicArray(const DynamicArray& arr);
  ~DynamicArray();
  int operator[](const int i);
  int getlen();
  int getsize();
  void resize(const int newsize);

 private:
  int size{0};
  int len{0};
  int* data{nullptr};
};
#endif  // DynamicArray