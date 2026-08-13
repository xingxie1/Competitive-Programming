#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

template<typename T>
class segtree {
private:
    int n;
    vector<T> tree;
    vector<T> sum;
    vector<T> aa;
    
    ll calc (int p,int l,int t,ll v)
    {
        if (mx[p] <= v) return v * (r - l + 1);
        if (l == r) return max(aa[l],v);
        int ls = p << 1,rs = p << 1 | 1;
        if (tree[ls] <= v) return v * (r - l + 1) + calc(rs,v);
        else return calc(ls,v) + (sum[p] - sum[ls]);

    }
    void push_up(int p)
    {
        // 【注意】如果是求区间最小值，这里改为 min
        tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
        sum[p] = sum[p << 1] + calc(p << 1 | 1,tree[p << 1]);
    }
    
    void update(int p, int l, int r, int idx, T v)
    {
        if (l == r)
        {
            tree[p] = v;
            return;
        }
        int m = l + (r - l) / 2;
        if (idx <= m) update(p << 1, l, m, idx, v);
        else update(p << 1 | 1, m + 1, r, idx, v);
        
        push_up(p);
    }
    
    T query(int p, int start, int end, int l, int r) 
    {
        if (l <= start && end <= r) return tree[p];
        int m = start + (end - start) / 2;
        
        // 【注意】如果是求区间最小值，这里改为 numeric_limits<T>::max()
        T res = numeric_limits<T>::lowest();
        
        // 【注意】如果是求区间最小值，这里的 max 也改为 min
        if (l <= m) res = max(res, query(p << 1, start, m, l, r));
        if (r > m) res = max(res, query(p << 1 | 1, m + 1, end, l, r));
        
        return res;
    }
    
public: 
    segtree(const vector<T>& a) 
    {
        aa = a;
        n = a.size();
        // 【注意】如果是求区间最小值，这里改为 numeric_limits<T>::max()
        tree.resize(4 * n, numeric_limits<T>::lowest());
        
        auto build = [&](auto&& self, int p, int l, int r) -> void
        {
            if (l == r) 
            {
                tree[p] = a[l];
                return;
            }
            int m = l + (r - l) / 2;
            self(self, p << 1, l, m);
            self(self, p << 1 | 1, m + 1, r);
            push_up(p);
        };
        if (n > 0) 
        {
            build(build, 1, 0, n - 1);
        }
    }
    
    void update(int idx, T v)
    {
        if (idx >= 0 && idx < n) update(1, 0, n - 1, idx, v);
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
void solve()
{
    int n,q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree<ll> tree(a);
    vll pre(n + 1);
    for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + tree.query(i,i);
    int lastans = 0;
    while (q--)
    {
        int u,v;
        cin >> u >> v;
        int l = 1 + (u ^ lastans) % n,t = 1 + (v ^ (lastans + 1)) % (n - l + 1);
        int r = l + t - 1;
        lastans = pre[r] - pre[l - 1];
        // cout << lastans << endl;
        cout << l << " " << r << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}