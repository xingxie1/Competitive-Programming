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
    vll sum1,sum2,add;
    void up(int p)
    {
        sum1[p] = (sum1[p << 1] + sum1[p << 1 | 1]) % MOD;
        sum2[p] = (sum2[p << 1] + sum2[p << 1 | 1]) % MOD;
    }
    void build(int p,int l,int r,vll& a)
    {
        if (l == r) 
        {
            sum1[p] = a[l];
            sum2[p] = a[l] * a[l] % MOD;
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void apply(int p,ll v,int len)
    {
        sum2[p] = (sum2[p] + 2 * sum1[p] * v % MOD + len * v % MOD * v %MOD) % MOD;
        sum1[p] = (sum1[p] + len * v % MOD) % MOD;
        add[p] = (add[p] + v) % MOD;
    }
    void down(int p,int ll,int lr)
    {
        if (add[p]) 
        {
            apply(p << 1,add[p],ll);
            apply(p << 1 | 1,add[p],lr);
            add[p] = 0;
        }
    }
    void update(int p,int st,int ed,int l,int r,ll v)
    {
        if (l <= st && r >= ed)
        {
            apply(p,v,ed - st + 1);
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    ll query_sum1(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return sum1[p];
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        ll res = 0;
        if (l <= m) res = (res + query_sum1(p << 1,st,m,l,r)) % MOD;
        if (r > m) res = (res + query_sum1(p << 1 | 1,m + 1,ed,l,r)) % MOD;
        return res; 
    } 
    ll query_sum2(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return sum2[p];
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        ll res = 0;
        if (l <= m) res = (res + query_sum2(p << 1,st,m,l,r)) % MOD;
        if (r > m) res = (res + query_sum2(p << 1 | 1,m + 1,ed,l,r)) % MOD;
        return res; 
    }
public: 
    segtree(vll& a)
    {
        n = a.size();
        sum1.assign(n << 2,0);
        sum2.assign(n << 2,0);
        add.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r,ll v)
    {
        update(1,0,n - 1,l,r,v);
    }
    ll query_sum1(int l,int r)
    {
        return query_sum1(1,0,n - 1,l,r);
    }
    ll query_sum2(int l,int r)
    {
        return query_sum2(1,0,n - 1,l,r);
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
    segtree tr(a);
    ll p2 = qpow(2,MOD - 2) % MOD;
    while (q--)
    {
        int l,r,v;
        cin >> l >> r >> v;
        l--;r--;
        tr.update(l,r,v);
        ll s1 = tr.query_sum1(l,r);
        ll s2 = tr.query_sum2(l,r);
        ll ans = (((s1 * s1) % MOD - s2) % MOD + MOD) % MOD;
        ans = ans * p2 % MOD;
        cout << ans << endl;
    }
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