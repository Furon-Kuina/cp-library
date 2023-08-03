#include <atcoder/convolution>
#include <atcoder/modint>

std::vector<atcoder::modint1000000007> ConvolutionMod1000000007(
    const std::vector<atcoder::modint1000000007> &a,
    const std::vector<atcoder::modint1000000007> &b) {
  int n = (int)a.size(), m = (int)b.size();
  std::vector<atcoder::modint1000000007> res(n + m - 1, 0);
  if (std::max(n, m) <= 60) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res[i + j] += a[i] * b[j];
      }
    }
    return res;
  }
  constexpr long long p1 = 167772161, p2 = 469762049, p3 = 1224736769;
  using ModInt2 = atcoder::static_modint<p2>;
  using ModInt3 = atcoder::static_modint<p3>;
  std::vector<long long> a_as_ll(n), b_as_ll(m);
  for (int i = 0; i < n; i++) a_as_ll[i] = a[i].val();
  for (int i = 0; i < m; i++) b_as_ll[i] = b[i].val();
  std::vector<long long> x = atcoder::convolution<p1>(a_as_ll, b_as_ll);
  std::vector<long long> y = atcoder::convolution<p2>(a_as_ll, b_as_ll);
  std::vector<long long> z = atcoder::convolution<p3>(a_as_ll, b_as_ll);
  constexpr int m1_inv_mod_p2 = 104391568;
  constexpr int m1m2_inv_mod_p3 = 721017874;
  constexpr int m1m2_mod_1000000007 = 564826938;
  for (int i = 0; i < n + m - 1; i++) {
    long long v1 = ((y[i] - x[i]) * (ModInt2)m1_inv_mod_p2).val();
    long long v2 =
        ((z[i] - ((ModInt3)(x[i] + p1 * v1)).val()) * (ModInt3)m1m2_inv_mod_p3)
            .val();
    res[i] = (x[i] + p1 * v1 + m1m2_mod_1000000007 * v2);
  }
  return res;
}

std::vector<atcoder::modint> ArbitraryModConvolution(
    const std::vector<atcoder::modint> &a,
    const std::vector<atcoder::modint> &b) {
  int n = (int)a.size(), m = (int)b.size();
  std::vector<atcoder::modint> res(n + m - 1, 0);
  if (std::max(n, m) <= 60) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        res[i + j] += a[i] * b[j];
      }
    }
    return res;
  }
  constexpr long long p1 = 167772161, p2 = 469762049, p3 = 1224736769;
  using ModInt2 = atcoder::static_modint<p2>;
  using ModInt3 = atcoder::static_modint<p3>;
  std::vector<long long> a_as_ll(n), b_as_ll(m);
  for (int i = 0; i < n; i++) a_as_ll[i] = a[i].val();
  for (int i = 0; i < m; i++) b_as_ll[i] = b[i].val();
  std::vector<long long> x = atcoder::convolution<p1>(a_as_ll, b_as_ll);
  std::vector<long long> y = atcoder::convolution<p2>(a_as_ll, b_as_ll);
  std::vector<long long> z = atcoder::convolution<p3>(a_as_ll, b_as_ll);
  const ModInt2 m1_inv_mod_p2 = (((ModInt2)p1).inv()).val();
  const ModInt3 m1m2_inv_mod_p3 = ((ModInt3)(p1 * p2)).inv().val();
  atcoder::modint m1m2_mod_p = p1 * p2;
  for (int i = 0; i < n + m - 1; i++) {
    long long v1 = ((y[i] - x[i]) * m1_inv_mod_p2).val();
    long long v2 =
        ((z[i] - ((ModInt3)(x[i] + p1 * v1)).val()) * m1m2_inv_mod_p3).val();
    res[i] = (x[i] + p1 * v1 + m1m2_mod_p * v2);
  }
  return res;
}