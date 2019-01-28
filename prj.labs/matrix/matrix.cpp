#include <iostream>

class matrix {
public:
  matrix() = default;
  ~matrix() {
    for (int i = 0; i < row_; i++) {
      delete[] data_[i];
    }
    delete[] data_;
  }
  matrix(const ptrdiff_t row, const ptrdiff_t col) {
    row_ = row;
    col_ = col;
    data_ = new int*[row_];
    for (int i = 0; i < row; i++) {
      data_[i] = new int[col];
      for (int j = 0; j < col; j++) {
        data_[i][j] = 0;
      }
    }
  }
  matrix(matrix& mat) {
    row_ = mat.row_;
    col_ = mat.col_;
    data_ = new int*[row_];
    for (int i = 0; i < row_; i++) {
      data_[i] = new int[col_];
      for (int j = 0; j < col_; j++) {
        data_[i][j] = mat.data_[i][j];
      }
    }
  }
  void set(const ptrdiff_t i, const ptrdiff_t j, int value) {
    data_[i][j] = value;
  }
  int get(const ptrdiff_t i, ptrdiff_t j) {
    return data_[i][j];
  }
private:
  int** data_{nullptr};
  ptrdiff_t row_{0};
  ptrdiff_t col_{0};
};

int main() {
  matrix mat1;

  matrix mat2 = matrix(3, 7);
  mat2.set(0, 0, 1);
  std::cout << mat2.get(0, 0) << std::endl;

  matrix mat3 = matrix(mat2);
  mat3.set(0, 0, 3);
  std::cout << mat3.get(0, 0) << " " << mat2.get(0, 0);
  return 0;
}