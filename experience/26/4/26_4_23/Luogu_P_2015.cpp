#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vvpii = vector<vector<pair<int,int>>>;
using vpll = vector<pair<ll,ll>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,q;
    cin >> n >> q;
    vvpii g(n);
    for (int i = 1;i < n;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vvt dp(n + 1,vt(q + 1));
    auto dfs = [&](auto&& self,int u,int fa) -> void
    {
        for (auto& [v,w] : g[u])
        {
            if (v == fa) continue;
            self(self,v,u);
            for (int j = q;j >= 1;j--)
            {
                for (int k = 0;k < j;k++) 
                {
                    dp[u][j] = max(dp[u][j],dp[u][j - 1 - k] + dp[v][k] + w);
                }
            }
        }
    };
    dfs(dfs,0,-1);
    cout << dp[0][q] << endl;
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