struct rational {
  long long u, l;
  inline rational normalize() {
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
  rational(long long u, long long l) : u(u), l(l) { normalize() }
  inline rational operator-() {
    (*this).u *= -1;
    return (*this);
  }
  inline const rational &operator=(long long a) {
    (*this) = rational(a, 1);
    return (*this);
  }
};