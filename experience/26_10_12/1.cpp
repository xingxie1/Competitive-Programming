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

void solve()
{
    int n;
    cin >> n;
    vll c(n),w(n);
    for (int i = 0;i < n;i++) cin >> c[i];
    for (int i = 0;i < n;i++) cin >> w[i];
    vvt g(n);
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vpll a(n);
    vll ans(n + 1,LLONG_MIN / 2);
    auto update = [&](int u,ll v) -> void
    {
        if (v > a[u].fi) 
        {
            a[u].se = a[u].fi;
            a[u].fi = v;
            return ;
        }
        if (v > a[u].se) a[u].se = v;
    };
    auto dfs1 = [&](auto&& self,int u,int fa) -> void
    {
        for (int v : g[u])
        {
            if (v == fa) continue;
            self(self,v,u);
            update(u,a[v].fi + w[v]);
        }
    };
    auto dfs2 = [&](auto&& self,int u,int fa) -> void
    {
        for (int v : g[u])
        {
            if (v == fa) continue;
            ll x = (a[v].fi + w[v] == a[u].fi) ? a[u].se : a[u].fi;
            update(v,x + w[u]);
            self(self,v,u);
        }
    }; 
    dfs1(dfs1,0,-1);
    dfs2(dfs2,0,-1);
    for (int i = 0;i < n;i++) ans[c[i]] = max(ans[c[i]],a[i].fi + a[i].se + w[i]);
    for (int i = 1;i <= n;i++) 
    {
        if (ans[i] == LLONG_MIN / 2) cout << -1 << " ";
        else cout << ans[i] << " ";
    }
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