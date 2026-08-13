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
int MOD;

void solve()
{
    int n;
    cin >> n >> MOD;
    vvt g(n);
    for (int i = 1;i < n;i++) 
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vll down(n),up(n);
    auto dfs1 = [&](auto&& self,int u,int fa) -> void
    {
        down[u] = 1;
        for (int v : g[u]) 
        {
            if (v == fa) continue;
            self(self,v,u);
            down[u] = down[u] * (down[v] + 1) % MOD;
        }
    };
    vll ans(n);
    auto dfs2 = [&](auto&& self,int u,int fa) -> void
    {
        int m = g[u].size();
        vll val(m);
        for (int i = 0;i < m;i++) 
        {
            int v = g[u][i];
            if (v == fa) 
            {
                val[i] = (up[u] + 1) % MOD;
            }
            else 
            {
                val[i] = (down[v] + 1) % MOD;
            }
        }
        vll pre(m + 1,1),suf(m + 1,1);
        for (int i = 0;i < m;i++) 
        {
            pre[i + 1] = pre[i] * val[i] % MOD;
        }
        for (int i = m - 1;i >= 0;i--) 
        {
            suf[i] = suf[i + 1] * val[i] % MOD;
        }
        ans[u] = pre[m];
        for (int i = 0;i < m;i++) 
        {
            int v = g[u][i];
            if (v == fa) continue;
            up[v] = pre[i] * suf[i + 1] % MOD;
            self(self,v,u);
        }
    };
    dfs1(dfs1,0,-1);
    dfs2(dfs2,0,-1);
    for (ll x : ans) cout << x << endl;
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