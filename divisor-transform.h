constexpr ll MAX_N = 100010;
ll sieve[MAX_N];
template <typename T>
void divisor_transform(vector<T> &f){ //\sum_{d divides n}g(n) = f(n) を満たすg(n)を求める
    ll N = f.size();
    memset(sieve, 1, sizeof(sieve));
    for(ll p = 2; p <= N; p++){
        if(sieve[p]){
            for(ll i = 1; i * p < N; i++){
                sieve[i * p] = false;
                f[i] -= f[i * p];
            }
        }
    }
}