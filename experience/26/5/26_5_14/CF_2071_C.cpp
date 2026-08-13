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
    int n,st,ed;
    cin >> n >> st >> ed;
    st--;ed--;
    vvt g(n);
    for (int i = 1;i < n;i++) 
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vt dis(n,-1);
    dis[ed] = 0;
    auto dfs = [&](auto&& self,int u,int fa) -> void
    {
        for (int v : g[u]) 
        {
            if (v == fa) continue;
            dis[v] = dis[u] + 1;
            self(self,v,u);
        }
    };
    dfs(dfs,ed,-1);
    vt idx(n);
    ranges::iota(idx,0);
    ranges::sort(idx,{},[&](int x) {return -dis[x];});
    for (int x : idx) cout << x + 1 << " ";
    cout << endl;


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