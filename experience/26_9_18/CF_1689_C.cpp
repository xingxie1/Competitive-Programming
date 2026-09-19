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
    vvt g(n);
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vt sz(n);
    auto dfs1 = [&](auto&& self,int u,int fa) -> void
    {
        sz[u] = 1;
        for (int v : g[u])
        {
            if (v == fa) continue;
            self(self,v,u);
            sz[u] += sz[v];
        }
    };
    dfs1(dfs1,0,-1);
    vt dp(n);
    auto dfs2 = [&](auto&& self,int u,int fa) -> void
    {
        int a = -1,b = -1;
        for (int v : g[u])
        {
            if (v == fa) continue;
            if (a == -1) a = v;
            else b = v;
        }
        if (a == -1) return ;
        if (b == -1) 
        {
            self(self,a,u);
            dp[u] = sz[a] - 1;
        } 
        else 
        {
            self(self,a,u);
            self(self,b,u);
            dp[u] = max(dp[b] + sz[a] - 1,dp[a] + sz[b] - 1);
        }
    };
    dfs2(dfs2,0,-1);
    cout << dp[0] << endl;
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