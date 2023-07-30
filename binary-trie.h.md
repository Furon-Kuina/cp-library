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
  bundledCode: "#line 1 \"binary-trie.h\"\ntemplate <typename T = long long, int B\
    \ = 32>\nstruct BinaryTrie {\n private:\n  struct node {\n    int cnt;\n    node*\
    \ ch[2];\n    node() : cnt(0), ch{nullptr, nullptr} {}\n  };\n  node* add(node*\
    \ t, T val, int b = B - 1) {\n    if (!t) t = new node;\n    t->cnt += 1;\n  \
    \  if (b < 0) return t;\n    bool f = (val >> T(b)) & T(1);\n    t->ch[f] = add(t->ch[f],\
    \ val, b - 1);\n    return t;\n  }\n  node* sub(node* t, T val, int b = B - 1)\
    \ {\n    assert(t);\n    t->cnt -= 1;\n    if (t->cnt == 0) return nullptr;\n\
    \    if (b < 0) return t;\n    bool f = (val >> T(b)) & T(1);\n    t->ch[f] =\
    \ sub(t->ch[f], val, b - 1);\n    return t;\n  }\n  T get_min(node* t, T val,\
    \ int b = B - 1) const {\n    assert(t);\n    if (b < 0) return 0;\n    bool f\
    \ = (val >> T(b)) & T(1);\n    f ^= !t->ch[f];\n    return get_min(t->ch[f], val,\
    \ b - 1) | (T(f) << T(b));\n  }\n  T get(node* t, int k, int b = B - 1) const\
    \ {\n    if (b < 0) return 0;\n    int m = t->ch[0] ? t->ch[0]->cnt : 0;\n   \
    \ return k < m ? get(t->ch[0], k, b - 1)\n                 : get(t->ch[1], k -\
    \ m, b - 1) | (T(1) << T(b));\n  }\n  int count_lower(node* t, T val, int b =\
    \ B - 1) {\n    if (!t || b < 0) return 0;\n    bool f = (val >> T(b)) & T(1);\n\
    \    return (f && t->ch[0] ? t->ch[0]->cnt : 0) +\n           count_lower(t->ch[f],\
    \ val, b - 1);\n  }\n  node* root;\n\n public:\n  BinaryTrie() : root(nullptr)\
    \ {}\n  int size() const { return root ? root->cnt : 0; }\n  bool empty() const\
    \ { return !root; }\n  void insert(T val) { root = add(root, val); }\n  void erase(T\
    \ val) { root = sub(root, val); }\n  T max_element(T bias = 0) const { return\
    \ get_min(root, ~bias); }\n  T min_element(T bias = 0) const { return get_min(root,\
    \ bias); }\n  int lower_bound(T val) { return count_lower(root, val); }\n  int\
    \ upper_bound(T val) { return count_lower(root, val + 1); }\n  T operator[](int\
    \ k) const {\n    assert(0 <= k && k < size());\n    return get(root, k);\n  }\n\
    \  int count(T val) const {\n    if (!root) return 0;\n    node* t = root;\n \
    \   for (int i = B - 1; i >= 0; i--) {\n      t = t->ch[(val >> T(i)) & T(1)];\n\
    \      if (!t) return 0;\n    }\n    return t->cnt;\n  }\n};\n"
  code: "template <typename T = long long, int B = 32>\nstruct BinaryTrie {\n private:\n\
    \  struct node {\n    int cnt;\n    node* ch[2];\n    node() : cnt(0), ch{nullptr,\
    \ nullptr} {}\n  };\n  node* add(node* t, T val, int b = B - 1) {\n    if (!t)\
    \ t = new node;\n    t->cnt += 1;\n    if (b < 0) return t;\n    bool f = (val\
    \ >> T(b)) & T(1);\n    t->ch[f] = add(t->ch[f], val, b - 1);\n    return t;\n\
    \  }\n  node* sub(node* t, T val, int b = B - 1) {\n    assert(t);\n    t->cnt\
    \ -= 1;\n    if (t->cnt == 0) return nullptr;\n    if (b < 0) return t;\n    bool\
    \ f = (val >> T(b)) & T(1);\n    t->ch[f] = sub(t->ch[f], val, b - 1);\n    return\
    \ t;\n  }\n  T get_min(node* t, T val, int b = B - 1) const {\n    assert(t);\n\
    \    if (b < 0) return 0;\n    bool f = (val >> T(b)) & T(1);\n    f ^= !t->ch[f];\n\
    \    return get_min(t->ch[f], val, b - 1) | (T(f) << T(b));\n  }\n  T get(node*\
    \ t, int k, int b = B - 1) const {\n    if (b < 0) return 0;\n    int m = t->ch[0]\
    \ ? t->ch[0]->cnt : 0;\n    return k < m ? get(t->ch[0], k, b - 1)\n         \
    \        : get(t->ch[1], k - m, b - 1) | (T(1) << T(b));\n  }\n  int count_lower(node*\
    \ t, T val, int b = B - 1) {\n    if (!t || b < 0) return 0;\n    bool f = (val\
    \ >> T(b)) & T(1);\n    return (f && t->ch[0] ? t->ch[0]->cnt : 0) +\n       \
    \    count_lower(t->ch[f], val, b - 1);\n  }\n  node* root;\n\n public:\n  BinaryTrie()\
    \ : root(nullptr) {}\n  int size() const { return root ? root->cnt : 0; }\n  bool\
    \ empty() const { return !root; }\n  void insert(T val) { root = add(root, val);\
    \ }\n  void erase(T val) { root = sub(root, val); }\n  T max_element(T bias =\
    \ 0) const { return get_min(root, ~bias); }\n  T min_element(T bias = 0) const\
    \ { return get_min(root, bias); }\n  int lower_bound(T val) { return count_lower(root,\
    \ val); }\n  int upper_bound(T val) { return count_lower(root, val + 1); }\n \
    \ T operator[](int k) const {\n    assert(0 <= k && k < size());\n    return get(root,\
    \ k);\n  }\n  int count(T val) const {\n    if (!root) return 0;\n    node* t\
    \ = root;\n    for (int i = B - 1; i >= 0; i--) {\n      t = t->ch[(val >> T(i))\
    \ & T(1)];\n      if (!t) return 0;\n    }\n    return t->cnt;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: binary-trie.h
  requiredBy: []
  timestamp: '2023-07-30 22:22:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: binary-trie.h
layout: document
redirect_from:
- /library/binary-trie.h
- /library/binary-trie.h.html
title: binary-trie.h
---
