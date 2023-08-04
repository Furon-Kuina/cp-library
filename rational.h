#include <numeric>

struct Rational {
  using i128 = __int128_t;
  long long u, l;
  inline Rational Normalize() {
    if (l < 0) u = -u, l = -l;
    long long d = std::gcd(u, l);
    if (u == 0) {
      l = 1;
    } else {
      u /= d;
      l /= d;
    }
    return *this;
  }
  Rational(long long u, long long l) : u(u), l(l) { Normalize(); }
  inline Rational operator-() {
    (*this).u *= -1;
    return (*this);
  }
  inline const Rational &operator=(long long a) {
    (*this) = Rational(a, 1);
    return (*this);
  }
};