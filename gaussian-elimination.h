std::vector<long long> GaussianElimination(const std::vector<long long> &binary_vectors) {
    std::vector<long long> basis;
    for (auto v: binary_vectors) {
        for (long long e: basis) {
            v = std::min(v, v ^ e);
        }
        if (v > 0)
            basis.emplace_back(v);
    }
    std::sort(basis.begin(), basis.end());
    int k = (int) basis.size();
    for (int i = 0; i < k; ++i) {
        int msb = __builtin_clzll(basis[i]);
        long long e = (1LL << (63 - msb));
        for (int j = i + 1; j < k; ++j) {
            if (basis[j] & e)
                basis[j] ^= basis[i];
        }
    }
    return basis;
}