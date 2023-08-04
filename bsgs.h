#include <cassert>
#include <numeric>
#include <unordered_map>

long long DiscreteLog(long long a, long long b, long long m,
                      bool positive = false) {
  // a^x = b(mod m)を満たす最小の非負整数xを返す。存在しない場合は-1
  assert(m != 0);
  if (a == 0) {
    if (b == 0)
      return 0;
    else
      return -1;
  }
  if (a == 1) {
    if (b % m == 1)
      return 0;
    else
      return -1;
  }
  long long k = m, g = 1;
  while (k) {
    k /= 2;
    g *= a;
    g %= m;
  }
  g = std::gcd(g, m);
  long long t = 1, c = positive ? 1 : 0;
  t *= a;
  t %= m;
  for (; t % g; ++c) {
    if (positive && t % g == 0) break;
    if (t == b) return c;
    t *= a;
    t %= m;
  }
  if (b % g) return -1;
  t /= g;
  b /= g;

  long long modified_mod = m / g, h = 0, gs = 1;
  for (; h * h < modified_mod; ++h) {
    gs *= a;
    gs %= modified_mod;
  }
  std::unordered_map<long long, long long> bs;
  for (long long p = 0, x = b; p < h; bs[x] = ++p) {
    x *= a;
    x %= modified_mod;
  }
  for (long long s = 0, e = t; s < modified_mod;) {
    e *= gs;
    e %= modified_mod;
    s += h;
    if (bs.count(e)) return c + s - bs[e];
  }
  return -1;
}