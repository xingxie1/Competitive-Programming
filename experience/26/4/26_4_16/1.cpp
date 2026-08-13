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
const int MOD = (int)1e9+7;

long long qpow(long long a,long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}
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
    vvt dp(n,vt(2));
    auto dfs = [&](auto&& self,int u,int fa) -> void
    {
        dp[u][0] = 1;
        dp[u][1] = 1;
        for (int v : g[u]) 
        {
            if (v != fa) 
            {
                self(self,v,u);
                dp[u][0] = (dp[u][0] * dp[v][1]) % MOD;
                dp[u][1] = (dp[u][1] * (dp[v][0] + dp[v][1])) % MOD;
            }
        }
    };
    dfs(dfs,0,-1);
    ll ans = (dp[0][0] + dp[0][1]) % MOD;
    cout << ans << endl;

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