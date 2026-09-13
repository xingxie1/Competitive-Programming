#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<ll>;
using pii = pair<int,int>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
void solve()
{
    int n,q;
    cin >> n >> q;
    vvt g(n);
    for (int i = 0;i < n;i++) 
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vt sz(n),p(n);
    auto dfs = [&](auto&& self,int u,int fa) -> void
    {
        sz[u] = 1;
        p[u] = rng();
        for (int v : g[u])
        {
            if (v == fa) continue;
            self(self,v,u);
            sz[u] += sz[v];
            p[u] ^= p[v];
        }
    };
    dfs(dfs,0,-1);
    while (q--)
    {
        int k;
        cin >> k;
        
    }

}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

    return 0;
}