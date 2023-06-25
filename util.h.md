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
  bundledCode: "#line 1 \"util.h\"\ninline long long CountDigit(long long n, const\
    \ long long base = 10) {\n    assert(n > 0);\n    assert(base > 1);\n    long\
    \ long res = 0;\n    while (n) {\n        res++;\n        n /= base;\n    }\n\
    \    return res;\n}\n\n// returns floor(n / m)\ninline long long DivFloor(long\
    \ long n, long long m) {\n    assert(m != 0);\n    if (m < 0) {\n        n = -n;\n\
    \        m = -m;\n    }\n    if (n >= 0)\n        return n / m;\n    else if (n\
    \ % m == 0)\n        return -(std::abs(n) / m);\n    else\n        return -(std::abs(n)\
    \ / m) - 1;\n}\n\n// returns ceil(n / m)\ninline long long DivCeil(long long n,\
    \ long long m) {\n    assert(m != 0);\n    if (n % m == 0)\n        return DivFloor(n,\
    \ m);\n    else\n        return DivFloor(n, m) + 1;\n}\n\ntemplate<typename T,\
    \ typename F>\nbool Exists(const std::vector<T> &vec, F &&f) {\n    return std::any_of(vec.begin(),\
    \ vec.end(), f);\n}\n\ntemplate<typename T, typename F>\nbool ForAll(const std::vector<T>\
    \ &vec, F &&f) {\n    return std::all_of(vec.begin(), vec.end(), f);\n}\n\nusing\
    \ i128 = __int128;\n\nstd::istream &operator>>(std::istream &is, i128 &m) {\n\
    \    int64_t a;\n    is >> a;\n    m = a;\n    return is;\n}\n\nstd::ostream &operator<<(std::ostream\
    \ &os, const i128 &m) {\n    os << (int64_t) m;\n    return os;\n}\n\nstd::vector<long\
    \ long> Iota(int len, long long from = 0) {\n    std::vector<long long> res(len,\
    \ from);\n    for(int i = 1; i < len; ++i) {\n        res[i + 1] = res[i] + 1;\n\
    \    }\n    return res;\n}\n\nclass RangeCount {\n    \nprivate:\n    const std::vector<long\
    \ long> &vec_;\n\npublic:\n    RangeCount(const std::vector<long long> &vec) :\
    \ vec_(vec) {}\n\n    long long CountInRange(long long begin, long long end) {\n\
    \        return std::lower_bound(vec_.begin(), vec_.end(), end)\n            \
    \   - std::lower_bound(vec_.begin(), vec_.end(), begin);\n    }\n\n    long long\
    \ CountSmaller(long long x) {\n        return std::lower_bound(vec_.begin(), vec_.end(),\
    \ x) - vec_.begin();\n    }\n\n    long long CountLarger(long long x) {\n    \
    \    return vec_.end() - std::upper_bound(vec_.begin(), vec_.end(), x);\n    }\n\
    \n    long long CountFrom(long long x) {\n        return vec_.end() - std::lower_bound(vec_.begin(),\
    \ vec_.end(), x);\n    }\n\n    long long CountTo(long long x) {\n        return\
    \ std::upper_bound(vec_.begin(), vec_.end(), x) - vec_.begin();\n    }\n};\n\n\
    inline long long PowMod(long long x, long long n, const long long m) {\n    assert(n\
    \ >= 0);\n    assert(m != 0);\n    if (x == 0)\n        return 0;\n    long long\
    \ res = 1;\n    x = Mod(x, m);\n    while (n > 0) {\n        if (n & 1) {\n  \
    \          assert(x == 0 || std::abs(res) <= kMax / std::abs(x));\n          \
    \  res = Mod(res * x, m);\n        }\n        if (n >>= 1) {\n            assert(x\
    \ == 0 || std::abs(x) <= kMax / std::abs(x));\n            x = Mod(x * x, m);\n\
    \        }\n    }\n    return res;\n}\n\ntemplate<typename T>\nstd::vector<std::vector<T>>\
    \ Rotate(std::vector<std::vector<T>> vector, bool clockwise = false) {\n    //\u53CD\
    \u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\n    int h = vector.size(),\
    \ w = vector[0].size();\n    std::vector<std::vector<T>> res(w, std::vector<T>(h));\n\
    \    for (int i = 0; i < w; ++i) {\n        for (int j = 0; j < h; ++j) {\n  \
    \          if (clockwise)\n                res[i][j] = vector[h - j - 1][i];\n\
    \            else\n                res[i][j] = vector[j][w - i - 1];\n       \
    \ }\n    }\n    return res;\n}\n\nstd::vector<std::string> Rotate(std::vector<std::string>\
    \ v, bool clockwise = false) {\n    int h = v.size(), w = v[0].size();\n    std::vector<std::string>\
    \ res(w, std::string(h, {}));\n    for (int i = 0; i < w; ++i) {\n        for\
    \ (int j = 0; j < h; ++j) {\n            if (clockwise)\n                res[i][j]\
    \ = v[h - j - 1][i];\n            else\n                res[i][j] = v[j][w - i\
    \ - 1];\n        }\n    }\n    return res;\n}\n\nlong long SqrtFloor(long long\
    \ n) {\n    // n -> floor(sqrt(n))\n    assert(n >= 0);\n    if(n == 0)\n    \
    \    return 0;\n    long long ok = 0;\n    long long ng = n + 1;\n    while (ng\
    \ - ok > 1) {\n        long long mid = (ok + ng) / 2;\n        if (mid <= n /\
    \ mid) {\n            ok = mid;\n        } else {\n            ng = mid;\n   \
    \     }\n    }\n    return ok;\n}\n\nlong long SqrtCeil(long long n) {\n    //\
    \ n -> ceil(sqrt(n))\n    assert(n >= 0);\n    if(n == 0)\n        return 0;\n\
    \    long long ok = n;\n    long long ng = 0;\n    while (ok - ng > 1) {\n   \
    \     long long mid = (ok + ng) / 2;\n        if (mid >= n / mid) {\n        \
    \    ok = mid;\n        } else {\n            ng = mid;\n        }\n    }\n  \
    \  return ok;\n}\n\ntemplate<typename T>\nstd::vector<T> Deduplicate(std::vector<T>\
    \ v) {\n    std::sort(v.begin(), v.end());\n    v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n    return v;\n}\n\nauto IsValid = [&](long long i, long\
    \ long j){\n    return 0 <= i && i < H && 0 <= j && j < W;\n};\n\nnamespace debug\
    \ {\n    template<typename T, typename S>\n    std::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T, S> &p) {\n        os << \"(\" << p.first << \", \" <<\
    \ p.second << \")\";\n        return os;\n    }\n\n    template<typename T, typename\
    \ S>\n    std::ostream &operator<<(std::ostream &os, const std::map<T, S> &ma)\
    \ {\n        for (auto[a, b]: ma) {\n            os << \"(\" << a << \", \" <<\
    \ b << \")\"\n               << \" \";\n        }\n        return os;\n    }\n\
    \n    template<typename T>\n    std::ostream &operator<<(std::ostream &os, const\
    \ std::set<T> &s) {\n        os << \"{\";\n        for (auto c: s)\n         \
    \   os << c << \" \";\n        os << \"}\";\n        return os;\n    }\n\n   \
    \ template<typename T>\n    std::ostream &operator<<(std::ostream &os, const std::multiset<T>\
    \ &s) {\n        os << \"{\";\n        for (auto c: s)\n            os << c <<\
    \ \" \";\n        os << \"}\";\n        return os;\n    }\n\n    template<typename\
    \ T>\n    std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)\
    \ {\n        os << \"[\";\n        for (int i = 0; i < v.size(); i++) {\n    \
    \        os << v[i] << (i == v.size() - 1 ? \"\" : \" \");\n        }\n      \
    \  os << \"]\";\n        return os;\n    }\n\n    void dump_func() {\n       \
    \ std::cerr << std::endl;\n    }\n\n    template<class Head, class... Tail>\n\
    \    void dump_func(Head &&head, Tail &&...tail) {\n        std::cerr << head;\n\
    \        if (sizeof...(Tail) == 0)\n            std::cerr << \" \";\n        else\n\
    \            std::cerr << \", \";\n        dump_func(std::move(tail)...);\n  \
    \  }\n\n    void assert_ole(bool cond) {\n        if (cond) return;\n        for\
    \ (int i = 0; i < 100000000; ++i) {\n            std::cout << i;\n        }\n\
    \    }\n\n    void assert_re(bool cond) {\n        assert(cond);\n    }\n\n\n\
    }\n\n//#define ONLINE_JUDGE\n#ifdef ONLINE_JUDGE\n#define dump(...) true\n#else\n\
    #define dump(...)                                                            \
    \                                          \\\n      std::cerr << __LINE__ <<\
    \ \" : (\" << #__VA_ARGS__ << \") = \";                                      \
    \                 \\\n      dump_func(__VA_ARGS__)\n#endif\n\nusing namespace\
    \ debug;\n"
  code: "inline long long CountDigit(long long n, const long long base = 10) {\n \
    \   assert(n > 0);\n    assert(base > 1);\n    long long res = 0;\n    while (n)\
    \ {\n        res++;\n        n /= base;\n    }\n    return res;\n}\n\n// returns\
    \ floor(n / m)\ninline long long DivFloor(long long n, long long m) {\n    assert(m\
    \ != 0);\n    if (m < 0) {\n        n = -n;\n        m = -m;\n    }\n    if (n\
    \ >= 0)\n        return n / m;\n    else if (n % m == 0)\n        return -(std::abs(n)\
    \ / m);\n    else\n        return -(std::abs(n) / m) - 1;\n}\n\n// returns ceil(n\
    \ / m)\ninline long long DivCeil(long long n, long long m) {\n    assert(m !=\
    \ 0);\n    if (n % m == 0)\n        return DivFloor(n, m);\n    else\n       \
    \ return DivFloor(n, m) + 1;\n}\n\ntemplate<typename T, typename F>\nbool Exists(const\
    \ std::vector<T> &vec, F &&f) {\n    return std::any_of(vec.begin(), vec.end(),\
    \ f);\n}\n\ntemplate<typename T, typename F>\nbool ForAll(const std::vector<T>\
    \ &vec, F &&f) {\n    return std::all_of(vec.begin(), vec.end(), f);\n}\n\nusing\
    \ i128 = __int128;\n\nstd::istream &operator>>(std::istream &is, i128 &m) {\n\
    \    int64_t a;\n    is >> a;\n    m = a;\n    return is;\n}\n\nstd::ostream &operator<<(std::ostream\
    \ &os, const i128 &m) {\n    os << (int64_t) m;\n    return os;\n}\n\nstd::vector<long\
    \ long> Iota(int len, long long from = 0) {\n    std::vector<long long> res(len,\
    \ from);\n    for(int i = 1; i < len; ++i) {\n        res[i + 1] = res[i] + 1;\n\
    \    }\n    return res;\n}\n\nclass RangeCount {\n    \nprivate:\n    const std::vector<long\
    \ long> &vec_;\n\npublic:\n    RangeCount(const std::vector<long long> &vec) :\
    \ vec_(vec) {}\n\n    long long CountInRange(long long begin, long long end) {\n\
    \        return std::lower_bound(vec_.begin(), vec_.end(), end)\n            \
    \   - std::lower_bound(vec_.begin(), vec_.end(), begin);\n    }\n\n    long long\
    \ CountSmaller(long long x) {\n        return std::lower_bound(vec_.begin(), vec_.end(),\
    \ x) - vec_.begin();\n    }\n\n    long long CountLarger(long long x) {\n    \
    \    return vec_.end() - std::upper_bound(vec_.begin(), vec_.end(), x);\n    }\n\
    \n    long long CountFrom(long long x) {\n        return vec_.end() - std::lower_bound(vec_.begin(),\
    \ vec_.end(), x);\n    }\n\n    long long CountTo(long long x) {\n        return\
    \ std::upper_bound(vec_.begin(), vec_.end(), x) - vec_.begin();\n    }\n};\n\n\
    inline long long PowMod(long long x, long long n, const long long m) {\n    assert(n\
    \ >= 0);\n    assert(m != 0);\n    if (x == 0)\n        return 0;\n    long long\
    \ res = 1;\n    x = Mod(x, m);\n    while (n > 0) {\n        if (n & 1) {\n  \
    \          assert(x == 0 || std::abs(res) <= kMax / std::abs(x));\n          \
    \  res = Mod(res * x, m);\n        }\n        if (n >>= 1) {\n            assert(x\
    \ == 0 || std::abs(x) <= kMax / std::abs(x));\n            x = Mod(x * x, m);\n\
    \        }\n    }\n    return res;\n}\n\ntemplate<typename T>\nstd::vector<std::vector<T>>\
    \ Rotate(std::vector<std::vector<T>> vector, bool clockwise = false) {\n    //\u53CD\
    \u6642\u8A08\u56DE\u308A\u306B90\u5EA6\u56DE\u8EE2\n    int h = vector.size(),\
    \ w = vector[0].size();\n    std::vector<std::vector<T>> res(w, std::vector<T>(h));\n\
    \    for (int i = 0; i < w; ++i) {\n        for (int j = 0; j < h; ++j) {\n  \
    \          if (clockwise)\n                res[i][j] = vector[h - j - 1][i];\n\
    \            else\n                res[i][j] = vector[j][w - i - 1];\n       \
    \ }\n    }\n    return res;\n}\n\nstd::vector<std::string> Rotate(std::vector<std::string>\
    \ v, bool clockwise = false) {\n    int h = v.size(), w = v[0].size();\n    std::vector<std::string>\
    \ res(w, std::string(h, {}));\n    for (int i = 0; i < w; ++i) {\n        for\
    \ (int j = 0; j < h; ++j) {\n            if (clockwise)\n                res[i][j]\
    \ = v[h - j - 1][i];\n            else\n                res[i][j] = v[j][w - i\
    \ - 1];\n        }\n    }\n    return res;\n}\n\nlong long SqrtFloor(long long\
    \ n) {\n    // n -> floor(sqrt(n))\n    assert(n >= 0);\n    if(n == 0)\n    \
    \    return 0;\n    long long ok = 0;\n    long long ng = n + 1;\n    while (ng\
    \ - ok > 1) {\n        long long mid = (ok + ng) / 2;\n        if (mid <= n /\
    \ mid) {\n            ok = mid;\n        } else {\n            ng = mid;\n   \
    \     }\n    }\n    return ok;\n}\n\nlong long SqrtCeil(long long n) {\n    //\
    \ n -> ceil(sqrt(n))\n    assert(n >= 0);\n    if(n == 0)\n        return 0;\n\
    \    long long ok = n;\n    long long ng = 0;\n    while (ok - ng > 1) {\n   \
    \     long long mid = (ok + ng) / 2;\n        if (mid >= n / mid) {\n        \
    \    ok = mid;\n        } else {\n            ng = mid;\n        }\n    }\n  \
    \  return ok;\n}\n\ntemplate<typename T>\nstd::vector<T> Deduplicate(std::vector<T>\
    \ v) {\n    std::sort(v.begin(), v.end());\n    v.erase(std::unique(v.begin(),\
    \ v.end()), v.end());\n    return v;\n}\n\nauto IsValid = [&](long long i, long\
    \ long j){\n    return 0 <= i && i < H && 0 <= j && j < W;\n};\n\nnamespace debug\
    \ {\n    template<typename T, typename S>\n    std::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T, S> &p) {\n        os << \"(\" << p.first << \", \" <<\
    \ p.second << \")\";\n        return os;\n    }\n\n    template<typename T, typename\
    \ S>\n    std::ostream &operator<<(std::ostream &os, const std::map<T, S> &ma)\
    \ {\n        for (auto[a, b]: ma) {\n            os << \"(\" << a << \", \" <<\
    \ b << \")\"\n               << \" \";\n        }\n        return os;\n    }\n\
    \n    template<typename T>\n    std::ostream &operator<<(std::ostream &os, const\
    \ std::set<T> &s) {\n        os << \"{\";\n        for (auto c: s)\n         \
    \   os << c << \" \";\n        os << \"}\";\n        return os;\n    }\n\n   \
    \ template<typename T>\n    std::ostream &operator<<(std::ostream &os, const std::multiset<T>\
    \ &s) {\n        os << \"{\";\n        for (auto c: s)\n            os << c <<\
    \ \" \";\n        os << \"}\";\n        return os;\n    }\n\n    template<typename\
    \ T>\n    std::ostream &operator<<(std::ostream &os, const std::vector<T> &v)\
    \ {\n        os << \"[\";\n        for (int i = 0; i < v.size(); i++) {\n    \
    \        os << v[i] << (i == v.size() - 1 ? \"\" : \" \");\n        }\n      \
    \  os << \"]\";\n        return os;\n    }\n\n    void dump_func() {\n       \
    \ std::cerr << std::endl;\n    }\n\n    template<class Head, class... Tail>\n\
    \    void dump_func(Head &&head, Tail &&...tail) {\n        std::cerr << head;\n\
    \        if (sizeof...(Tail) == 0)\n            std::cerr << \" \";\n        else\n\
    \            std::cerr << \", \";\n        dump_func(std::move(tail)...);\n  \
    \  }\n\n    void assert_ole(bool cond) {\n        if (cond) return;\n        for\
    \ (int i = 0; i < 100000000; ++i) {\n            std::cout << i;\n        }\n\
    \    }\n\n    void assert_re(bool cond) {\n        assert(cond);\n    }\n\n\n\
    }\n\n//#define ONLINE_JUDGE\n#ifdef ONLINE_JUDGE\n#define dump(...) true\n#else\n\
    #define dump(...)                                                            \
    \                                          \\\n      std::cerr << __LINE__ <<\
    \ \" : (\" << #__VA_ARGS__ << \") = \";                                      \
    \                 \\\n      dump_func(__VA_ARGS__)\n#endif\n\nusing namespace\
    \ debug;"
  dependsOn: []
  isVerificationFile: false
  path: util.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util.h
layout: document
redirect_from:
- /library/util.h
- /library/util.h.html
title: util.h
---
