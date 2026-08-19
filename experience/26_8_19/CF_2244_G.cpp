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
    vll mx;
    void up(int p)
    {
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    void build(int p,int st,int ed,vll& a)
    {
        if (st == ed)
        {
            mx[p] = a[st];
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m,a);
        build(p << 1 | 1,m + 1,ed,a);
        up(p);
    }
    void update(int p,int st,int ed,int i,ll v)
    {
        if (st == ed)
        {
            mx[p] = v;
            return ;
        }
        int m = st + ed >> 1;
        if (i <= m) update(p << 1,st,m,i,v);
        else update(p << 1 | 1,m + 1,ed,i,v);
        up(p);
    }
    ll query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed) return mx[p];
        int m = st + ed >> 1;
        ll res = 0;
        if (l <= m) res = max(res,query(p << 1,st,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }

public:
    segtree (vll& a)
    {
        n = a.size();
        mx.assign(n << 2,0);
    }
    void update(int i,ll v)
    {
        update(1,0,n - 1,i,v);
    }
    ll query(int l,int r)
    {
        if (r < l) return 0;
        return query(1,0,n - 1,l,r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vll a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    vll tmp(n + 1);
    segtree tr(tmp);
    vvpll b(n + 1,vpll());
    ll ans = 0;
    for (int i = 1;i <= n;i++)
    {
        for (auto& [j,v] : b[i])
        {
            tr.update(j,v);
        }
        ll mx = tr.query(1,i - a[i] - 1);
        ans = max(ans,mx + a[i]);
        if (i + a[i] + 1 <= n)
        {
            b[i + a[i] + 1].push_back({i,mx + a[i]});
        }
    }
    cout << ans << endl;
    
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