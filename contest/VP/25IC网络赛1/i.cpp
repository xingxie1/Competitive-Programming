#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using pii = pair<int,int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vvpii = vector<vector<pii>>;

void solve()
{
    int n,m,v,t;
    cin >> n >> m >> v >> t;
    t--;
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
    pq.push({1,0,t});
    vvpii g(n);
    vpii dp(n,{INT_MAX / 2,v});
    dp[t] = {1,0};
    for (int i = 0;i < m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    while (!pq.empty())
    {
        auto [d,r,x] = pq.top();
        pq.pop();
        if (d > dp[x].fi || (d == dp[x].fi && r > dp[x].se)) continue;
        for (auto& [y,w] : g[x])
        {
            int nd = INT_MAX / 2,nr = INT_MAX/ 2;
            if (w + r <= v) 
            {
                nr = r + w;
                nd = d;
            }
            else if (w + r > v && w <= v) 
            {
                nd = d + 1;
                nr = w;
            }
            else if (w > v) continue;

            if (nd < dp[y].fi) 
            {
                dp[y].fi = nd;
                dp[y].se = nr;
                pq.push({nd,nr,y});
            }
            else if (nd == dp[y].fi && nr < dp[y].se)
            {
                dp[y].fi = nd;
                dp[y].se = nr;
                pq.push({nd,nr,y});
            }
        }
    }
    for (int i = 0;i < n;i++)
    {
        if (dp[i].fi == INT_MAX / 2) cout << -1 << " ";
        else cout << dp[i].fi << " ";
    }
    cout << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}