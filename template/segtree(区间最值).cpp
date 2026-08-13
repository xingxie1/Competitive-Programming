template<typename T>
class segtree {
private:
    int n;
    vector<T> tr;
    
    void up(int p)
    {
        tr[p] = max(tr[p << 1], tr[p << 1 | 1]);
    }
    void build(int p,int st,int ed,vt& a)
    {
        if (l == r) 
        {
            tr[p] = a[l];
            return;
        }
        int m = l + (r - l) / 2;
        build(p << 1, l, m,a);
        build(p << 1 | 1, m + 1, r,a);
        up(p);
    }
    void update(int p, int l, int r, int id, T v)
    {
        if (l == r)
        {
            tr[p] = v;
            return;
        }
        int m = l + (r - l) / 2;
        if (id <= m) update(p << 1, l, m, id, v);
        else update(p << 1 | 1, m + 1, r, id, v);
        
        up(p);
    }
    
    T query(int p, int st, int ed, int l, int r) 
    {
        if (l <= st && r >= ed) return tr[p];
        int m = st + (ed - st) / 2;
        
        T res = numeric_limits<T>::lowest();
        
        if (l <= m) res = max(res, query(p << 1, st, m, l, r));
        if (r > m) res = max(res, query(p << 1 | 1, m + 1, ed, l, r));
        
        return res;
    }
    
public: 
    segtree(const vector<T>& a) 
    {
        n = a.size();
        tr.resize(4 * n, numeric_limits<T>::lowest());

        if (n > 0) 
        {
            build(build, 1, 0, n - 1);
        }
    }
    
    void update(int id, T v)
    {
        if (id >= 0 && id < n) update(1, 0, n - 1, id, v);
    }
    
    T query(int l, int r)
    {
        if (l <= r && l >= 0 && r < n)
        {
            return query(1, 0, n - 1, l, r);
        }
        // 【注意】如果是求区间最小值，这里改为 numeric_limits<T>::max()
        return numeric_limits<T>::lowest();
    }
};