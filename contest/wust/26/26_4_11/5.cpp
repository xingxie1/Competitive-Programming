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
    int n,r,m;
    cin >> n >> r >> m;
    vvt g(n);
    r--;
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // for (int i = 0;i < n;i++) 
    // {
    //     cout << i << " : " ;
    //     for (int j : g[i]) cout << j << " ";
    //     cout << endl;
    // }
    vll ans(n);
    vll cnt(n,1);
    auto dfs = [&](auto&& self,int u,int fa) -> ll
    {
        if (u != r && g[u].size() == 1) 
        {
            cnt[u] = 1;
            return 1LL;
        }
        for (int v : g[u]) 
        {
            if (v != fa) 
            {
                cnt[u] += self(self,v,u);
            }
        }
        return cnt[u];
    };
    dfs(dfs,r,-1);
    // for (ll x : cnt) cout << x << " ";
    ans = cnt;
    auto dfs2 = [&](auto&& self,int u,int fa) -> void
    {
        if (u != r && g[u].size() == 1) return ;
        vt b;
        for (int v : g[u])
        {
            if (v != fa) b.push_back(cnt[v]);
        }
        ll sum = accumulate(b.begin(),b.end(),0LL) + 1;
        for (int i = 0;i < b.size();i++) 
        {
            ans[u] += 1LL * (sum - b[i]) * b[i];
        }
        for (int v : g[u])
        {
            if (v != fa) self(self,v,u);
        }
    };
    dfs2(dfs2,r,-1);
    // for (ll x : ans) cout << x << " ";
    for (int i = 0;i < m;i++)
    {
        int p;
        cin >> p;
        p--;
        cout << ans[p] << endl;
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