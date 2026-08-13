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
        u--;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    set<pii> ans;
    for (int i = 0;i < n;i++)
    {
        vt sz(n,1);
        auto dfs = [&](auto&& self,int u,int fa) -> void
        {
            for (int v : g[u])
            {
                if (v == fa) continue;
                self(self,v,u);
                sz[u] += sz[v];
            }
        };  
        dfs(dfs,i,-1);
        vt b;
        int sum = 0;
        for (int j : g[i])
        {
            b.push_back(sz[j]);
            sum += sz[j];
        }
        // cout << sum << endl;
        int m = b.size();
        vt dp(sum + 1);
        dp[0] = 1;
        for (int i = 0;i < m;i++)
        {
            for (int j = sum;j >= b[i];j--)
            {
                dp[j] |= dp[j - b[i]];
            }
        }
        for (int i = 1;i <= sum - 1;i++)
        {
            if (dp[i]) 
            {
                ans.insert({i,n - 1 - i});
            }
        }
    }
    cout << ans.size() << endl;
    for (auto&[l,r] : ans) cout << l << " " << r << endl;
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