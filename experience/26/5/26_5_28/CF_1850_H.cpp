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
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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

void solve()
{
    int n,m;
    cin >> n >> m;
    vvpii g(n);
    for (int i = 0;i < m;i++) 
    {
        int u,v,d;
        cin >> u >> v >> d;
        u--;v--;
        g[u].push_back({v,d});
        g[v].push_back({u,-d});
    }
    vll dis(n);
    vt vis(n);
    auto dfs = [&](auto&& self,int u) -> bool
    {
        vis[u] = 1;
        for (auto& [v,d] : g[u])
        {
            if (!vis[v]) 
            {
                dis[v] = dis[u] + d;
                if (!self(self,v)) return false;
            }
            else 
            {
                if (dis[v] != dis[u] + d) return false;
            }
        }
        return true;
    };
    for (int i = 0;i < n;i++) 
    {
        if (!vis[i]) 
        {
            dis[i] = 0;
            if (!dfs(dfs,i)) 
            {
                NO;
                return ;
            }
        }
    }
    YES;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}