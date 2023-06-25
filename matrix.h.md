---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: h
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"matrix.h\"\ntemplate<typename T>\nclass Matrix {\nprivate:\n\
    \    int row_, col_;\n\npublic:\n\n    std::vector<std::vector<T>> m_;\n\n   \
    \ Matrix(int row, int col) : row_(row), col_(col), m_() {}\n\n    Matrix(int row,\
    \ int col, T x) : row_(row), col_(col), m_(row, std::vector<T>(col)) {\n     \
    \   for (int i = 0; i < row_; i++) {\n            for (int j = 0; j < col_; j++)\
    \ m_[i][j] = x;\n        }\n    }\n\n    Matrix(std::vector<std::vector<T>> &m)\
    \ : row_((int) m.size()), col_((int) m[0].size()), m_(m) {}\n\n    Matrix(std::initializer_list<std::vector<T>\
    \ > init) : m_(init) {\n        row_ = (int) m_.size();\n        col_ = (int)\
    \ m_[0].size();\n    }\n\n    bool operator==(const Matrix &x) {\n        if (row_\
    \ != x.n || col_ != x.m) return false;\n        for (int i = 0; i < row_; i++)\
    \ {\n            for (int j = 0; j < col_; j++) {\n                if (m_[i][j]\
    \ != x[i][j]) return false;\n            }\n        }\n        return true;\n\
    \    }\n\n    Matrix &operator=(const Matrix &x) = default;\n\n    Matrix operator+(const\
    \ Matrix &x) {\n        assert(row_ == x.row_ && col_ == x.col_);\n        Matrix\
    \ res(m_);\n        for (int i = 0; i < row_; i++) {\n            for (int j =\
    \ 0; j < col_; j++) {\n                res.m_[i][j] += x.m_[i][j];\n         \
    \   }\n        }\n        return res;\n    }\n\n    Matrix operator-(const Matrix\
    \ &x) {\n        assert(row_ == x.row_ && col_ == x.col_);\n        Matrix res(m_);\n\
    \        for (int i = 0; i < row_; i++) {\n            for (int j = 0; j < col_;\
    \ j++) {\n                res.m_[i][j] -= x.m_[i][j];\n            }\n       \
    \ }\n        return res;\n    }\n\n    Matrix operator*(const Matrix &x) {\n \
    \       assert(col_ == x.row_);\n        Matrix res(row_, x.col_, T());\n    \
    \    for (int i = 0; i < row_; i++) {\n            for (int k = 0; k < col_; k++)\
    \ {\n                for (int j = 0; j < x.col_; j++) {\n                    res.m_[i][j]\
    \ += m_[i][k] * x.m_[k][j];\n                }\n            }\n        }\n   \
    \     return res;\n    }\n\n    std::vector<T> operator*(const std::vector<T>\
    \ &v) {\n        assert(col_ == (int) v.size());\n        std::vector<T> res(row_,\
    \ 0);\n        for (int i = 0; i < row_; i++) {\n            for (int j = 0; j\
    \ < col_; j++) {\n                res[i] += m_[i][j] * v[j];\n            }\n\
    \        }\n        return res;\n    }\n\n    Matrix &operator+=(const Matrix\
    \ &x) {\n        *this = *this + x;\n        return *this;\n    }\n\n    Matrix\
    \ &operator-=(const Matrix &x) {\n        *this = *this - x;\n        return *this;\n\
    \    }\n\n    Matrix &operator*=(const Matrix &x) {\n        *this = *this * x;\n\
    \        return *this;\n    }\n\n    T &operator()(long long i, long long j) {\n\
    \        return m_[i][j];\n    }\n\n    std::vector<T> &operator[](long long i)\
    \ {\n        return m_[i];\n    }\n\n    Matrix pow(long long k) {\n        assert(k\
    \ >= 0);\n        assert(row_ == col_);\n        std::vector<std::vector<T>> x(row_,\
    \ std::vector<T>(row_));\n        for (int i = 0; i < row_; i++)\n           \
    \ x[i][i] = 1;\n        Matrix res(x), tmp = *this;\n        while (k) {\n   \
    \         if (k & 1)\n                res *= tmp;\n            k >>= 1;\n    \
    \        tmp *= tmp;\n        }\n        return res;\n    }\n\n    Matrix transpose()\
    \ {\n        Matrix<T> ret(col_, row_, 0);\n        for (int i = 0; i < col_;\
    \ i++) {\n            for (int j = 0; j < row_; j++) {\n                ret[i][j]\
    \ = (*this)[j][i];\n            }\n        }\n        return ret;\n    }\n};\n\
    \ntemplate<typename T>\nMatrix<T> DiagonalMatrix(const int n, const T d) {\n \
    \   Matrix<T> res(n, n);\n    for (int i = 0; i < n; i++)\n        res.m_[i][i]\
    \ = d;\n    return res;\n}\n\ntemplate<typename T>\nMatrix<T> IdentityMatrix(const\
    \ int n) {\n    return diag(n, T(1));\n}\n"
  code: "template<typename T>\nclass Matrix {\nprivate:\n    int row_, col_;\n\npublic:\n\
    \n    std::vector<std::vector<T>> m_;\n\n    Matrix(int row, int col) : row_(row),\
    \ col_(col), m_() {}\n\n    Matrix(int row, int col, T x) : row_(row), col_(col),\
    \ m_(row, std::vector<T>(col)) {\n        for (int i = 0; i < row_; i++) {\n \
    \           for (int j = 0; j < col_; j++) m_[i][j] = x;\n        }\n    }\n\n\
    \    Matrix(std::vector<std::vector<T>> &m) : row_((int) m.size()), col_((int)\
    \ m[0].size()), m_(m) {}\n\n    Matrix(std::initializer_list<std::vector<T> >\
    \ init) : m_(init) {\n        row_ = (int) m_.size();\n        col_ = (int) m_[0].size();\n\
    \    }\n\n    bool operator==(const Matrix &x) {\n        if (row_ != x.n || col_\
    \ != x.m) return false;\n        for (int i = 0; i < row_; i++) {\n          \
    \  for (int j = 0; j < col_; j++) {\n                if (m_[i][j] != x[i][j])\
    \ return false;\n            }\n        }\n        return true;\n    }\n\n   \
    \ Matrix &operator=(const Matrix &x) = default;\n\n    Matrix operator+(const\
    \ Matrix &x) {\n        assert(row_ == x.row_ && col_ == x.col_);\n        Matrix\
    \ res(m_);\n        for (int i = 0; i < row_; i++) {\n            for (int j =\
    \ 0; j < col_; j++) {\n                res.m_[i][j] += x.m_[i][j];\n         \
    \   }\n        }\n        return res;\n    }\n\n    Matrix operator-(const Matrix\
    \ &x) {\n        assert(row_ == x.row_ && col_ == x.col_);\n        Matrix res(m_);\n\
    \        for (int i = 0; i < row_; i++) {\n            for (int j = 0; j < col_;\
    \ j++) {\n                res.m_[i][j] -= x.m_[i][j];\n            }\n       \
    \ }\n        return res;\n    }\n\n    Matrix operator*(const Matrix &x) {\n \
    \       assert(col_ == x.row_);\n        Matrix res(row_, x.col_, T());\n    \
    \    for (int i = 0; i < row_; i++) {\n            for (int k = 0; k < col_; k++)\
    \ {\n                for (int j = 0; j < x.col_; j++) {\n                    res.m_[i][j]\
    \ += m_[i][k] * x.m_[k][j];\n                }\n            }\n        }\n   \
    \     return res;\n    }\n\n    std::vector<T> operator*(const std::vector<T>\
    \ &v) {\n        assert(col_ == (int) v.size());\n        std::vector<T> res(row_,\
    \ 0);\n        for (int i = 0; i < row_; i++) {\n            for (int j = 0; j\
    \ < col_; j++) {\n                res[i] += m_[i][j] * v[j];\n            }\n\
    \        }\n        return res;\n    }\n\n    Matrix &operator+=(const Matrix\
    \ &x) {\n        *this = *this + x;\n        return *this;\n    }\n\n    Matrix\
    \ &operator-=(const Matrix &x) {\n        *this = *this - x;\n        return *this;\n\
    \    }\n\n    Matrix &operator*=(const Matrix &x) {\n        *this = *this * x;\n\
    \        return *this;\n    }\n\n    T &operator()(long long i, long long j) {\n\
    \        return m_[i][j];\n    }\n\n    std::vector<T> &operator[](long long i)\
    \ {\n        return m_[i];\n    }\n\n    Matrix pow(long long k) {\n        assert(k\
    \ >= 0);\n        assert(row_ == col_);\n        std::vector<std::vector<T>> x(row_,\
    \ std::vector<T>(row_));\n        for (int i = 0; i < row_; i++)\n           \
    \ x[i][i] = 1;\n        Matrix res(x), tmp = *this;\n        while (k) {\n   \
    \         if (k & 1)\n                res *= tmp;\n            k >>= 1;\n    \
    \        tmp *= tmp;\n        }\n        return res;\n    }\n\n    Matrix transpose()\
    \ {\n        Matrix<T> ret(col_, row_, 0);\n        for (int i = 0; i < col_;\
    \ i++) {\n            for (int j = 0; j < row_; j++) {\n                ret[i][j]\
    \ = (*this)[j][i];\n            }\n        }\n        return ret;\n    }\n};\n\
    \ntemplate<typename T>\nMatrix<T> DiagonalMatrix(const int n, const T d) {\n \
    \   Matrix<T> res(n, n);\n    for (int i = 0; i < n; i++)\n        res.m_[i][i]\
    \ = d;\n    return res;\n}\n\ntemplate<typename T>\nMatrix<T> IdentityMatrix(const\
    \ int n) {\n    return diag(n, T(1));\n}"
  dependsOn: []
  isVerificationFile: false
  path: matrix.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix.h
layout: document
redirect_from:
- /library/matrix.h
- /library/matrix.h.html
title: matrix.h
---
