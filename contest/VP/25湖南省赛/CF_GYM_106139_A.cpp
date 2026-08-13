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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

struct edge{
    ll u,v,w;
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<edge> e(m);
    for (int i = 0;i < m;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        e[i].u = u;
        e[i].v = v;
        e[i].w = w;
    }
    vll dp(n,LLONG_MAX / 2);
    vll ways(n),cnt(n);
    dp[0] = 0;
    ways[0] = 1;
    vll dis(n,LLONG_MAX / 2);
    for (int t = 0;t < n - 1;t++) 
    {
        vll ndp(n,LLONG_MAX / 2);
        vll nways(n);
        for (auto& [u,v,w] : e)
        {
            if (dp[u] != LLONG_MAX / 2)
            {
                ll nd = dp[u] + w;
                if (nd < ndp[v]) 
                {
                    ndp[v] = nd;
                    nways[v] = ways[u];
                }
                else if (nd == ndp[v]) 
                {
                    nways[v] += ways[u];
                    nways[v] %= MOD;
                }

            }
            if (dp[v] != LLONG_MAX / 2)
            {
                ll nd = dp[v] + w;
                if (nd < ndp[u]) 
                {
                    ndp[u] = nd;
                    nways[u] = ways[v];
                }
                else if (nd == ndp[u]) 
                {
                    nways[u] += ways[v];
                    nways[u] %= MOD;
                }

            }  
        }
        dp = ndp;
        ways = nways;
        cnt[t + 1] = ways[n - 1];
        dis[t + 1] = dp[n - 1];
    }
    ll ans = 0;
    for (int i = 1;i < n;i++) 
    {
        if (dis[i] == LLONG_MAX / 2) continue; 
        long double mn = 0,mx = 1e30;
        ll s = dis[i];
        for (int j = 1;j < i;j++) 
        {
            if (dis[j] == LLONG_MAX / 2) continue;
            ll s1 = dis[j];
            mx = min(mx,1.0l * (s1 - s) / (i - j));
        }
        for (int j = i + 1;j < n;j++) 
        {
            if (dis[j] == LLONG_MAX / 2) continue;
            ll s2 = dis[j];
            mn = max(mn,1.0l * (s - s2) / (j - i));
        }
        // cout << mn << " " << mx << endl;
        if (mn <= mx) ans += cnt[i];
        ans %= MOD;
    }
    cout << ans << endl;
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
