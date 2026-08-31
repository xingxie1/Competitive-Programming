#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;

const int MOD = (int)1e9 + 7;
void solve()
{
    int n,k;
    while (cin >> n >> k)
    {
        vvt g(n);
        for (int i = 1;i < n;i++)
        {
            int u,v;
            cin >> u >> v;
            u--;v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        vvt dp(n,vt(k + 1));
        vt sz(n);
        auto dfs = [&](auto&& self,int u,int fa) -> int
        {
            sz[u] = 1;
            for (int v : g[u])
            {
                if (v == fa) continue; 
                sz[u] += self(self,v,u);
            }
            return sz[u];
        };
        dfs(dfs,0,-1);
        auto dfs2 = [&](auto&& self,int u,int fa)
        {
            for (int j = 0;j <= sz[u];j++)
            {
                
            }
        };
    }

}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}