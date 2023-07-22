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
  bundledCode: "#line 1 \"fps.h\"\n\ntemplate <typename T,\n          std::vector<T>\
    \ (*Convolution)(std::vector<T>, std::vector<T>)>\nclass Fps : public std::vector<T>\
    \ {\n public:\n  bool ntt_friendly_ = true;\n\n  Fps &operator+=(const Fps &f)\
    \ {\n    if (f.size() > this->size()) {\n      this->resize(f.size());\n    }\n\
    \    for (int i = 0; i < (int)f.size(); ++i) {\n      (*this)[i] += f[i];\n  \
    \  }\n    return *this;\n  }\n\n  Fps &operator+=(const T &c) {\n    (*this)[0]\
    \ += c;\n    return *this;\n  }\n\n  Fps &operator-=(const Fps &f) {\n    if (f.size()\
    \ > this->size()) {\n      this->resize(f.size());\n    }\n    for (int i = 0;\
    \ i < (int)f.size(); ++i) {\n      (*this)[i] -= f[i];\n    }\n    return *this;\n\
    \  }\n\n  Fps &operator-=(const T &c) {\n    (*this)[0] -= c;\n    return *this;\n\
    \  }\n\n  Fps &operator*=(const Fps &f) {\n    (*this) = Convolution(*this, f);\n\
    \    return *this;\n  }\n\n  Fps &operator*=(const T &c) {\n    for (int i = 0;\
    \ i < (int)this->size(); ++i) {\n      (*this)[i] *= c;\n    }\n    return *this;\n\
    \  }\n\n  // multiply by x^d\n  Fps &operator<<=(const long long d) {\n    this->insert(this->begin(),\
    \ d, T(0));\n    return *this;\n  }\n\n  // cut the terms a_0x^0 to a_{d-1}x^{d-1}\n\
    \  Fps &operator>>=(const long long d) {\n    this->erase(this->begin(), this->begin()\
    \ + d);\n    return *this;\n  }\n\n  Fps operator+(const Fps &f) const { return\
    \ Fps(*this) += f; }\n\n  Fps operator+(const T &c) const { return Fps(*this)\
    \ += c; }\n\n  Fps operator-(const Fps &f) const { return Fps(*this) -= f; }\n\
    \n  Fps operator-(const T &c) const { return Fps(*this) -= c; }\n\n  Fps operator*(const\
    \ Fps &f) const { return Fps(*this) *= f; }\n\n  Fps operator*(const T &c) const\
    \ { return Fps(*this) *= c; }\n\n  Fps operator<<(const long long d) const { return\
    \ Fps(*this) <<= d; }\n\n  Fps operator>>(const long long d) const { return Fps(*this)\
    \ >>= d; }\n\n  Fps operator-() const {\n    Fps res(this->size);\n    for (int\
    \ i = 0; i < (int)this->size(); ++i) {\n      res[i] = -(*this)[i];\n    }\n \
    \   return res;\n  }\n\n  Fps Integral() const {\n    const int n = (int)this->size();\n\
    \    Fps res(n + 1);\n    res[0] = T(0);\n    for (int i = 0; i < n; ++i) {\n\
    \      res[i + 1] = (*this)[i] / T(i + 1);\n    }\n    return res;\n  }\n\n  Fps\
    \ Derivative() const {\n    const int n = (int)this->size();\n    Fps res(std::max(0,\
    \ n - 1));\n    for (int i = 1; i < n; ++i) {\n      res[i - 1] = (*this)[i] *\
    \ T(i);\n    }\n    return res;\n  }\n\n  Fps Inverse() const { int n = (int)this->size();\
    \ }\n};\n"
  code: "\ntemplate <typename T,\n          std::vector<T> (*Convolution)(std::vector<T>,\
    \ std::vector<T>)>\nclass Fps : public std::vector<T> {\n public:\n  bool ntt_friendly_\
    \ = true;\n\n  Fps &operator+=(const Fps &f) {\n    if (f.size() > this->size())\
    \ {\n      this->resize(f.size());\n    }\n    for (int i = 0; i < (int)f.size();\
    \ ++i) {\n      (*this)[i] += f[i];\n    }\n    return *this;\n  }\n\n  Fps &operator+=(const\
    \ T &c) {\n    (*this)[0] += c;\n    return *this;\n  }\n\n  Fps &operator-=(const\
    \ Fps &f) {\n    if (f.size() > this->size()) {\n      this->resize(f.size());\n\
    \    }\n    for (int i = 0; i < (int)f.size(); ++i) {\n      (*this)[i] -= f[i];\n\
    \    }\n    return *this;\n  }\n\n  Fps &operator-=(const T &c) {\n    (*this)[0]\
    \ -= c;\n    return *this;\n  }\n\n  Fps &operator*=(const Fps &f) {\n    (*this)\
    \ = Convolution(*this, f);\n    return *this;\n  }\n\n  Fps &operator*=(const\
    \ T &c) {\n    for (int i = 0; i < (int)this->size(); ++i) {\n      (*this)[i]\
    \ *= c;\n    }\n    return *this;\n  }\n\n  // multiply by x^d\n  Fps &operator<<=(const\
    \ long long d) {\n    this->insert(this->begin(), d, T(0));\n    return *this;\n\
    \  }\n\n  // cut the terms a_0x^0 to a_{d-1}x^{d-1}\n  Fps &operator>>=(const\
    \ long long d) {\n    this->erase(this->begin(), this->begin() + d);\n    return\
    \ *this;\n  }\n\n  Fps operator+(const Fps &f) const { return Fps(*this) += f;\
    \ }\n\n  Fps operator+(const T &c) const { return Fps(*this) += c; }\n\n  Fps\
    \ operator-(const Fps &f) const { return Fps(*this) -= f; }\n\n  Fps operator-(const\
    \ T &c) const { return Fps(*this) -= c; }\n\n  Fps operator*(const Fps &f) const\
    \ { return Fps(*this) *= f; }\n\n  Fps operator*(const T &c) const { return Fps(*this)\
    \ *= c; }\n\n  Fps operator<<(const long long d) const { return Fps(*this) <<=\
    \ d; }\n\n  Fps operator>>(const long long d) const { return Fps(*this) >>= d;\
    \ }\n\n  Fps operator-() const {\n    Fps res(this->size);\n    for (int i = 0;\
    \ i < (int)this->size(); ++i) {\n      res[i] = -(*this)[i];\n    }\n    return\
    \ res;\n  }\n\n  Fps Integral() const {\n    const int n = (int)this->size();\n\
    \    Fps res(n + 1);\n    res[0] = T(0);\n    for (int i = 0; i < n; ++i) {\n\
    \      res[i + 1] = (*this)[i] / T(i + 1);\n    }\n    return res;\n  }\n\n  Fps\
    \ Derivative() const {\n    const int n = (int)this->size();\n    Fps res(std::max(0,\
    \ n - 1));\n    for (int i = 1; i < n; ++i) {\n      res[i - 1] = (*this)[i] *\
    \ T(i);\n    }\n    return res;\n  }\n\n  Fps Inverse() const { int n = (int)this->size();\
    \ }\n};"
  dependsOn: []
  isVerificationFile: false
  path: fps.h
  requiredBy: []
  timestamp: '2023-07-23 00:00:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: fps.h
layout: document
redirect_from:
- /library/fps.h
- /library/fps.h.html
title: fps.h
---
