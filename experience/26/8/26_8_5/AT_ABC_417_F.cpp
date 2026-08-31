#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
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
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

class segtree
{
    int n;
    vll sum,isu,upd;
    void up(int p) 
    {
        sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % MOD;
    }
    void apply(int p,int len,ll d)
    {
        sum[p] = len * d;
        isu[p] = 1;
        upd[p] = d;
    }
    void down(int p,int ll,int lr)
    {
        if (isu[p]) 
        {
            apply(p << 1,ll,upd[p]);
            apply(p << 1 | 1,lr,upd[p]);
            isu[p] = 0;
        }
    }
    void build(int p,int st,int ed,vll& a)
    {
        if (st == ed) 
        {
            sum[p] = a[st];
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m,a);
        build(p << 1 | 1,m + 1,ed,a);
        up(p);
    }
    void update(int p,int st,int ed,int l,int r,ll v)
    {
        if (l <= st && r >= ed)
        {
            apply(p,ed - st + 1,v);
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    ll query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return sum[p];
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        ll res = 0;
        if (l <= m) res = (res + query(p << 1,st,m,l,r)) % MOD;
        if (r > m) res = (res + query(p << 1 | 1,m + 1,ed,l,r)) % MOD;
        return res;
    }
public: 
    segtree(vll& a) 
    {
        n = a.size();
        sum.assign(n << 2,0);
        isu.assign(n << 2,0);
        upd.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r,ll v) 
    {
        update(1,0,n - 1,l,r,v);
    }
    ll query(int l,int r)
    {
        return query(1,0,n - 1,l,r);
    }
};

ll qpow(ll a,ll b)
{
    ll ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void solve()
{
    int n,q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        l--;r--;
        ll sum = tr.query(l,r);
        int len = r - l + 1;
        ll ans = sum * qpow(len,MOD - 2) % MOD;
        tr.update(l,r,ans);
    }
    for (int i = 0;i < n;i++) cout << tr.query(i,i) << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}