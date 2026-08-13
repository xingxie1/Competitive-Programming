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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if (n == 2) 
    {
        NO;
        return ;
    }
    int f = -1;
    vt vis(n);
    vvt ans(n);
    for (int i = 0;i < n;i++) 
    {
        for (int j : g[i]) 
        {
            if (g[j].size() == 2) 
            {
                f = i;
                int k = g[j][0];
                if (k == i) k = g[j][1];
                ans[i].push_back(j);
                ans[j].push_back(k);
                vis[i] = vis[j] = vis[k] = 1;
                break;
            }
        }
        if (f != -1) break;
    }
    if (f == -1) 
    {
        NO;
        return ;
    }
    auto dfs = [&](auto&& self,int u,int fa,int val) -> void
    {
        for (int v : g[u]) 
        {
            if (v == fa) continue;
            if (vis[u] && vis[v]) 
            {
                self(self,v,u,1);
                continue;
            }
            if (val == 0) ans[u].push_back(v);
            else ans[v].push_back(u);
            self(self,v,u,val ^ 1);
        }
    };
    dfs(dfs,f,-1,0);
    YES;
    for (int i = 0;i < n;i++) 
    {
        for (int j : ans[i]) cout << i + 1 << " " << j + 1 << endl;
    }
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