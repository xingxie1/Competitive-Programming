#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m, s;
    cin >> n >> m;
    vvpii g(n);
    for (int i = 0;i < m;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    cin >> s;
    vt key(s + 1);
    for (int i = 1;i <= s;i++) cin >> key[i];
    auto dij = [&](int st) 
    {
        pqueue<pii,vpii,greater<>> pq;
        pq.push({0,st});
        vt dis(n,INT_MAX / 2);
        dis[st] = 0;
        while (!pq.empty()) 
        {
            auto [d,x] = pq.top();
            pq.pop();
            if (d > dis[x]) continue;
            for (auto& [y,w] : g[x]) 
            {
                ll nd = d + w;
                if (nd >= dis[y]) continue;
                dis[y] = nd;
                pq.push({nd,y});
            }
        }
        return dis;
    };
    vvt dis(s + 1);
    for (int i = 0;i <= s;i++) 
    {
        dis[i] = dij(key[i]);
    }
    // for (int st : key) 
    // {
    //     for (int i = 0;i < n;i++) cout << dis[st][i] << " ";
    //     cout << endl;
    // }
    int N = (1 << s);
    vvt dp(N,vt(s + 1,INT_MAX / 2));
    dp[0][0] = 0;
    for (int i = 0;i < s;i++) 
    {
        dp[1 << i][i] = dis[0][key[i + 1]];
    }
    for (int mask = 0;mask < N;mask++) 
    {
        for (int i = 0;i < s;i++) 
        {
            if (!(mask >> i & 1)) continue;
            for (int j = 0;j < s;j++) 
            {
                if (mask >> j & 1) continue;
                int y = key[j + 1];
                dp[mask | 1 << j][j] = min(dp[mask | 1 << j][j],dp[mask][i] + dis[i + 1][y]);
            }
        }
    }
    int ans = INT_MAX;
    for (int i = 0;i < s;i++) 
    {
        ans = min(ans,dp[N - 1][i] + dis[0][key[i + 1]]);
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