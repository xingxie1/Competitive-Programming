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
    int n,q;
    cin >> n >> q;
    vvt g(n);
    for (int u = 1;u < n;u++)
    {
        int v;
        cin >> v;
        v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vt b = {1};
    vt sz(n,1);
    auto dfs = [&](auto&& self,int u,int fa) -> void
    {
        for (int v : g[u]) 
        {
            if (v == fa) continue;
            b.push_back(v + 1);
            self(self,v,u);
            sz[u] += sz[v];
        }
    };
    dfs(dfs,0,-1);
    // for (int x : b) cout << x << " ";
    // cout << endl;
    // for (int i = 0;i < n;i++)
    // {
    //     cout << i + 1 << " " << sz[i] << endl;
    // }
    vt p(n + 1);
    for (int i = 0;i < n;i++) p[b[i]] = i;
    while (q--)
    {
        int u,k;
        cin >> u >> k;
        u--;
        int i = p[u + 1];
        if (k > sz[u] || i + k - 1 >= n) cout << -1 << endl;
        else cout << b[i + k - 1] << endl;
    }
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