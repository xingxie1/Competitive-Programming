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
    vt tr;
    void up(int p)
    {
        tr[p] = max(tr[p << 1],tr[p << 1 | 1]);
    }
    void build(int p,int l,int r)
    {
        if (l == r) 
        {
            tr[p] = 0;
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m);
        build(p << 1 | 1,m + 1,r);
        up(p);
    }
    int query(int p,int st,int ed,int l,int r)
    {
        if (l <= st && r >= ed)
        {
            return tr[p];
        }
        int m = st + ed >> 1;
        int res = 0;
        if (l <= m) res = max(res,query(p << 1,st,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
    void update(int p,int st,int ed,int id,int v)
    {
        if (st == id && ed == id)
        {
            tr[p] = v;
            return ;
        }
        int m = st + ed >> 1;
        if (id <= m) update(p << 1,st,m,id,v);
        else update(p << 1 | 1,m + 1,ed,id,v);
        up(p);
    }
public:
    segtree (int _n)
    {
        n = _n;
        tr.assign(n << 2,0);
        build(1,0,n - 1);
    }
    int query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
    void update(int id,int v) 
    {
        update(1,0,n - 1,id,v);
    }
};
void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vt tmp = a;
    ranges::sort(tmp);
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    int m = tmp.size();
    segtree l(m),r(m);
    vt L(n),R(n);
    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        x = ranges::lower_bound(tmp,x) - tmp.begin();
        int mx = 0;
        if (x > 0) 
        {
            mx = l.query(0,x - 1);
        }
        L[i] = mx + 1;
        l.update(x,mx + 1);
    }
    for (int i = n - 1;i >= 0;i--)
    {
        int x = a[i];
        x = ranges::lower_bound(tmp,x) - tmp.begin();
        int mx = 0;
        if (x < m - 1) 
        {
            mx = r.query(x + 1,m - 1);
        }
        R[i] = mx + 1;
        r.update(x,mx + 1);
    }
    int mx = l.query(0,m - 1);
    vt ans;
    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        int id = ranges::lower_bound(tmp,x) - tmp.begin();
        if (L[i] + R[i] - 1 == mx) ans.push_back(i + 1);
    }
    ranges::sort(ans);
    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;
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