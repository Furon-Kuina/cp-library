template <typename T>
std::vector<int> InversePermutation(const std::vector<T> &v) {
  int n = (int)v.size();
  std::vector<int> res(n, -1);
  for (int i = 0; i < n; ++i) {
    assert(res[i] == -1);
    res[i] = i;
  }
  return res;
}