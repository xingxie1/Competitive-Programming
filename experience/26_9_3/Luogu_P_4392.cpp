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
    vt mn,mx;
    void up(int p)
    {
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
        mx[p] = max(mx[p << 1],mx[p << 1 | 1]);
    }
    void build(int p,int st,int ed,vt& a)
    {
        if (st == ed) 
        {
            mn[p] = mx[p] = a[st];
            return ;
        }
        int m = st + ed >> 1;
        build(p << 1,st,m,a);
        build(p << 1 | 1,m + 1,ed,a);
        up(p);
    }
    int query_max(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return mx[p];
        }
        int m = st + ed >> 1;
        int res = 0;
        if (l <= m) res = max(res,query_max(p << 1,st,m,l,r));
        if (r > m) res = max(res,query_max(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
    int query_min(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return mn[p];
        }
        int m = st + ed >> 1;
        int res = INT_MAX / 2;
        if (l <= m) res = min(res,query_min(p << 1,st,m,l,r));
        if (r > m) res = min(res,query_min(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree (vt& a)
    {
        n = a.size();
        mn.assign(n << 2,INT_MAX / 2);
        mx.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    int query_max(int l,int r)
    {
        return query_max(1,0,n - 1,l,r);
    }
    int query_min(int l,int r)
    {
        return query_min(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n,m,c;
    cin >> n >> m >> c;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    segtree tr(a);
    vt ans;
    for (int i = 0;i + m - 1 < n;i++)
    {
        int mx = tr.query_max(i,i + m - 1);
        int mn = tr.query_min(i,i + m - 1);
        if (mx - mn <= c) ans.push_back(i + 1);
    }
    if (ans.empty()) cout << "NONE" << endl;
    else 
    {
        for (int x : ans) cout << x << endl;
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