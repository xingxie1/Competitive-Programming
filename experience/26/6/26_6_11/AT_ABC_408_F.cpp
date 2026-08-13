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
    void update(int p,int st,int ed,int id,int v) 
    {
        if (st == ed && st == id) 
        {
            tr[p] = v;
            return ;
        }
        int m = st + ed >> 1;
        if (id <= m) update(p << 1,st,m,id,v);
        else update(p << 1 | 1,m + 1,ed,id,v);
        up(p);
    }
    int query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return tr[p];
        }
        int m = st + ed >> 1;
        int res = INT_MIN / 2;
        if (l <= m) res = max(res,query(p << 1,st,m,l,r));
        if (r > m) res = max(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(int _n) 
    {
        n = _n;
        tr.assign(n << 2,INT_MIN / 2);
    }
    void update(int id,int v) 
    {
        update(1,0,n - 1,id,v);
    }
    int query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n, d, r;
    cin >> n >> d >> r;
    vt a(n);
    vt pos(n + 1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        pos[a[i]] = i;
    }
    vt dp(n + 1);
    segtree tr(n);
    for (int h = 1;h <= n;h++) 
    {
        if (h - d >= 1) 
        {
            tr.update(pos[h - d],dp[h - d]);
        }
        int i = pos[h];
        int mx = tr.query(max(i - r,0),min(i + r,n - 1));
        dp[h] = max(mx + 1,0);
    }
    cout << ranges::max(dp) << endl;
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