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
//const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vvt g(n);
    for (int i = 1;i < n;i++) 
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto check = [&](int x)
    {
        vt cnt(n,1);
        int ans = 0;
        auto dfs = [&](auto&& self,int u,int fa) -> void
        {
            for (int v : g[u])
            {
                if (v != fa)
                {
                    self(self,v,u);
                    if (cnt[v] >= x) ans++;
                    else cnt[u] += cnt[v];
                }
            }
        };
        dfs(dfs,0,-1);
        if (ans > k) return 1;
        if (ans == k && cnt[0] >= x) return 1;
        return 0;
    };
    int l = 0,r = n + 1;
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        if (check(m)) l = m;
        else r = m;
    }
    cout << l << endl;
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