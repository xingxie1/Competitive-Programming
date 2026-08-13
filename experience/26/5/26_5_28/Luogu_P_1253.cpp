#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

template<typename T>
class segtree
{
private:
    vector<T> tree;
    vector<T> set;
    vector<T> add;
    vector<int> has_set;
    int n;

    void push_up(int p)
    {
        // 如果是区间最小值，这里改成 min
        tree[p] = max(tree[p << 1], tree[p << 1 | 1]);
    }

    void apply_set(int p,T v) 
    {
        tree[p] = v;
        set[p] = v;
        add[p] = 0;
        has_set[p] = 1;
    }
    void apply_add(int p,T v) 
    {
        tree[p] += v;
        if (has_set[p]) set[p] += v;
        else add[p] += v;
    }
    void push_down(int p) 
    {
        if (has_set[p]) 
        {
            apply_set(p << 1,set[p]);
            apply_set(p << 1 | 1,set[p]);
            has_set[p] = 0;
        }
        if (add[p]) 
        {
            apply_add(p << 1,add[p]);
            apply_add(p << 1 | 1,add[p]);
            add[p] = 0;
        }
    } 

    void build(int p,int l,int r,const vector<T>& a)
    {
        if (l == r)
        {
            tree[p] = a[l];
            return ;
        }

        int m = l + (r - l) / 2;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        push_up(p);
    }

    void range_set(int p,int st,int ed,int l,int r,T v)
    {
        if (l <= st && ed <= r) 
        {
            apply_set(p,v);
            return ;
        }
        push_down(p);
        int m = st + ed >> 1;
        if (l <= m) range_set(p << 1,st,m,l,r,v);
        if (r > m) range_set(p << 1 | 1,m + 1,ed,l,r,v);
        push_up(p);
    }
    void range_add(int p,int st,int ed,int l,int r,T v) 
    {
        if (l <= st && r >= ed) 
        {
            apply_add(p, v);
            return ;
        }
        push_down(p);
        int m = st + ed >> 1;
        if (l <= m) range_add(p << 1,st,m,l,r,v);
        if (r > m) range_add(p << 1 | 1,m + 1,ed,l,r,v);
        push_up(p);
    }

    // 查询区间 [l,r] 最大值
    T query(int p,int start,int end,int l,int r)
    {
        if (l <= start && end <= r) return tree[p];

        int m = start + (end - start) / 2;

        // 如果是区间最小值，这里改成 numeric_limits<T>::max()
        T res = numeric_limits<T>::lowest();
        push_down(p);
        if (l <= m) res = max(res,query(p << 1,start,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,end,l,r));

        return res;
    }

public:
    segtree(const vector<T>& a)
    {
        n = a.size();

        // 如果是区间最小值，这里改成 numeric_limits<T>::max()
        tree.assign(4 * n,numeric_limits<T>::lowest());
        add.assign(4 * n,0);
        set.assign(4 * n,0);
        has_set.assign(4 * n,0);

        if (n > 0)
        {
            build(1,0,n - 1,a);
        }
    }

    void range_set(int l,int r,T v) 
    {
        range_set(1,0,n - 1,l,r,v);
    }
    void range_add(int l,int r,T v)
    {
        range_add(1,0,n - 1,l,r,v);
    } 

    // 查询区间 [l,r] 最大值，下标从 0 开始
    T query(int l,int r)
    {
        if (l <= r && l >= 0 && r < n)
        {
            return query(1,0,n - 1,l,r);
        }

        // 如果是区间最小值，这里改成 numeric_limits<T>::max()
        return numeric_limits<T>::lowest();
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (q--) 
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            ll l, r, x;
            cin >> l >> r >> x;
            tr.range_set(l - 1,r - 1,x);
        }
        else if (op == 2) 
        {
            ll l,r,x;
            cin >> l >> r >> x;
            tr.range_add(l - 1,r - 1,x);
        }
        else 
        {
            ll l, r;
            cin >> l >> r;
            cout << tr.query(l - 1,r - 1) << endl;
        }
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