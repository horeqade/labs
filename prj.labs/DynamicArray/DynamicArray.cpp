#include "DynamicArray.h"
#include <iostream>

// template <typename T>
int DynamicArray::getlen() { return len; }

int DynamicArray::getsize() { return size; }

// template<typename T>
DynamicArray::~DynamicArray() { delete[] data; }

// template<typename T>
int DynamicArray::operator[](const int i) { return this->data[i]; }

// template<typename T>
DynamicArray::DynamicArray(const DynamicArray& arr) {
  data = new int[arr.size];
  size = arr.size;
  for (int i = 0; i < len; i++) {
    data[i] = arr.data[i];
  }
  len = arr.len;
}

// template <typename T>
void DynamicArray::resize(const int newsize) {
  int* arr = new int[newsize];
  for (int i = 0; i < len; i++) {
    arr[i] = data[i];
  }
  data = arr;
  size = newsize;
}