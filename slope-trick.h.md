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
  bundledCode: "#line 1 \"slope-trick.h\"\ntemplate< typename T >\nstruct SlopeTrick\
    \ {\n\n    const T slope_INF = numeric_limits< T >::max() / 8;\n\n    T min_f;\n\
    \    priority_queue< T, vector< T >, less<> > L;\n    priority_queue< T, vector<\
    \ T >, greater<> > R;\n    T add_l, add_r;\n\nprivate:\n    void push_R(const\
    \ T &a) {\n        R.push(a - add_r);\n    }\n\n    T top_R() const {\n      \
    \  if(R.empty()) return slope_INF;\n        else return R.top() + add_r;\n   \
    \ }\n\n    T pop_R() {\n        T val = top_R();\n        if(not R.empty()) R.pop();\n\
    \        return val;\n    }\n\n    void push_L(const T &a) {\n        L.push(a\
    \ - add_l);\n    }\n\n    T top_L() const {\n        if(L.empty()) return -slope_INF;\n\
    \        else return L.top() + add_l;\n    }\n\n    T pop_L() {\n        T val\
    \ = top_L();\n        if(not L.empty()) L.pop();\n        return val;\n    }\n\
    \n    size_t size() {\n        return L.size() + R.size();\n    }\n\npublic:\n\
    \    SlopeTrick() : min_f(0), add_l(0), add_r(0) {}\n\n    struct Query {\n  \
    \      T lx, rx, min_f;\n    };\n\n    // return min f(x)\n    Query min() const\
    \ {\n        return (Query) {top_L(), top_R(), min_f};\n    }\n\n    // f(x) +=\
    \ a\n    void add_const(const T &a) {\n        min_f += a;\n    }\n\n    // add\
    \ \\_\n    // f(x) += max(a - x, 0)\n    void add_a_minus_x(const T &a) {\n  \
    \      min_f += max(T(0), a - top_R());\n        push_R(a);\n        push_L(pop_R());\n\
    \    }\n\n    // add _/\n    // f(x) += max(x - a, 0)\n    void add_x_minus_a(const\
    \ T &a) {\n        min_f += max(T(0), top_L() - a);\n        push_L(a);\n    \
    \    push_R(pop_L());\n    }\n\n    // add \\/\n    // f(x) += abs(x - a)\n  \
    \  void add_abs(const T &a) {\n        add_a_minus_x(a);\n        add_x_minus_a(a);\n\
    \    }\n\n    // \\/ -> \\_\n    // f_{new} (x) = min f(y) (y <= x)\n    void\
    \ clear_right() {\n        while(not R.empty()) R.pop();\n    }\n\n    // \\/\
    \ -> _/\n    // f_{new} (x) = min f(y) (y >= x)\n    void clear_left() {\n   \
    \     while(not L.empty()) L.pop();\n    }\n\n    // \\/ -> \\_/\n    // f_{new}\
    \ (x) = min f(y) (x-b <= y <= x-a)\n    void shift(const T &a, const T &b) {\n\
    \        assert(a <= b);\n        add_l += a;\n        add_r += b;\n    }\n\n\
    \    // \\/. -> .\\/\n    // f_{new} (x) = f(x - a)\n    void shift(const T &a)\
    \ {\n        shift(a, a);\n    }\n\n    // L, R \u3092\u7834\u58CA\u3059\u308B\
    \n    T get(const T &x) {\n        T ret = min_f;\n        while(not L.empty())\
    \ {\n            ret += max(T(0), pop_L() - x);\n        }\n        while(not\
    \ R.empty()) {\n            ret += max(T(0), x - pop_R());\n        }\n      \
    \  return ret;\n    }\n\n    void merge(SlopeTrick &st) {\n        if(st.size()\
    \ > size()) {\n            swap(st.L, L);\n            swap(st.R, R);\n      \
    \      swap(st.add_l, add_l);\n            swap(st.add_r, add_r);\n          \
    \  swap(st.min_f, min_f);\n        }\n        while(not st.R.empty()) {\n    \
    \        add_x_minus_a(st.pop_R());\n        }\n        while(not st.L.empty())\
    \ {\n            add_a_minus_x(st.pop_L());\n        }\n        min_f += st.min_f;\n\
    \    }\n};\n"
  code: "template< typename T >\nstruct SlopeTrick {\n\n    const T slope_INF = numeric_limits<\
    \ T >::max() / 8;\n\n    T min_f;\n    priority_queue< T, vector< T >, less<>\
    \ > L;\n    priority_queue< T, vector< T >, greater<> > R;\n    T add_l, add_r;\n\
    \nprivate:\n    void push_R(const T &a) {\n        R.push(a - add_r);\n    }\n\
    \n    T top_R() const {\n        if(R.empty()) return slope_INF;\n        else\
    \ return R.top() + add_r;\n    }\n\n    T pop_R() {\n        T val = top_R();\n\
    \        if(not R.empty()) R.pop();\n        return val;\n    }\n\n    void push_L(const\
    \ T &a) {\n        L.push(a - add_l);\n    }\n\n    T top_L() const {\n      \
    \  if(L.empty()) return -slope_INF;\n        else return L.top() + add_l;\n  \
    \  }\n\n    T pop_L() {\n        T val = top_L();\n        if(not L.empty()) L.pop();\n\
    \        return val;\n    }\n\n    size_t size() {\n        return L.size() +\
    \ R.size();\n    }\n\npublic:\n    SlopeTrick() : min_f(0), add_l(0), add_r(0)\
    \ {}\n\n    struct Query {\n        T lx, rx, min_f;\n    };\n\n    // return\
    \ min f(x)\n    Query min() const {\n        return (Query) {top_L(), top_R(),\
    \ min_f};\n    }\n\n    // f(x) += a\n    void add_const(const T &a) {\n     \
    \   min_f += a;\n    }\n\n    // add \\_\n    // f(x) += max(a - x, 0)\n    void\
    \ add_a_minus_x(const T &a) {\n        min_f += max(T(0), a - top_R());\n    \
    \    push_R(a);\n        push_L(pop_R());\n    }\n\n    // add _/\n    // f(x)\
    \ += max(x - a, 0)\n    void add_x_minus_a(const T &a) {\n        min_f += max(T(0),\
    \ top_L() - a);\n        push_L(a);\n        push_R(pop_L());\n    }\n\n    //\
    \ add \\/\n    // f(x) += abs(x - a)\n    void add_abs(const T &a) {\n       \
    \ add_a_minus_x(a);\n        add_x_minus_a(a);\n    }\n\n    // \\/ -> \\_\n \
    \   // f_{new} (x) = min f(y) (y <= x)\n    void clear_right() {\n        while(not\
    \ R.empty()) R.pop();\n    }\n\n    // \\/ -> _/\n    // f_{new} (x) = min f(y)\
    \ (y >= x)\n    void clear_left() {\n        while(not L.empty()) L.pop();\n \
    \   }\n\n    // \\/ -> \\_/\n    // f_{new} (x) = min f(y) (x-b <= y <= x-a)\n\
    \    void shift(const T &a, const T &b) {\n        assert(a <= b);\n        add_l\
    \ += a;\n        add_r += b;\n    }\n\n    // \\/. -> .\\/\n    // f_{new} (x)\
    \ = f(x - a)\n    void shift(const T &a) {\n        shift(a, a);\n    }\n\n  \
    \  // L, R \u3092\u7834\u58CA\u3059\u308B\n    T get(const T &x) {\n        T\
    \ ret = min_f;\n        while(not L.empty()) {\n            ret += max(T(0), pop_L()\
    \ - x);\n        }\n        while(not R.empty()) {\n            ret += max(T(0),\
    \ x - pop_R());\n        }\n        return ret;\n    }\n\n    void merge(SlopeTrick\
    \ &st) {\n        if(st.size() > size()) {\n            swap(st.L, L);\n     \
    \       swap(st.R, R);\n            swap(st.add_l, add_l);\n            swap(st.add_r,\
    \ add_r);\n            swap(st.min_f, min_f);\n        }\n        while(not st.R.empty())\
    \ {\n            add_x_minus_a(st.pop_R());\n        }\n        while(not st.L.empty())\
    \ {\n            add_a_minus_x(st.pop_L());\n        }\n        min_f += st.min_f;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: slope-trick.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: slope-trick.h
layout: document
redirect_from:
- /library/slope-trick.h
- /library/slope-trick.h.html
title: slope-trick.h
---
