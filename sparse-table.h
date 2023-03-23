struct sparsetable{
    vector<vector<long long>> st;
    vector<int> lookup;

    explicit sparsetable(const vector<long long> &v){
        const int n = (int)v.size();
        const int b = 32 - __builtin_clz(n);
        st.assign(b, vector<long long>(n));
        for(int i = 0; i < n; i++){
            st[0][i] = v[i];
        }
        for(int i = 1; i < b; i++){
            for(int j = 0; j + (1 << i) <= n; j++){
                st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i-1))]);
            }
        }
        lookup.resize(n+1);
        for(int i = 2; i < n + 1; i++){
            lookup[i] = lookup[i >> 1] + 1;
        }
    }

    inline long long rmq(long long l, long long r){
        //a_l, ... a_{r-1}の最小値
        int b = lookup[r-l];
        return min(st[b][l], st[b][r - (1 << b)]);
    }
};