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
    vvt g(n);
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int fa = -1;
    for (int i = 0;i < n;i++) 
    {
        if (g[i].size() == 1) fa = i;
    }
    auto dfs = [&](auto&& self,int u,int fa) -> pii
    {
        pii ans = {0,0};
        for (int v : g[u])
        {
            if (v == fa) continue;
            auto [l,nl] = self(self,v,u);
            ans.fi += nl;
            ans.se += max(l,nl);
        }
        ans.fi += a[u];
        return ans;
    };
    auto ans = dfs(dfs,fa,-1);
    // for (int x : a) cout << x << " ";
    cout << max(ans.fi,ans.se) << endl;
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