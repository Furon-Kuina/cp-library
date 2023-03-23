#include "bits/stdc++.h"

using namespace std;


namespace util {
    using ll = long long;
    using vl = std::vector<long long>;
    using pl = std::pair<long long, long long>;

    constexpr long long kInf = std::numeric_limits<long long>::max() / 8;
    constexpr long long kMax = std::numeric_limits<long long>::max();

    template<typename T, typename U>
    inline bool UpdateMax(T &x, const U &y) {
        if (x < y) {
            x = y;
            return true;
        }
        return false;
    }

    template<typename T, typename U>
    inline bool UpdateMin(T &x, const U &y) {
        if (x > y) {
            x = y;
            return true;
        }
        return false;
    }

    inline long long Pow(long long x, long long n) {
        assert(n >= 0);
        if (x == 0)
            return 0;
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

    // returns the "arithmetic modulo"
    // for a pair of integers (n, m) with m != 0, there exists a unique pair of integer (q, r)
    // s.t. n = qm + r and 0 <= r < |m|
    // returns this r
    inline long long Mod(long long n, const long long m) {
        assert(m != 0);
        if (m < 0)
            return Mod(n, -m);
        if (n >= 0)
            return n % m;
        else
            return (m + n % m) % m;
    }

    // returns the "arithmetic quotient"
    inline long long Quotient(long long n, long long m) {
        assert((n - Mod(n, m)) % m == 0);
        return (n - Mod(n, m)) / m;
    }


    // returns floor(n / m)
    inline long long DivFloor(long long n, long long m) {
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

    // returns ceil(n / m)
    inline long long DivCeil(long long n, long long m) {
        assert(m != 0);
        if (n % m == 0)
            return DivFloor(n, m);
        else
            return DivFloor(n, m) + 1;
    }

    template<typename T>
    inline T Sum(const std::vector<T> &vec) {
        return std::accumulate(vec.begin(), vec.end(), T(0));
    }
}
using namespace util;


void Solve() {
    
}

int main() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(15);

    Solve();

    return 0;
}