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
    int n;
    vll add,mx;
    void up(int p)
    {
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    void apply(int p,ll v) 
    {
        mx[p] += v;
        add[p] += v;
    }
    void down(int p)
    {
        if (add[p]) 
        {
            apply(p << 1,add[p]);
            apply(p << 1 | 1,add[p]);
            add[p] = 0;
        }
    }
    void build(int p,int l,int r,vll& a)
    {
        if (l == r) 
        {
            mx[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void update(int p,int st,int ed,int l,int r,ll v) 
    {
        if (l <= st && r >= ed) 
        {
            apply(p,v);
            return ;
        }
        int m = st + ed >> 1;
        down(p);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    ll query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed) return mx[p];
        int m = st + ed >> 1;
        down(p);
        ll res = 0;
        if (l <= m) res = max(res,query(p << 1,st,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(vll& a) 
    {
        n = a.size();
        mx.assign(n << 2,0);
        add.assign(n << 2,0);
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

void solve()
{
    int n,d,w;
    cin >> n >> d >> w;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    ranges::sort(a);
    int l = 0,r = 0;
    vll tmp(2e5 + 5);
    segtree tr(tmp);
    ll ans = 0;
    while (r < n) 
    {
        auto [t,x] = a[r];
        // cout << t << " " << x << " " << max(1,x - w + 1) << endl;
        tr.update(max(1,x - w + 1),x,1);
        while (l < r && a[r].fi - a[l].fi >= d) 
        {
            // cout << l << " " << r << endl;
            tr.update(max(1,a[l].se - w + 1),a[l].se,-1);
            l++;
        }
        // cout << tr.query(1,2e5) << endl;
        // for (int j = 1;j <= 5;j++) cout << tr.query(j,j) << endl;
        // cout << endl;
        ans = max(ans,tr.query(1,2e5));
        r++;
    }
    cout << ans << endl;
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