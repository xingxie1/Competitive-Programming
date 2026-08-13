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
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        g[b].push_back(a);
    }
    
    vector<set<int>> acc(n + 1);
    vector<int> vis(n + 1);
    queue<int> q;
    for (int i = 1;i <= n;i++)
    {
        if (!vis[i])
        {
            q.push(i);
            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                vis[x] = 1;
                for (int y : g[x])
                {
                    for (int v : acc[x])
                    {
                        acc[y].insert(v);
                    }
                    acc[y].insert(x);
                    acc[y].erase(y);
                    if (!vis[y])
                        q.push(y);
                }
            }
        }
    }
    // for (int i = 1;i <= n;i++)
    // {
    //     cout << i << " : " ;
    //     for (int y : acc[i]) cout << y << " ";
    //     cout << endl;
    // }
    int t;
    cin >> t;
    set<int> black;
    while (t--)
    {
        int op,v;
        cin >> op >> v;
        // cout << op << " " << v << endl;
        if (op == 1)
        {
            black.insert(v);
        }
        else 
        {
            int flag = 0;
            if (black.count(v))
            {
                flag = 1;
            }
            for (int y : acc[v])
            {
                if (black.count(y))
                {
                    flag = 1;
                    // break;
                }
                // cout << y << " ";
                // cout << endl;
            }
            if (flag) cout << "YES" << endl;
            else cout << "NO" << endl;
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