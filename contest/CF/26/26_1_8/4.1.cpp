#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1,vector<int>());
    for (int i = 1;i < n;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> d(n + 1);
    auto bfs = [&]()
    {
        queue<pair<int,int>> q;
        vector<int> vis(n + 1);
        q.push({1,0});
        while (!q.empty())
        {
            auto [x,dd] = q.front();
            q.pop();
            d[x] = dd;
            vis[x] = 1;
            for (int y : g[x])
            {
                if (!vis[y])
                {
                    q.emplace(y,dd + 1);
                }
            }
        }
    };
    bfs();
    int mx = 0;
    map<int,int> cnt;
    for (int i = 1;i <= n;i++) 
    {
        cnt[d[i]]++;
    }
    for (auto [x,y] : cnt) mx = max(mx,y);
    int ans = mx;
    for (int i = 1;i <= n;i++)
    {
        if (g[i].size() - (i != 1) == cnt[d[i] + 1]) ans = max(ans,cnt[d[i] + 1] + 1);
    }
    
    cout << ans << endl;
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