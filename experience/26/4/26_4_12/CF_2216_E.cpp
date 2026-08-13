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
// #define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve1()
{
    int n,s;
    cin >> n >> s;
    vt b(n);
    s--;
    for (int i = 0;i < n;i++) 
    {
        if (s >> i & 1) b[i] = 1;
    }
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        int mn = min(u,v);
        int mx = max(u,v);
        u--,v--;
        if (b[u] == b[v]) cout << mx << " " << mn << endl;
        else cout << mn << " " << mx << endl;
    }
}
void solve2()
{
    int n;
    cin >> n;
    vector<vpii> g(n + 1);
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back({v,u > v});
        g[v].push_back({u,u > v});
    }
    int ans = 0;
    vt b(n + 1);
    auto dfs = [&](auto&& self,int u,int fa) -> void
    {
        for (auto[v,op] : g[u])
        {
            if (v != fa)
            {
                if (op == 1) b[v] = b[u];
                else b[v] = b[u] ^ 1;
                self(self,v,u);
            }
        }
    };
    dfs(dfs,n,-1);
    for (int i = 1;i <= n;i++)
    {
        if (b[i]) ans += (1 << (i - 1));
        // cout << b[i] << " ";
    }
    cout << ans + 1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1,q;
    cin >> _ >> q;
    if (q == 1) while (_--) solve1();
    else while (_--) solve2();

    return 0;
}