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
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

class segtree
{
    int n;
    vll tr,mul,add;
    void up(int p) 
    {
        tr[p] = (tr[p << 1] + tr[p << 1 | 1]) % MOD;
    }
    void apply(int p,int len,ll M,ll D)
    {
        tr[p] = (tr[p] * M % MOD + D * len % MOD) % MOD;
        add[p] = (add[p] * M + D) % MOD;
        mul[p] = mul[p] * M % MOD;
    }
    void down(int p,int ll,int lr) 
    {
        if (add[p] != 0 || mul[p] != 1) 
        {
            apply(p << 1,ll,mul[p],add[p]);
            apply(p << 1 | 1,lr,mul[p],add[p]);
            mul[p] = 1;
            add[p] = 0;
        }
    }
    void build(int p,int l,int r,vll& a) 
    {
        if (l == r) 
        {
            tr[p] = a[l] % MOD;
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void update_add(int p,int st,int ed,int l,int r,ll v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,ed - st + 1,1,v);
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update_add(p << 1,st,m,l,r,v);
        if (r > m) update_add(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    void update_mul(int p,int st,int ed,int l,int r,ll v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,ed - st + 1,v,0);
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update_mul(p << 1,st,m,l,r,v);
        if (r > m) update_mul(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    ll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return tr[p];
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
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
        add.assign(n << 2,0);
        mul.assign(n << 2,1);
        build(1,0,n - 1,a);
    }
    ll query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
    void update_add(int l,int r,ll v) 
    {
        update_add(1,0,n - 1,l,r,v);
    }
    void update_mul(int l,int r,ll v) 
    {
        update_mul(1,0,n - 1,l,r,v);
    }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vpii a(m);
    for (int i = 0;i < m;i++) 
    {
        int x,y;
        cin >> x >> y;
        a[i] = {x,y};
    }
    ranges::sort(a);
    vll dp(n + 1);
    dp[1] = 1;
    segtree tr(dp);
    for (auto& [x,y] : a) 
    {
        ll s = tr.query(x,y);
        // tr.update_mul(1,x - 1,2);
        tr.update_mul(y + 1,n,2);
        tr.update_add(y,y,s);
    }
    cout << tr.query(n,n) << endl;
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