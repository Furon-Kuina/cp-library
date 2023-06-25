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
  bundledCode: "#line 1 \"geometry.h\"\nnamespace geometry {\n    using scalar = long\
    \ long;\n    constexpr scalar EPS = 0;\n\n    int Sign(const scalar a) {\n   \
    \     if (a < -EPS) return -1;\n        if (a > EPS) return 1;\n        return\
    \ 0;\n    }\n\n    bool IsEqual(const scalar a, const scalar b) {\n        return\
    \ Sign(a - b) == 0;\n    }\n\n    struct Point {\n        scalar x, y;\n\n   \
    \     Point() = default;\n\n        Point(scalar _x, scalar _y) {\n          \
    \  x = _x, y = _y;\n        }\n\n        Point operator-() const {\n         \
    \   return {-x, -y};\n        }\n\n        Point operator+(const Point &b) const\
    \ {\n            return {x + b.x, y + b.y};\n        }\n\n        Point operator-(const\
    \ Point &b) const {\n            return {x - b.x, y - b.y};\n        }\n\n   \
    \     Point operator*(const scalar &b) const {\n            return {x * b, y *\
    \ b};\n        }\n\n        Point operator/(const scalar &b) const {\n       \
    \     assert(!IsEqual(b, 0));\n            return {x / b, y / b};\n        }\n\
    \n        Point operator+=(const Point &b) {\n            x += b.x;\n        \
    \    y += b.y;\n            return *this;\n        }\n\n        Point operator-=(const\
    \ Point &b) {\n            x -= b.x;\n            y -= b.y;\n            return\
    \ *this;\n        }\n\n        Point operator*=(const scalar b) {\n          \
    \  x *= b;\n            y *= b;\n            return *this;\n        }\n\n    \
    \    Point operator/=(const scalar b) {\n            assert(!IsEqual(b, 0.0));\n\
    \            x /= b;\n            y /= b;\n            return *this;\n       \
    \ }\n\n        bool operator==(const Point &b) const {\n            return IsEqual(b.x,\
    \ x) && IsEqual(b.y, y);\n        }\n\n        scalar Norm() const {\n       \
    \     return sqrt(x * x + y * y);\n        }\n\n        scalar SquaredNorm() const\
    \ {\n            return x * x + y * y;\n        }\n\n        scalar DotProduct(const\
    \ Point &b) const {\n            return x * b.x + y * b.y;\n        }\n\n    \
    \    scalar CrossProduct(const Point &b) const {\n            return x * b.y -\
    \ y * b.x;\n        }\n\n        scalar Arg() const {\n            return std::atan2(y,\
    \ x);\n        }\n\n        Point Rotate(double theta) const {\n            return\
    \ {(scalar) (x * cos(theta) - y * sin(theta)), (scalar) (x * sin(theta) + y *\
    \ cos(theta))};\n        }\n    };\n\n    inline Point operator*(scalar a, const\
    \ Point &b) {\n        return {b.x * a, b.y * a};\n    }\n\n    inline bool operator<(const\
    \ Point &a, const Point &b) {\n        if (Sign(a.x - b.x) != 0) return Sign(a.x\
    \ - b.x) < 0;\n        else return Sign(a.y - b.y) < 0;\n    }\n\n    void SortByArgument(std::vector<Point>\
    \ &v) {\n        sort(v.begin(), v.end(), [&](Point a, Point b) { return a.Arg()\
    \ < b.Arg(); });\n    }\n\n    Point Rotate(Point a, double theta) {\n       \
    \ return a.Rotate(theta);\n    }\n\n    scalar Distance(const Point &a, const\
    \ Point &b) {\n        return (a - b).Norm();\n    }\n\n    std::istream &operator>>(std::istream\
    \ &is, Point &a) {\n        scalar x, y;\n        is >> x >> y;\n        a = Point(x,\
    \ y);\n        return is;\n    }\n\n    std::ostream &operator<<(std::ostream\
    \ &os, const Point &a) {\n        os << \"(\" << a.x << \". \" << a.y << \")\"\
    ;\n        return os;\n    }\n}\nusing namespace geometry;\n"
  code: "namespace geometry {\n    using scalar = long long;\n    constexpr scalar\
    \ EPS = 0;\n\n    int Sign(const scalar a) {\n        if (a < -EPS) return -1;\n\
    \        if (a > EPS) return 1;\n        return 0;\n    }\n\n    bool IsEqual(const\
    \ scalar a, const scalar b) {\n        return Sign(a - b) == 0;\n    }\n\n   \
    \ struct Point {\n        scalar x, y;\n\n        Point() = default;\n\n     \
    \   Point(scalar _x, scalar _y) {\n            x = _x, y = _y;\n        }\n\n\
    \        Point operator-() const {\n            return {-x, -y};\n        }\n\n\
    \        Point operator+(const Point &b) const {\n            return {x + b.x,\
    \ y + b.y};\n        }\n\n        Point operator-(const Point &b) const {\n  \
    \          return {x - b.x, y - b.y};\n        }\n\n        Point operator*(const\
    \ scalar &b) const {\n            return {x * b, y * b};\n        }\n\n      \
    \  Point operator/(const scalar &b) const {\n            assert(!IsEqual(b, 0));\n\
    \            return {x / b, y / b};\n        }\n\n        Point operator+=(const\
    \ Point &b) {\n            x += b.x;\n            y += b.y;\n            return\
    \ *this;\n        }\n\n        Point operator-=(const Point &b) {\n          \
    \  x -= b.x;\n            y -= b.y;\n            return *this;\n        }\n\n\
    \        Point operator*=(const scalar b) {\n            x *= b;\n           \
    \ y *= b;\n            return *this;\n        }\n\n        Point operator/=(const\
    \ scalar b) {\n            assert(!IsEqual(b, 0.0));\n            x /= b;\n  \
    \          y /= b;\n            return *this;\n        }\n\n        bool operator==(const\
    \ Point &b) const {\n            return IsEqual(b.x, x) && IsEqual(b.y, y);\n\
    \        }\n\n        scalar Norm() const {\n            return sqrt(x * x + y\
    \ * y);\n        }\n\n        scalar SquaredNorm() const {\n            return\
    \ x * x + y * y;\n        }\n\n        scalar DotProduct(const Point &b) const\
    \ {\n            return x * b.x + y * b.y;\n        }\n\n        scalar CrossProduct(const\
    \ Point &b) const {\n            return x * b.y - y * b.x;\n        }\n\n    \
    \    scalar Arg() const {\n            return std::atan2(y, x);\n        }\n\n\
    \        Point Rotate(double theta) const {\n            return {(scalar) (x *\
    \ cos(theta) - y * sin(theta)), (scalar) (x * sin(theta) + y * cos(theta))};\n\
    \        }\n    };\n\n    inline Point operator*(scalar a, const Point &b) {\n\
    \        return {b.x * a, b.y * a};\n    }\n\n    inline bool operator<(const\
    \ Point &a, const Point &b) {\n        if (Sign(a.x - b.x) != 0) return Sign(a.x\
    \ - b.x) < 0;\n        else return Sign(a.y - b.y) < 0;\n    }\n\n    void SortByArgument(std::vector<Point>\
    \ &v) {\n        sort(v.begin(), v.end(), [&](Point a, Point b) { return a.Arg()\
    \ < b.Arg(); });\n    }\n\n    Point Rotate(Point a, double theta) {\n       \
    \ return a.Rotate(theta);\n    }\n\n    scalar Distance(const Point &a, const\
    \ Point &b) {\n        return (a - b).Norm();\n    }\n\n    std::istream &operator>>(std::istream\
    \ &is, Point &a) {\n        scalar x, y;\n        is >> x >> y;\n        a = Point(x,\
    \ y);\n        return is;\n    }\n\n    std::ostream &operator<<(std::ostream\
    \ &os, const Point &a) {\n        os << \"(\" << a.x << \". \" << a.y << \")\"\
    ;\n        return os;\n    }\n}\nusing namespace geometry;"
  dependsOn: []
  isVerificationFile: false
  path: geometry.h
  requiredBy: []
  timestamp: '2023-03-23 16:34:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry.h
layout: document
redirect_from:
- /library/geometry.h
- /library/geometry.h.html
title: geometry.h
---
