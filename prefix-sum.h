class PrefixMax {

private:
    int len_{};
    std::vector<long long> arr_;
    std::vector<long long> prefix_max_;
    std::vector<long long> suffix_max_;
public:
    PrefixMax() = default;

    explicit PrefixMax(std::vector<long long> &arr) : arr_(arr), len_((int) arr.size()) {
        prefix_max_.resize(len_ + 1);
        prefix_max_[0] = std::numeric_limits<long long>::min();
        for (int i = 0; i < len_; ++i) {
            prefix_max_[i + 1] = std::max(prefix_max_[i], arr[i]);
        }
        suffix_max_.resize(len_ + 1);
        suffix_max_[len_] = std::numeric_limits<long long>::min();
        for (int i = len_ - 1; i >= 0; --i) {
            suffix_max_[i] = std::max(suffix_max_[i + 1], arr[i]);
        }
    }

    long long MaxTo(long long r) {
        // max(arr[0], ..., arr[r])
        // Note: SumTo(r) is inclusive on r, while RangeSum(begin, end) is not.
        assert(r >= 0);
        assert(r < arr_.size());
        return prefix_max_[r + 1];
    }

    long long MaxFrom(long long r) {
        assert(r >= 0);
        assert(r < arr_.size());
        return suffix_max_[r];
    }

    long long AllMax() {
        return prefix_max_[len_];
    }
};

class PrefixMin {

private:
    int len_{};
    std::vector<long long> arr_;
    std::vector<long long> prefix_min_;
    std::vector<long long> suffix_min_;
public:
    PrefixMin() = default;

    explicit PrefixMin(std::vector<long long> &arr) : arr_(arr), len_((int) arr.size()) {
        prefix_min_.resize(len_ + 1);
        prefix_min_[0] = std::numeric_limits<long long>::max();
        for (int i = 0; i < len_; ++i) {
            prefix_min_[i + 1] = std::min(prefix_min_[i], arr[i]);
        }
        suffix_min_.resize(len_ + 1);
        suffix_min_[len_] = std::numeric_limits<long long>::max();
        for (int i = len_ - 1; i >= 0; --i) {
            suffix_min_[i] = std::min(suffix_min_[i + 1], arr[i]);
        }
    }

    long long MinTo(long long r) {
        // min(arr[0], ..., arr[r])
        assert(r >= 0);
        assert(r < arr_.size());
        return prefix_min_[r + 1];
    }

    long long MinFrom(long long r) {
        assert(r >= 0);
        assert(r < arr_.size());
        return suffix_min_[r];
    }

    long long AllMin() {
        return prefix_min_[len_];
    }
};

template<typename T>
class PrefixSum {

private:
    int len_;
    std::vector<T> arr_;
    std::vector<T> sum_;

public:
    PrefixSum(std::vector<T> &arr) : arr_(arr), len_(arr.size()) {
        sum_.resize(len_ + 1);
        sum_[0] = T(0);
        for (int i = 0; i < len_; ++i) {
            sum_[i + 1] = sum_[i] + arr[i];
        }
    }

    T SumTo(long long r) {
        // arr[0] + ... arr[r]
        // Note: Sum(r) is inclusive on r, while RangeSum(begin, end) is not.
        assert(r >= 0);
        assert(r < arr_.size());
        return sum_[r + 1];
    }

    T SumFrom(long long r) {
        return AllSum() - SumTo(r - 1);
    }

    T RangeSum(long long begin, long long end) {
        // a[begin] + ... + a[end - 1]
        assert(0 <= begin && begin <= end && end <= len_);
        return sum_[end] - sum_[begin];
    }

    T AllSum() {
        return sum_[len_];
    }
};

template<typename T>
struct Ruiseki_2d {
        int H;
        int W;
        vector< vector<T> > A;
        vector< vector<T> >  Sum;
        explicit Ruiseki_2d(vector<vector<T>> v){
            H = (int)v.size();
            W = (int)v[0].size();
            A = v;
            Sum.assign(H+1, vector<T>(W+1, 0));
            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){
                    Sum[i+1][j+1] = Sum[i][j+1] + Sum[i+1][j] + A[i][j] - Sum[i][j];
                }
            }
        }
        T sum(int y1, int y2, int x1, int x2){ //[x1, x2)×[y1, y2)の範囲の和
            return Sum[y2][x2] - Sum[y1][x2] - Sum[y2][x1] + Sum[y1][x1];
        }
};