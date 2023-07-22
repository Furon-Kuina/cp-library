namespace binary_set {
inline long long Singleton(const long long x) { return 1LL << x; }

inline long long PopCount(const long long x) { return __builtin_popcount(x); }

template <typename T>
inline bool Contains(const long long S, const T i) {
  return (S & (1LL << i)) != 0;
}

inline long long MostSignificantBit(const long long x) {
  for (int i = 63; i >= 0; --i) {
    if (x & (1LL << i)) return i;
  }
  return -1;
}
}  // namespace binary_set
using namespace binary_set;