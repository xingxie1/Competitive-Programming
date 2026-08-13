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
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vvt g(n + 1,vt());
    g[0].push_back(1);
    for (int i = 1;i <= n;i++)
    {
        int l,r;
        cin >> l >> r;
        if (l == 0 && r == 0) continue;
        g[i].push_back(l);
        g[i].push_back(r);
    }
    vt sz(n + 1);
    auto dfs = [&](this auto&& self,int i)
    {
        if (g[i].size() == 0) 
        {
            sz[i] = 1;
            return 1;
        }
        sz[i] = 1 + self(g[i][0]) + self(g[i][1]);
        return sz[i];
    };
    dfs(1);
    sz[0] = sz[1] + 1;
    // for (int x : sz) cout << x << " ";
    // cout << endl;
    vll ans(n + 1);
    auto dfs2 = [&](this auto&& self,int i,int fa)
    {
        if (g[i].size() == 0)
        {
            ans[i] = 1 + ans[fa];
            ans[i] %= MOD;
            return ;
        }
        else 
        {
            ans[i] = 2 * (sz[i] - 1) + 1 + ans[fa];
            ans[i] %= MOD;
            self(g[i][0],i);
            self(g[i][1],i);
        }
    };
    dfs2(1,0);
    for (int i = 1;i <= n;i++) cout << ans[i] << " ";
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