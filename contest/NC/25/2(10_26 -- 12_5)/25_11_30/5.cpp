#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

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
    vector<int> vis(n + 1);
    vector<pair<int,int>> dist;
    queue<pair<int,int>> q;
    q.emplace(1,0);
    while (!q.empty())
    {
        auto [x,d] = q.front();
        dist.push_back({x,d});
        vis[x] = 1;
        q.pop();
        for (int y : g[x])
        {
            if (!vis[y])
            {
                q.emplace(y,d + 1);
            }
        }
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