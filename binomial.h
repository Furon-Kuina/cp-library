template <typename T>
class Binomial {
 private:
  int size_, mod_;
  std::vector<T> fact_, fact_inv_, inv_;

 public:
  explicit Binomial(int size) : size_(size), mod_(T::mod()) {
    fact_.resize(size + 1);
    fact_inv_.resize(size + 1);
    inv_.resize(size + 1);
    fact_[0] = fact_[1] = 1;
    fact_inv_[0] = fact_inv_[1] = 1;
    inv_[1] = 1;
    for (int i = 2; i <= size; ++i) {
      fact_[i] = fact_[i - 1] * i;
      inv_[i] = T(mod_) - inv_[mod_ % i] * (mod_ / i);
      fact_inv_[i] = fact_inv_[i - 1] * inv_[i];
    }
  }

  T Calc(int n, int k) {
    assert(n <= size_ && k <= size_);
    if (k < 0 || n < 0 || n < k) return 0;
    if (k == 0) {
      return 1;
    }

    return fact_[n] * fact_inv_[n - k] * fact_inv_[k];
  }

  T Factorial(int k) {
    assert(k >= 0 && k <= size_);
    return fact_[k];
  }

  T FactorialInv(int k) {
    assert(k >= 0 && k <= size_);
    return fact_inv_[k];
  }
};