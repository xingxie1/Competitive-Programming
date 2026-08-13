#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int m,a,b;
    cin >> m >> a >> b;
    queue<pii> q; 
    map<pii,vpii> g;
    vvt vis(m,vt(m));
    for (int u = 0;u < m;u++)
    {
        for (int v = 0;v < m;v++)
        {
            int w = (a * v + b * u ) % m;
            g[{v,w}].push_back({u,v});
        }
        q.push({u,0});
        q.push({0,u});
        vis[0][u] = 1;
        vis[u][0] = 1;
    }
    while (!q.empty())
    {
        auto [v,w] = q.front();
        q.pop();
        for (auto&[u,v] : g[{v,w}])
        {
            if (!vis[u][v])
            {
                q.push({u,v});
                vis[u][v] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0;i < m;i++)
    {
        for (int j : vis[i]) ans += (j == 0);
    }
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