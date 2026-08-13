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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

class segtree
{
    vll mn;
    int n;
    void up(int p) 
    {
        mn[p] = min(mn[p << 1], mn[p << 1 | 1]);
    }
    void build(int p,int l,int r)
    {
        if (l == r) 
        {
            mn[p] = LLONG_MAX / 2;
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m);
        build(p << 1 | 1,m + 1,r);
        up(p);
    }
    void update(int p,int st,int ed,int id,ll v)
    {
        if (st == id && ed == id)
        {
            mn[p] = v;
            return ;
        }
        int m = st + ed >> 1;
        if (id <= m) update(p << 1,st,m,id,v);
        if (id > m) update(p << 1 | 1,m + 1,ed,id,v);
        up(p);
    }
    ll query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed) 
        {
            return mn[p];
        }
        int m = st + ed >> 1;
        ll res = LLONG_MAX / 2;
        if (l <= m) res = min(res,query(p << 1,st,m,l,r));
        if (r > m) res = min(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(int _n) 
    {
        n = _n;
        mn.assign(n << 2,LLONG_MAX / 2);
        build(1,0,n - 1);
    }
    void update(int id,ll v)
    {
        update(1,0,n - 1,id,v);
    }
    ll query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    int m;
    cin >> m;
    vpii b(m);
    vt p(n + 1);
    for (int i = 0;i < m;i++) 
    {
        cin >> b[i].fi >> b[i].se;
        p[b[i].se] = max(p[b[i].se],b[i].fi);
    }
    for (int i = 0;i < n;i++) 
    {
        p[i + 1] = max(p[i],p[i + 1]);
    }
    segtree tr(n + 1);
    tr.update(0,0);
    for (int i = 1;i <= n;i++)
    {
        // cout << p[i] << " " << i << endl;
        tr.update(i,tr.query(p[i - 1],i - 1) + a[i]);
    }
    cout << tr.query(p[n],n) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}