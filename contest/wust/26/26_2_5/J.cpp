#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vector g(n + 1,vector<int>());
    vt deg(n + 1);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    map<int,vt> a;
    for (int i = 1;i <= n;i++) 
    {
        a[deg[i]].push_back(i);
    }
    vt ans(n + 1),dis(n + 1,INT_MAX / 2);
    queue<int> q;
    auto bfs = [&](int mx,vt& f)
    {
        for (int u : f) 
        {
            if (dis[u] == INT_MAX / 2) ans[u] = -1;
            else ans[u] = dis[u];

            dis[u] = 0;
            q.push(u);
        }
        while (!q.empty())
        {
            auto x = q.front();
            q.pop();
            for (int y : g[x])
            {
                if (deg[y] >= mx) continue;

                if (dis[y] > dis[x] + 1)
                {
                    dis[y] = dis[x] + 1;
                    q.push(y);
                }
            }
        }
    };
    
    for (auto it = a.rbegin();it != a.rend();it++)
    {
        bfs(it->fi, it->se);
    }
    for (int i = 1;i <= n;i++) 
    {
        cout << ans[i] << " ";
    }
    cout << endl;
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