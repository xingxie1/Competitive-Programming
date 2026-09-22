#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define fi first
#define se second
using vt = vector<int>;
using vvt = vector<vector<int>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vvpii = vector<vector<pii>>;
using vvpll = vector<vector<pll>>;
using vll = vector<ll>;

const int MOD = 998244353;

ll qpow(ll a,ll b) 
{
    ll res = 1;
    while (b) 
    {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void solve()
{
    int n,m,ed;
    cin >> n >> m >> ed;
    string s;
    cin >> s;
    ed--;
    vvpii g(n),f(n);
    priority_queue<pll,vpll,greater<>> pq;
    vt deg(n);
    for (int i = 0;i < m;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back({v,w});
        f[v].push_back({u,w});
        deg[u]++;
    }
    vll dis(n,LLONG_MAX / 2);
    dis[ed] = 0;
    pq.push({0,ed});
    while (!pq.empty())
    {
        auto [d,x] = pq.top();
        pq.pop();
        if (d > dis[x]) continue;
        for (auto& [y,w] : f[x])
        {
            ll nd = d + w;
            if (nd < dis[y])
            {
                dis[y] = nd;
                pq.push({nd,y});
            }
        }
    }
    vt cnt(n);
    auto ddeg = deg;
    cnt[ed] = 1;
    queue<int> q;
    q.push(ed);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto& [y,w] : f[x])
        {
            if (dis[x] == dis[y] - w) 
            {
                cnt[y] += cnt[x];
                cnt[y] %= MOD;
            }
            ddeg[y]--;
            if (!ddeg[y]) q.push(y);
        }
    }
    // for (int x : cnt) cout << x << " ";
    // cout << endl;
    q.push(ed);
    vll dp(n);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (auto& [y,w] : f[x])
        {
            if (s[y] == '1') 
            {
                if (dis[y] == dis[x] + w)
                {
                    ll val = cnt[x] * qpow(cnt[y],MOD - 2) % MOD;
                    val = val * (dp[x] + w) % MOD;
                    dp[y] = (dp[y] + val) % MOD;
                }
            }
            else 
            {
                dp[y] = (dp[y] + qpow(g[y].size(),MOD - 2) * (dp[x] + w) % MOD) % MOD;
            }
            deg[y]--;
            if (!deg[y]) 
            {
                q.push(y);
            }
        }
    }
    for (int x : dp) cout << x << " ";
    cout << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();

    return 0;
}