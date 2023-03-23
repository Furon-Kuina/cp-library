template<typename T = long long, int B = 32>
struct BinaryTrie{
private:
    struct node{
        int cnt;
        node* ch[2];
        node() : cnt(0), ch{nullptr, nullptr} {}
    };
    node* add(node* t, T val, int b = B - 1){
        if(!t) t = new node;
        t->cnt += 1;
        if(b < 0) return t;
        bool f = (val >> T(b)) & T(1);
        t->ch[f] = add(t->ch[f], val, b - 1);
        return t;
    }
    node* sub(node* t, T val, int b = B - 1){
        assert(t);
        t->cnt -= 1;
        if(t->cnt == 0) return nullptr;
        if(b < 0) return t;
        bool f = (val >> T(b)) & T(1);
        t->ch[f] = sub(t->ch[f], val, b - 1);
        return t;
    }
    T get_min(node* t, T val, int b = B - 1) const{
        assert(t);
        if(b < 0) return 0;
        bool f = (val >> T(b)) & T(1);
        f ^= !t->ch[f];
        return get_min(t->ch[f], val, b - 1) | (T(f) << T(b));
    }
    T get(node* t, int k, int b = B - 1) const{
        if(b < 0) return 0;
        int m = t->ch[0] ? t->ch[0]->cnt : 0;
        return k < m ? get(t->ch[0], k, b - 1) : get(t->ch[1], k - m, b - 1) | (T(1) << T(b));
    }
    int count_lower(node* t, T val, int b = B - 1){
        if(!t || b < 0) return 0;
        bool f = (val >> T(b)) & T(1);
        return (f && t->ch[0] ? t->ch[0]->cnt : 0) + count_lower(t->ch[f], val, b - 1);
    }
    node *root;
public:
    BinaryTrie() : root(nullptr) {}
    int size() const{
        return root ? root->cnt : 0;
    }
    bool empty() const{
        return !root;
    }
    void insert(T val){
        root = add(root, val);
    }
    void erase(T val){
        root = sub(root, val);
    }
    T max_element(T bias = 0) const{
        return get_min(root, ~bias);
    }
    T min_element(T bias = 0) const{
        return get_min(root, bias);
    }
    int lower_bound(T val){
        return count_lower(root, val);
    }
    int upper_bound(T val){
        return count_lower(root, val + 1);
    }
    T operator[](int k) const{
        assert(0 <= k && k < size());
        return get(root, k);
    }
    int count(T val) const{
        if(!root) return 0;
        node *t = root;
        for(int i = B - 1; i >= 0; i--){
            t = t->ch[(val >> T(i)) & T(1)];
            if(!t) return 0;
        }
        return t->cnt;
    }
};
