#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n,m,s;
    cin >> n >> m >> s;
    vvt g(n + 1,vt());
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    vt vis(n + 1);
    stack<int> st;
    auto dfs1 = [&](this auto&& self,int u) ->void
    {
        vis[u] = 1;
        for (int v : g[u])
        {
            if (!vis[v]) self(v);
        }
        st.push(u);
    };
    for (int i = 1;i <= n;i++)
    {
        if (!vis[i]) dfs1(i);
    }
    for (int& x : vis) x = 0;
    auto dfs2 = [&](this auto&& self,int u) ->void
    {
        vis[u] = 1;
        for (int v : g[u]) 
        {
            if (!vis[v]) self(v);
        }
    };
    dfs2(s);
    int ans = 0;
    while (!st.empty())
    {
        int u = st.top();
        if (!vis[u]) 
        {
            ans++;
            dfs2(u);
        }
        st.pop();
    }
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