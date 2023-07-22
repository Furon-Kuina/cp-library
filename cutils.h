#include <cassert>
#include <cmath>
constexpr long long kMax = std::numeric_limits<long long>::max();

inline long long CountDigit(long long n, const long long base = 10) {
  assert(n > 0);
  assert(base > 1);
  long long res = 0;
  while (n) {
    res++;
    n /= base;
  }
  return res;
}

// verified
inline long long Pow(long long x, long long n) {
  assert(n >= 0);
  if (x == 0) return 0;
  long long res = 1LL;
  while (n > 0) {
    if (n & 1) {
      assert(x != 0 && std::abs(res) <= kMax / std::abs(x));
      res = res * x;
    }
    if (n >>= 1) {
      assert(x != 0 && std::abs(x) <= kMax / std::abs(x));
      x = x * x;
    }
  }
  return res;
}

// verified
inline long long Mod(long long n, const long long m) {
  // returns the "arithmetic modulo"
  // for a pair of integers (n, m) with m != 0, there exists a unique pair of
  // integer (q, r) s.t. n = qm + r and 0 <= r < |m| returns this r
  assert(m != 0);
  if (m < 0) return Mod(n, -m);
  if (n >= 0)
    return n % m;
  else
    return (m + n % m) % m;
}

inline long long Quotient(long long n, long long m) {
  // returns the "arithmetic quotient"
  assert((n - Mod(n, m)) % m == 0);
  return (n - Mod(n, m)) / m;
}

inline long long DivFloor(long long n, long long m) {
  // returns floor(n / m)
  assert(m != 0);
  if (m < 0) {
    n = -n;
    m = -m;
  }
  if (n >= 0)
    return n / m;
  else if (n % m == 0)
    return -(std::abs(n) / m);
  else
    return -(std::abs(n) / m) - 1;
}

inline long long DivCeil(long long n, long long m) {
  // returns ceil(n / m)
  assert(m != 0);
  if (n % m == 0)
    return DivFloor(n, m);
  else
    return DivFloor(n, m) + 1;
}

inline long long PowMod(long long x, long long n, const long long m) {
  assert(n >= 0);
  assert(m != 0);
  if (x == 0) return 0;
  long long res = 1;
  x = Mod(x, m);
  while (n > 0) {
    if (n & 1) {
      assert(x == 0 || std::abs(res) <= kMax / std::abs(x));
      res = Mod(res * x, m);
    }
    if (n >>= 1) {
      assert(x == 0 || std::abs(x) <= kMax / std::abs(x));
      x = Mod(x * x, m);
    }
  }
  return res;
}

long long SqrtFloor(long long n) {
  // n -> floor(sqrt(n))
  assert(n >= 0);
  if (n == 0) return 0;
  long long ok = 0;
  long long ng = n + 1;
  while (ng - ok > 1) {
    long long mid = (ok + ng) / 2;
    if (mid <= n / mid) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

long long SqrtCeil(long long n) {
  // n -> ceil(sqrt(n))
  assert(n >= 0);
  if (n == 0) return 0;
  long long ok = n;
  long long ng = 0;
  while (ok - ng > 1) {
    long long mid = (ok + ng) / 2;
    if (mid >= n / mid) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}
