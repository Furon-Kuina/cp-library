template<typename T = long long>
class Compress {
    std::vector<T> vec_;
    std::vector<T> values_;
    std::vector<long long> rank_;

    explicit Compress(const std::vector<T> &vec) : vec_(vec) {
        int n = (int) vec_.size();
        values_ = vec;
        rank_.resize(n);
        std::sort(values_.begin(), values_.end());
        values_.erase(std::unique(values_.begin(), values_.end()), values_.end());
        for (int i = 0; i < n; ++i) {
            rank_[i] = std::lower_bound(values_.begin(), values_.end(), vec[i]) - values_.begin();
        }
    }

    std::vector<T> GetValueList() {
        return values_;
    }

    std::vector<long long> GetRankList() {
        return rank_;
    }

    std::pair<std::vector<T>, std::vector<long long> > GetResult() {
        return {values_, rank_};
    }

    int GetRank(T x) {
        auto itr = std::lower_bound(values_.begin(), values_.end(), x);
        assert(*itr == x);
        return itr - values_.begin();
    }
};