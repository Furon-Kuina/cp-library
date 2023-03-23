#include <vector>
#include <cassert>
#include <algorithm>

namespace arithmetic {
    class Sieve {
    private:
        int max_;
        int size_;
        std::vector<int> lpf_;
        std::vector<int> lpf_exp_;
        std::vector<int> lpf_div_;

    public:
        std::vector<int> prime_list;

        Sieve(int max) : max_(max), size_(max + 1) {
            lpf_.resize(size_, -1);
            lpf_exp_.resize(size_);
            lpf_div_.resize(size_);
            for (int i = 2; i < size_; ++i) {
                if (lpf_[i] == -1) {
                    lpf_[i] = i;
                    prime_list.emplace_back(i);
                }
                for (int p: prime_list) {
                    if (p * i > max || p > lpf_[i]) break;
                    lpf_[p * i] = p;
                }
            }
            for (int i = 2; i < size_; ++i) {
                int k = i / lpf_[i];
                if (lpf_[i] != lpf_[k]) {
                    lpf_exp_[i] = 1;
                    lpf_div_[i] = k;
                } else {
                    lpf_exp_[i] = lpf_exp_[k] + 1;
                    lpf_div_[i] = lpf_div_[k];
                }
            }
        }

        bool IsPrime(int n) {
            assert(n <= max_);
            return lpf_[n] == n;
        }

        struct Factor {
            long long prime;
            long long exp;

            Factor(long long p, long long e) : prime(p), exp(e) {}
        };

        std::vector<Factor> PrimeFactors(int n) {
            std::vector<Factor> res;
            while (n > 1) {
                res.emplace_back(lpf_[n], lpf_exp_[n]);
                n = lpf_div_[n];
            }
            return res;
        }

    };

    std::vector<long long> Divisor(long long n) { //nの約数を昇順に並べたvectorを返す
        std::vector<long long> res;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                res.emplace_back(i);
                if (i * i != n) res.emplace_back(n / i);
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
}
using namespace arithmetic;
