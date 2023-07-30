#include <cassert>
#include <vector>

template <typename T>
class Matrix {
 private:
  int row_, col_;

 public:
  std::vector<std::vector<T>> m_;

  Matrix(int row, int col) : row_(row), col_(col), m_() {}

  Matrix(int row, int col, T x)
      : row_(row), col_(col), m_(row, std::vector<T>(col)) {
    for (int i = 0; i < row_; i++) {
      for (int j = 0; j < col_; j++) m_[i][j] = x;
    }
  }

  Matrix(std::vector<std::vector<T>> &m)
      : row_((int)m.size()), col_((int)m[0].size()), m_(m) {}

  Matrix(std::initializer_list<std::vector<T>> init) : m_(init) {
    row_ = (int)m_.size();
    col_ = (int)m_[0].size();
  }

  bool operator==(const Matrix &x) {
    if (row_ != x.n || col_ != x.m) return false;
    for (int i = 0; i < row_; i++) {
      for (int j = 0; j < col_; j++) {
        if (m_[i][j] != x[i][j]) return false;
      }
    }
    return true;
  }

  Matrix &operator=(const Matrix &x) = default;

  Matrix operator+(const Matrix &x) {
    assert(row_ == x.row_ && col_ == x.col_);
    Matrix res(m_);
    for (int i = 0; i < row_; i++) {
      for (int j = 0; j < col_; j++) {
        res.m_[i][j] += x.m_[i][j];
      }
    }
    return res;
  }

  Matrix operator-(const Matrix &x) {
    assert(row_ == x.row_ && col_ == x.col_);
    Matrix res(m_);
    for (int i = 0; i < row_; i++) {
      for (int j = 0; j < col_; j++) {
        res.m_[i][j] -= x.m_[i][j];
      }
    }
    return res;
  }

  Matrix operator*(const Matrix &x) {
    assert(col_ == x.row_);
    Matrix res(row_, x.col_, T());
    for (int i = 0; i < row_; i++) {
      for (int k = 0; k < col_; k++) {
        for (int j = 0; j < x.col_; j++) {
          res.m_[i][j] += m_[i][k] * x.m_[k][j];
        }
      }
    }
    return res;
  }

  std::vector<T> operator*(const std::vector<T> &v) {
    assert(col_ == (int)v.size());
    std::vector<T> res(row_, 0);
    for (int i = 0; i < row_; i++) {
      for (int j = 0; j < col_; j++) {
        res[i] += m_[i][j] * v[j];
      }
    }
    return res;
  }

  Matrix &operator+=(const Matrix &x) {
    *this = *this + x;
    return *this;
  }

  Matrix &operator-=(const Matrix &x) {
    *this = *this - x;
    return *this;
  }

  Matrix &operator*=(const Matrix &x) {
    *this = *this * x;
    return *this;
  }

  T &operator()(long long i, long long j) { return m_[i][j]; }

  std::vector<T> &operator[](long long i) { return m_[i]; }

  Matrix pow(long long k) {
    assert(k >= 0);
    assert(row_ == col_);
    std::vector<std::vector<T>> x(row_, std::vector<T>(row_));
    for (int i = 0; i < row_; i++) x[i][i] = 1;
    Matrix res(x), tmp = *this;
    while (k) {
      if (k & 1) res *= tmp;
      k >>= 1;
      tmp *= tmp;
    }
    return res;
  }

  Matrix transpose() {
    Matrix<T> ret(col_, row_, 0);
    for (int i = 0; i < col_; i++) {
      for (int j = 0; j < row_; j++) {
        ret[i][j] = (*this)[j][i];
      }
    }
    return ret;
  }
};

template <typename T>
Matrix<T> DiagonalMatrix(const int n, const T d) {
  Matrix<T> res(n, n);
  for (int i = 0; i < n; i++) res.m_[i][i] = d;
  return res;
}

template <typename T>
Matrix<T> IdentityMatrix(const int n) {
  return diag(n, T(1));
}