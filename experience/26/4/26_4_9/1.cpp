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
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vpii> g(n);
    for (int i = 0;i < m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        g[u].push_back({v,w});
    }
    long double ans = 0.0;
    auto dfs = [&](auto&& self,int u,ll k,int len)
    {
        if (u == n - 1) 
        {
            ans += 1.0 / k * len;
            return ;
        }
        for (auto [v,d] : g[u])
        {
            self(self,v,k * g[u].size(),d + len);
        }
    };
    dfs(dfs,0,1,0);
    
    
    cout << fixed << setprecision(2);
    // cout <<  round(ans) << endl;
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