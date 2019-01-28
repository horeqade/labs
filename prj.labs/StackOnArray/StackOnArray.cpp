#include <iostream>

class stack {
public:
  stack() = default;
  ~stack() {
    delete[] data_;
    data_ = nullptr;
  }
  void push(const int value) {
    if (capacity <= head + 1) {
      int* ndata = new int[capacity * 2 + 10];
      for (int i = 0; i < capacity; i++) {
        ndata[i] = data_[i];
      }
      delete[] data_;
      data_ = ndata;
      data_[head + 1] = value;
      head++;
      capacity = capacity * 2 + 10;
    }
    else {
      data_[head + 1] = value;
      head++;
    }
  }
  bool IsEmpty() {
    return (head == -1);
  }
  int pop() {
    if (IsEmpty()){
      throw ("Empty !");
    }
    else {
      head--;
      return data_[head + 1];
    }
  }
  int top() {
    if (IsEmpty()) {
      throw ("Empty !");
    }
    return data_[head];
  }
private:
  int* data_{ nullptr };
  ptrdiff_t head{ -1 };
  ptrdiff_t capacity{ 0 };
};

class point {
public:
  point() = default;
  point(int a, int b) {
    x = a;
    y = b;
  }
  std::ostream& WriteTo(std::ostream& ostrm) {
    ostrm << lbrace << x << comma << y << rbrace;
    return ostrm;
  }
  std::istream& WriteIn(std::istream& istrm) {
    char lb;
    char com;
    char rb;
    int xt;
    int yt;
    istrm >> lb >> xt >> com >> yt >> rb;
    if (lb == lbrace && com == comma && rb == rbrace)
    {
      x = xt;
      y = yt;
    }
    else {
      std::cout << "Wrong sentence !" << std::endl;
    }
    return istrm;
  }

private:
  char lbrace{ '(' };
  char comma{ ',' };
  char rbrace{ ')' };
  int x{ 0 };
  int y{ 0 };
};

inline std::ostream& operator<<(std::ostream& ostrm, point& p) {
  return p.WriteTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, point& p) {
  return p.WriteIn(istrm);
}

class QueueOnArray {
public:
  QueueOnArray() = default;
  ~QueueOnArray() {
    delete[] data_;
  }
  QueueOnArray(const QueueOnArray& q) {
    capacity = q.capacity;
    data_ = new int[capacity];
    for (int i = q.first; i <= q.last; i++) {
      data_[i - q.first] = q.data_[i];
    }
    last = q.last - q.first;
    first = 0;
  }
  QueueOnArray& operator=(const QueueOnArray& q) {
    if (&q == this) return *this;
    QueueOnArray tmp(q);
    std::swap(tmp.first, first);
    std::swap(tmp.last, last);
    std::swap(tmp.capacity, capacity);
    std::swap(tmp.data_, data_);
    return *this;

  }
  void push(int val) {
    if (last + 1 >= capacity) {
      int* nd = new int[(capacity + 1) * 2];
      for (int i = first; i <= last; i++) {
        nd[i - first] = data_[i];
      }
      nd[last - first + 1] = val;
      delete[] data_;
      data_ = nd;
      last = last - first + 1;
      first = 0;
      capacity = (capacity + 1) * 2;
    }
    else {
      last++;
      data_[last] = val;
    }
  }
  void pop() {
    if (IsEmpty()) return;

    first++;
  }
  int top() {
    if (first > last) {
      throw ("Error");
    }
    return data_[first];
  }
  bool IsEmpty() {
    return (first > last);
  }
private:
  int* data_{ nullptr };
  ptrdiff_t first{0};
  ptrdiff_t last{-1};
  ptrdiff_t capacity{ 0 };
};

int main() {
  /*stack s1;
  
  s1.push(1);
  std::cout << s1.pop();

  point p = point(5, 3);
  std::cout << p << std::endl;

  point p1;
  std::cin >> p1;
  std::cout << p1 << std::endl;
  */

  /* Queue On Array !
  QueueOnArray q1;
  q1.push(1);
  QueueOnArray q2(q1);
  QueueOnArray q3;
  q3 = q1;
  std::cout << q1.top() << std::endl;
  std::cout << q2.top() << std::endl;
  std::cout << q3.top() << std::endl;
  q1.pop();
  //std::cout << q1.top() << std::endl;
  std::cout << q2.top() << std::endl;
  std::cout << q3.top() << std::endl;
  */

  return 0;
}