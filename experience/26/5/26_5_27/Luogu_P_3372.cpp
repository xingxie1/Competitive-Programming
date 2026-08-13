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

class segtree{
    vll tr;
    vll lazy;
    int n;
    void push_up(int p)
    {
        tr[p] = tr[p << 1] + tr[p << 1 | 1];
    }
    void build(int p,int l,int r,vll& a) 
    {
        if (l == r) 
        {
            tr[p] = a[l];
            return ;
        }
        int m = (l + r) / 2;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        push_up(p);
    }
    void push_down(int p,int lenl,int lenr)
    {
        if (lazy[p] != 0) 
        {
            lazy[p << 1] += lazy[p];
            lazy[p << 1 | 1] += lazy[p];
            tr[p << 1] += lazy[p] * lenl;
            tr[p << 1 | 1] += lazy[p] * lenr;
            lazy[p] = 0;
        }
    }
    void update(int p,int st,int ed,int l,int r,ll v)
    {
        if (l <= st && r >= ed) 
        {
            lazy[p] += v;
            tr[p] += 1LL * v * (ed - st + 1);
            return ;
        }
        int m = (st + ed) / 2;
        push_down(p,m - st + 1,ed - m);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        push_up(p);
    }
    ll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return tr[p];
        int m = (st + ed) / 2;
        push_down(p,m - st + 1,ed - m);
        ll res = 0;
        if (l <= m) res += query(p << 1,st,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,ed,l,r);
        return res; 
    }
public:
    segtree(vll& a) 
    {
        n = a.size();
        tr.assign(n << 2,0);
        lazy.assign(n << 2,0);
        if (n > 0) build(1,0,n - 1,a);
    }
    void update(int l,int r,ll v) 
    {
        if (l <= r && l >= 0 && r < n) 
        {
            update(1,0,n - 1,l,r,v);
        }
    }
    ll query(int l,int r) 
    {
        if (l <= r && l >= 0 && r < n) 
        {
            return query(1,0,n - 1,l,r);
        }
        return 0;
    }
    
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (m--) 
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            ll x,y,v;
            cin >> x >> y >> v;
            tr.update(x - 1,y - 1,v);
        }
        else 
        {
            int x,y;
            cin >> x >> y;
            cout << tr.query(x - 1,y - 1) << endl;
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