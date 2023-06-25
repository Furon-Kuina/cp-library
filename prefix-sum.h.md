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
  bundledCode: "#line 1 \"prefix-sum.h\"\nclass PrefixMax {\n\nprivate:\n    int len_{};\n\
    \    std::vector<long long> arr_;\n    std::vector<long long> prefix_max_;\n \
    \   std::vector<long long> suffix_max_;\npublic:\n    PrefixMax() = default;\n\
    \n    explicit PrefixMax(std::vector<long long> &arr) : arr_(arr), len_((int)\
    \ arr.size()) {\n        prefix_max_.resize(len_ + 1);\n        prefix_max_[0]\
    \ = std::numeric_limits<long long>::min();\n        for (int i = 0; i < len_;\
    \ ++i) {\n            prefix_max_[i + 1] = std::max(prefix_max_[i], arr[i]);\n\
    \        }\n        suffix_max_.resize(len_ + 1);\n        suffix_max_[len_] =\
    \ std::numeric_limits<long long>::min();\n        for (int i = len_ - 1; i >=\
    \ 0; --i) {\n            suffix_max_[i] = std::max(suffix_max_[i + 1], arr[i]);\n\
    \        }\n    }\n\n    long long MaxTo(long long r) {\n        // max(arr[0],\
    \ ..., arr[r])\n        // Note: SumTo(r) is inclusive on r, while RangeSum(begin,\
    \ end) is not.\n        assert(r >= 0);\n        assert(r < arr_.size());\n  \
    \      return prefix_max_[r + 1];\n    }\n\n    long long MaxFrom(long long r)\
    \ {\n        assert(r >= 0);\n        assert(r < arr_.size());\n        return\
    \ suffix_max_[r];\n    }\n\n    long long AllMax() {\n        return prefix_max_[len_];\n\
    \    }\n};\n\nclass PrefixMin {\n\nprivate:\n    int len_{};\n    std::vector<long\
    \ long> arr_;\n    std::vector<long long> prefix_min_;\n    std::vector<long long>\
    \ suffix_min_;\npublic:\n    PrefixMin() = default;\n\n    explicit PrefixMin(std::vector<long\
    \ long> &arr) : arr_(arr), len_((int) arr.size()) {\n        prefix_min_.resize(len_\
    \ + 1);\n        prefix_min_[0] = std::numeric_limits<long long>::max();\n   \
    \     for (int i = 0; i < len_; ++i) {\n            prefix_min_[i + 1] = std::min(prefix_min_[i],\
    \ arr[i]);\n        }\n        suffix_min_.resize(len_ + 1);\n        suffix_min_[len_]\
    \ = std::numeric_limits<long long>::max();\n        for (int i = len_ - 1; i >=\
    \ 0; --i) {\n            suffix_min_[i] = std::min(suffix_min_[i + 1], arr[i]);\n\
    \        }\n    }\n\n    long long MinTo(long long r) {\n        // min(arr[0],\
    \ ..., arr[r])\n        assert(r >= 0);\n        assert(r < arr_.size());\n  \
    \      return prefix_min_[r + 1];\n    }\n\n    long long MinFrom(long long r)\
    \ {\n        assert(r >= 0);\n        assert(r < arr_.size());\n        return\
    \ suffix_min_[r];\n    }\n\n    long long AllMin() {\n        return prefix_min_[len_];\n\
    \    }\n};\n\ntemplate<typename T>\nclass PrefixSum {\n\nprivate:\n    int len_;\n\
    \    std::vector<T> arr_;\n    std::vector<T> sum_;\n\npublic:\n    PrefixSum(std::vector<T>\
    \ &arr) : arr_(arr), len_(arr.size()) {\n        sum_.resize(len_ + 1);\n    \
    \    sum_[0] = T(0);\n        for (int i = 0; i < len_; ++i) {\n            sum_[i\
    \ + 1] = sum_[i] + arr[i];\n        }\n    }\n\n    T SumTo(long long r) {\n \
    \       // arr[0] + ... arr[r]\n        // Note: Sum(r) is inclusive on r, while\
    \ RangeSum(begin, end) is not.\n        assert(r >= 0);\n        assert(r < arr_.size());\n\
    \        return sum_[r + 1];\n    }\n\n    T SumFrom(long long r) {\n        return\
    \ AllSum() - SumTo(r - 1);\n    }\n\n    T RangeSum(long long begin, long long\
    \ end) {\n        // a[begin] + ... + a[end - 1]\n        assert(0 <= begin &&\
    \ begin <= end && end <= len_);\n        return sum_[end] - sum_[begin];\n   \
    \ }\n\n    T AllSum() {\n        return sum_[len_];\n    }\n};\n\ntemplate<typename\
    \ T>\nstruct Ruiseki_2d {\n        int H;\n        int W;\n        vector< vector<T>\
    \ > A;\n        vector< vector<T> >  Sum;\n        explicit Ruiseki_2d(vector<vector<T>>\
    \ v){\n            H = (int)v.size();\n            W = (int)v[0].size();\n   \
    \         A = v;\n            Sum.assign(H+1, vector<T>(W+1, 0));\n          \
    \  for(int i = 0; i < H; i++){\n                for(int j = 0; j < W; j++){\n\
    \                    Sum[i+1][j+1] = Sum[i][j+1] + Sum[i+1][j] + A[i][j] - Sum[i][j];\n\
    \                }\n            }\n        }\n        T sum(int y1, int y2, int\
    \ x1, int x2){ //[x1, x2)\xD7[y1, y2)\u306E\u7BC4\u56F2\u306E\u548C\n        \
    \    return Sum[y2][x2] - Sum[y1][x2] - Sum[y2][x1] + Sum[y1][x1];\n        }\n\
    };\n"
  code: "class PrefixMax {\n\nprivate:\n    int len_{};\n    std::vector<long long>\
    \ arr_;\n    std::vector<long long> prefix_max_;\n    std::vector<long long> suffix_max_;\n\
    public:\n    PrefixMax() = default;\n\n    explicit PrefixMax(std::vector<long\
    \ long> &arr) : arr_(arr), len_((int) arr.size()) {\n        prefix_max_.resize(len_\
    \ + 1);\n        prefix_max_[0] = std::numeric_limits<long long>::min();\n   \
    \     for (int i = 0; i < len_; ++i) {\n            prefix_max_[i + 1] = std::max(prefix_max_[i],\
    \ arr[i]);\n        }\n        suffix_max_.resize(len_ + 1);\n        suffix_max_[len_]\
    \ = std::numeric_limits<long long>::min();\n        for (int i = len_ - 1; i >=\
    \ 0; --i) {\n            suffix_max_[i] = std::max(suffix_max_[i + 1], arr[i]);\n\
    \        }\n    }\n\n    long long MaxTo(long long r) {\n        // max(arr[0],\
    \ ..., arr[r])\n        // Note: SumTo(r) is inclusive on r, while RangeSum(begin,\
    \ end) is not.\n        assert(r >= 0);\n        assert(r < arr_.size());\n  \
    \      return prefix_max_[r + 1];\n    }\n\n    long long MaxFrom(long long r)\
    \ {\n        assert(r >= 0);\n        assert(r < arr_.size());\n        return\
    \ suffix_max_[r];\n    }\n\n    long long AllMax() {\n        return prefix_max_[len_];\n\
    \    }\n};\n\nclass PrefixMin {\n\nprivate:\n    int len_{};\n    std::vector<long\
    \ long> arr_;\n    std::vector<long long> prefix_min_;\n    std::vector<long long>\
    \ suffix_min_;\npublic:\n    PrefixMin() = default;\n\n    explicit PrefixMin(std::vector<long\
    \ long> &arr) : arr_(arr), len_((int) arr.size()) {\n        prefix_min_.resize(len_\
    \ + 1);\n        prefix_min_[0] = std::numeric_limits<long long>::max();\n   \
    \     for (int i = 0; i < len_; ++i) {\n            prefix_min_[i + 1] = std::min(prefix_min_[i],\
    \ arr[i]);\n        }\n        suffix_min_.resize(len_ + 1);\n        suffix_min_[len_]\
    \ = std::numeric_limits<long long>::max();\n        for (int i = len_ - 1; i >=\
    \ 0; --i) {\n            suffix_min_[i] = std::min(suffix_min_[i + 1], arr[i]);\n\
    \        }\n    }\n\n    long long MinTo(long long r) {\n        // min(arr[0],\
    \ ..., arr[r])\n        assert(r >= 0);\n        assert(r < arr_.size());\n  \
    \      return prefix_min_[r + 1];\n    }\n\n    long long MinFrom(long long r)\
    \ {\n        assert(r >= 0);\n        assert(r < arr_.size());\n        return\
    \ suffix_min_[r];\n    }\n\n    long long AllMin() {\n        return prefix_min_[len_];\n\
    \    }\n};\n\ntemplate<typename T>\nclass PrefixSum {\n\nprivate:\n    int len_;\n\
    \    std::vector<T> arr_;\n    std::vector<T> sum_;\n\npublic:\n    PrefixSum(std::vector<T>\
    \ &arr) : arr_(arr), len_(arr.size()) {\n        sum_.resize(len_ + 1);\n    \
    \    sum_[0] = T(0);\n        for (int i = 0; i < len_; ++i) {\n            sum_[i\
    \ + 1] = sum_[i] + arr[i];\n        }\n    }\n\n    T SumTo(long long r) {\n \
    \       // arr[0] + ... arr[r]\n        // Note: Sum(r) is inclusive on r, while\
    \ RangeSum(begin, end) is not.\n        assert(r >= 0);\n        assert(r < arr_.size());\n\
    \        return sum_[r + 1];\n    }\n\n    T SumFrom(long long r) {\n        return\
    \ AllSum() - SumTo(r - 1);\n    }\n\n    T RangeSum(long long begin, long long\
    \ end) {\n        // a[begin] + ... + a[end - 1]\n        assert(0 <= begin &&\
    \ begin <= end && end <= len_);\n        return sum_[end] - sum_[begin];\n   \
    \ }\n\n    T AllSum() {\n        return sum_[len_];\n    }\n};\n\ntemplate<typename\
    \ T>\nstruct Ruiseki_2d {\n        int H;\n        int W;\n        vector< vector<T>\
    \ > A;\n        vector< vector<T> >  Sum;\n        explicit Ruiseki_2d(vector<vector<T>>\
    \ v){\n            H = (int)v.size();\n            W = (int)v[0].size();\n   \
    \         A = v;\n            Sum.assign(H+1, vector<T>(W+1, 0));\n          \
    \  for(int i = 0; i < H; i++){\n                for(int j = 0; j < W; j++){\n\
    \                    Sum[i+1][j+1] = Sum[i][j+1] + Sum[i+1][j] + A[i][j] - Sum[i][j];\n\
    \                }\n            }\n        }\n        T sum(int y1, int y2, int\
    \ x1, int x2){ //[x1, x2)\xD7[y1, y2)\u306E\u7BC4\u56F2\u306E\u548C\n        \
    \    return Sum[y2][x2] - Sum[y1][x2] - Sum[y2][x1] + Sum[y1][x1];\n        }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: prefix-sum.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: prefix-sum.h
layout: document
redirect_from:
- /library/prefix-sum.h
- /library/prefix-sum.h.html
title: prefix-sum.h
---
