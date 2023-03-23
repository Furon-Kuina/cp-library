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

template<typename T, typename F>
bool Exists(const std::vector<T> &vec, F &&f) {
    return std::any_of(vec.begin(), vec.end(), f);
}

template<typename T, typename F>
bool ForAll(const std::vector<T> &vec, F &&f) {
    return std::all_of(vec.begin(), vec.end(), f);
}

using i128 = __int128;

std::istream &operator>>(std::istream &is, i128 &m) {
    int64_t a;
    is >> a;
    m = a;
    return is;
}

std::ostream &operator<<(std::ostream &os, const i128 &m) {
    os << (int64_t) m;
    return os;
}

std::vector<long long> Iota(int len, long long from = 0) {
    std::vector<long long> res(len, from);
    for(int i = 1; i < len; ++i) {
        res[i + 1] = res[i] + 1;
    }
    return res;
}

class RangeCount {
    
private:
    const std::vector<long long> &vec_;

public:
    RangeCount(const std::vector<long long> &vec) : vec_(vec) {}

    long long CountInRange(long long begin, long long end) {
        return std::lower_bound(vec_.begin(), vec_.end(), end)
               - std::lower_bound(vec_.begin(), vec_.end(), begin);
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

inline long long PowMod(long long x, long long n, const long long m) {
    assert(n >= 0);
    assert(m != 0);
    if (x == 0)
        return 0;
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

template<typename T>
std::vector<std::vector<T>> Rotate(std::vector<std::vector<T>> vector, bool clockwise = false) {
    //反時計回りに90度回転
    int h = vector.size(), w = vector[0].size();
    std::vector<std::vector<T>> res(w, std::vector<T>(h));
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            if (clockwise)
                res[i][j] = vector[h - j - 1][i];
            else
                res[i][j] = vector[j][w - i - 1];
        }
    }
    return res;
}

std::vector<std::string> Rotate(std::vector<std::string> v, bool clockwise = false) {
    int h = v.size(), w = v[0].size();
    std::vector<std::string> res(w, std::string(h, {}));
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
            if (clockwise)
                res[i][j] = v[h - j - 1][i];
            else
                res[i][j] = v[j][w - i - 1];
        }
    }
    return res;
}

long long SqrtFloor(long long n) {
    // n -> floor(sqrt(n))
    assert(n >= 0);
    if(n == 0)
        return 0;
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
    if(n == 0)
        return 0;
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

template<typename T>
std::vector<T> Deduplicate(std::vector<T> v) {
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());
    return v;
}

auto IsValid = [&](long long i, long long j){
    return 0 <= i && i < H && 0 <= j && j < W;
};

namespace debug {
    template<typename T, typename S>
    std::ostream &operator<<(std::ostream &os, const std::pair<T, S> &p) {
        os << "(" << p.first << ", " << p.second << ")";
        return os;
    }

    template<typename T, typename S>
    std::ostream &operator<<(std::ostream &os, const std::map<T, S> &ma) {
        for (auto[a, b]: ma) {
            os << "(" << a << ", " << b << ")"
               << " ";
        }
        return os;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const std::set<T> &s) {
        os << "{";
        for (auto c: s)
            os << c << " ";
        os << "}";
        return os;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const std::multiset<T> &s) {
        os << "{";
        for (auto c: s)
            os << c << " ";
        os << "}";
        return os;
    }

    template<typename T>
    std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
        os << "[";
        for (int i = 0; i < v.size(); i++) {
            os << v[i] << (i == v.size() - 1 ? "" : " ");
        }
        os << "]";
        return os;
    }

    void dump_func() {
        std::cerr << std::endl;
    }

    template<class Head, class... Tail>
    void dump_func(Head &&head, Tail &&...tail) {
        std::cerr << head;
        if (sizeof...(Tail) == 0)
            std::cerr << " ";
        else
            std::cerr << ", ";
        dump_func(std::move(tail)...);
    }

    void assert_ole(bool cond) {
        if (cond) return;
        for (int i = 0; i < 100000000; ++i) {
            std::cout << i;
        }
    }

    void assert_re(bool cond) {
        assert(cond);
    }


}

//#define ONLINE_JUDGE
#ifdef ONLINE_JUDGE
#define dump(...) true
#else
#define dump(...)                                                                                                      \
      std::cerr << __LINE__ << " : (" << #__VA_ARGS__ << ") = ";                                                       \
      dump_func(__VA_ARGS__)
#endif

using namespace debug;