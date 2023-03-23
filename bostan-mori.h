vector<modint1000000007> convolution1000000007(const vector<modint1000000007> &a, const vector<modint1000000007> &b){
    //a_n = c_1 * a_{n-1} + ... + c_d * a_{n-d}という線形漸化式で表される数列のN項目を計算する
    //aには初めのd項を添字の昇順に、cには係数を添字の昇順に並べたvectorを渡す
    int n = (int)a.size(), m = (int)b.size();
    vector<modint1000000007> ret(n + m - 1, 0);
    if(max(n, m) <= 100){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ret[i+j] += a[i] * b[j];
            }
        }
        return ret;
    }
    using mint1 = static_modint<167772161>;
    using mint2 = static_modint<469762049>;
    using mint3 = static_modint<1224736769>;
    vector<long long> a_int(n), b_int(m);
    for(int i = 0; i < n; i++) a_int[i] = a[i].val();
    for(int i = 0; i < m; i++) b_int[i] = b[i].val();
    vector<long long> x = convolution<167772161>(a_int, b_int);
    vector<long long> y = convolution<469762049>(a_int, b_int);
    vector<long long> z = convolution<1224736769>(a_int, b_int);
    const mint2 m1_inv_mod_m2 = (((mint2)(167772161)).inv()).val();
    const mint3 m1m2_inv_mod_m3 = (((mint3)((long long)167772161 * (long long)469762049)).inv()).val();
    modint1000000007 m1m2_mod_1000000007 = (long long)167772161 * (long long)469762049;
    for(int i = 0; i < n + m - 1; i++){
        long long v1 = ((y[i] - x[i]) * m1_inv_mod_m2).val();
        long long v2 = ((z[i] - ((mint3)(x[i] + 167772161 * v1)).val()) * m1m2_inv_mod_m3).val();
        ret[i] = (x[i] + 167772161 * v1 + m1m2_mod_1000000007 * v2);
    }
    return ret;
}

modint1000000007 Bostan_Mori(const vector<modint1000000007> &a, vector<modint1000000007> &c, long long N) {
    assert(a.size() == c.size());
    int d = c.size();
    c.resize(d + 1);
    for(int i = d; i >= 1; i--)
        c[i] = -c[i-1];
    c[0] = 1;
    auto P = convolution1000000007(a, c);
    P.resize(d);
    while(N){
        auto Q_minus = c;
        for(int i = 1; i <= d; i += 2)
            Q_minus[i] *= -1;
        P = convolution1000000007(P, Q_minus);
        c = convolution1000000007(c, Q_minus);
        P.resize(2 * d + 1);
        c.resize(2 * d + 1);
        for(int i = 0; i < d; i++)
            P[i] = P[(i << 1) | (N & 1)];
        for(int i = 0; i <= d; i++)
            c[i] = c[i << 1];
        P.resize(d);
        c.resize(d+1);
        N >>= 1;
    }
    return P[0];
}

modint998244353 BostanMori(const vector<modint998244353> &a, vector<modint998244353> &c, long long N){
    //a_n = c_1 * a_{n-1} + ... + c_d * a_{n-d}という線形漸化式で表される数列のN項目を計算する
    //aには初めのd項を添字の昇順に、cには係数を添字の昇順に並べたvectorを渡す
    assert(a.size() == c.size());
    int d = (int)c.size();
    c.resize(d + 1);
    for(int i = d; i >= 1; i--)
        c[i] = -c[i-1];
    c[0] = 1;
    vector<modint998244353> P = convolution(a, c);
    P.resize(d);
    while(N){
        auto Q_minus = c;
        for(int i = 1; i <= d; i += 2)
            Q_minus[i] *= -1;
        P = convolution(P, Q_minus);
        c = convolution(c, Q_minus);
        for(int i = 0; i < d; i++)
            P[i] = P[(i << 1) | (N & 1)];
        for(int i = 0; i <= d; i++)
            c[i] = c[i << 1];
        P.resize(d);
        c.resize(d + 1);
        N >>= 1;
    }
    return P[0];
}