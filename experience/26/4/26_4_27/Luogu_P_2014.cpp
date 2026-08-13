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
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
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
    int n,m;
    cin >> n >> m;
    vvt g(n + 1);
    vt a(n + 1);
    for (int i = 1;i <= n;i++)
    {
        int k;
        cin >> k >> a[i];
        g[k].push_back(i);
    }
    vvt dp(n + 1,vt(m + 2));
    auto dfs = [&](auto&& self,int u) -> void
    {
        dp[u][1] = a[u];
        for (int v : g[u]) 
        {
            self(self,v);
            for (int j = m + 1;j >= 1;j--)
            {
                for (int k = 0;k < j;k++)
                {
                    dp[u][j] = max(dp[u][j],dp[u][j - k] + dp[v][k]);
                }
            }
        }
    };
    dfs(dfs,0);
    cout << dp[0][m + 1] << endl;
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