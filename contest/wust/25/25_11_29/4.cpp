#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

pair<int,int> bfs(vector<vector<int>>& g,int x)
{
    int n = g.size();
    vector<int> vis(n);
    queue<pair<int,int>> q;
    q.emplace(x,0);
    int mxd = 0,ret = 0;
    while (!q.empty())
    {
        auto [x,d] = q.front();
        q.pop();
        vis[x] = 1;
        if (d > mxd)
        {
            mxd = d;
            ret = x;
        }
        for (int y : g[x])
        {
            if (!vis[y])
            {
                q.emplace(y,d + 1);
            }
        }
    }
    return {ret,mxd};
}
void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 1;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    auto t1 = bfs(g,1);
    int A = t1.fi;
    auto t2 = bfs(g,A);

    int ans = t2.se;

    cout << ans;
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