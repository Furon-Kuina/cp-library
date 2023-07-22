#include <algorithm>
#include <numeric>
#include <vector>

template <typename T, typename F>
bool Exists(const std::vector<T> &v, F &&f) {
  return std::any_of(v.begin(), v.end(), f);
}

template <typename T, typename F>
bool ForAll(const std::vector<T> &v, F &&f) {
  return std::all_of(v.begin(), v.end(), f);
}

std::vector<long long> Iota(int len, long long from = 0, long long delta = 1) {
  std::vector<long long> res(len, from);
  for (int i = 1; i < len; ++i) {
    res[i + 1] = res[i] + delta;
  }
  return res;
}

template <typename T>
std::vector<T> Deduplicate(std::vector<T> v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  return v;
}

template <typename T>
inline T Sum(const std::vector<T> &v) {
  return std::accumulate(v.begin(), v.end(), T{});
}

inline long long Max(const std::vector<long long> &v) {
  return *std::max_element(v.begin(), v.end());
}

inline long long Min(const std::vector<long long> &v) {
  return *std::min_element(v.begin(), v.end());
}

class Sorted {
 private:
  const std::vector<long long> &vec_;

 public:
  Sorted(const std::vector<long long> &vec) : vec_(vec) {}

  long long CountInRange(long long begin, long long end) {
    return std::lower_bound(vec_.begin(), vec_.end(), end) -
           std::lower_bound(vec_.begin(), vec_.end(), begin);
  }

  long long CountSmaller(long long x) {
    return std::lower_bound(vec_.begin(), vec_.end(), x) - vec_.begin();
  }

  long long CountLarger(long long x) {
    return vec_.end() - std::upper_bound(vec_.begin(), vec_.end(), x);
  }

  long long CountFrom(long long x) {
    return vec_.end() - std::lower_bound(vec_.begin(), vec_.end(), x);
  }

  long long CountTo(long long x) {
    return std::upper_bound(vec_.begin(), vec_.end(), x) - vec_.begin();
  }
};
