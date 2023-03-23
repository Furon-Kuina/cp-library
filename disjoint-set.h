class DisjointSet {
    std::vector<long long> parent_; // 各元の親を表す配列
    std::vector<long long> size_; // 素集合のサイズを表す配列(1 で初期化)

public:
    explicit DisjointSet(long long n) : parent_(n), size_(n, 1LL) {
        for (int i = 0; i < n; ++i)
            parent_[i] = i; // 初期では親は自分自身
    }

    long long Root(long long x) {
        while (parent_[x] != x) {
            x = parent_[x] = parent_[parent_[x]];
        }
        return x;
    }

    bool Merge(long long x, long long y) {
        x = Root(x);
        y = Root(y);
        if (x == y)
            return false;
        if (size_[x] < size_[y])
            swap(x, y);
        size_[x] += size_[y];
        parent_[y] = x;
        return true;
    }

    bool Same(long long x, long long y) {
        return Root(x) == Root(y);
    }

    bool Connected() {
        for (int i = 1; i < (int) parent_.size(); ++i) {
            if (!Same(0, i))
                return false;
        }
        return true;
    }

    long long Size(long long x) {
        return size_[Root(x)];
    }
};