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

void solve()
{
    int n;
    cin >> n;
    vt h(n),f(n);
    for (int i = 0;i < n;i++) cin >> h[i];
    for (int i = 1;i < n;i++) cin >> f[i],f[i]--;
    vvpll g(n);
    for (int i = 1;i < n;i++) 
    {
        ll w;
        cin >> w;
        g[f[i]].push_back({i,w});
    }
    ll sum = 0;
    vll ans(n);
    auto dfs = [&](auto&& self, int u) -> void
    {
        ranges::sort(g[u],{},[&](auto& f){
            return f.se;
        });
        ll last = 0;
        for (auto& [v,w] : g[u]) 
        {
            sum += w - last;
            last = w;
            self(self,v);
        }
        sum += h[u] - last;
        ans[u] = sum;
    };
    dfs(dfs,0);
    for (ll x : ans) cout << x << " "; 
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