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
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vvt g(n + 1);
    vt ans(n),deg(n + 1);
    for (int i = 1;i < n;i++)
    {
        int u,v,x,y;
        cin >> u >> v >> x >> y;
        if (x > y) 
        {
            g[u].push_back(v);
            deg[v]++;
        }
        else 
        {
            g[v].push_back(u);
            deg[u]++;
        }
    }
    int mx = n;
    queue<int> q;
    for (int i = 1;i <= n;i++)
    {
        if (deg[i] == 0) q.push(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ans[x - 1] = mx--;
        for (int y : g[x])
        {
            deg[y]--;
            if (deg[y] == 0) q.push(y);
        }
    }
    for (int x : ans) cout << x << " ";
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