#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vvt = vector<vt>;
using vll = vector<ll>;
using pii = pair<int,int>;

void solve()
{
    int n,m;
    cin >> n >> m;
    vt a(n + 1,-1);
    vvt g(n + 1);
    vt deg(n + 1);
    while (m--)
    {
        int l,r;
        cin >> l >> r;
        int last = 0;
        for (int i = 0;i < r - l + 1;i++)
        {
            int j;
            cin >> j;
            if (last) 
            {
                g[last].push_back(j);
                deg[j]++;
            }
            last = j;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        if (!g[i].size()) continue;
        sort(g[i].begin(),g[i].end());
    }
    int cur = 1;
    vt vis(n + 1);
    for (int i = 1;i <= n;i++)
    {
        if (deg[i] || vis[i]) continue;
        priority_queue<int,vt,greater<>> q;
        q.push(i);
        vis[i] = 1;
        while (!q.empty())
        {
            int x = q.top();
            q.pop();
            if (a[x] != -1)
            {
                cout << -1 << endl;
                return ;
            }
            a[x] = cur++;
            // cout << x << endl;
            for (int y : g[x])
            {
                deg[y]--;
                if (!deg[y]) 
                {
                    if (vis[y]) continue;
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
    for (int x : deg) 
    {
        if (x) 
        {
            cout << -1 << endl;
            return ;
        }
    }
    for (int i = 1;i <= n;i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();
}