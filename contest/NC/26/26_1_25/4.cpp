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
    vector g(n + 1,vector<int>());
    for (int i = 1;i < n;i++)
    {
        int x,y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> d(n + 1,1),vis(n + 1);
    queue<int> q;
    for (int i = 1;i <= n;i++)
    {
        if (g[i].size() == 1) q.emplace(i);
    }
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        vis[x]++;
        for (int y : g[x])
        {
            if (!vis[y])
            {
                d[y] += d[x];
                q.emplace(y);
            }
        }
    }
    int ans = 0;
    // for (int i = 1;i <= n;i++)
    // {
    //     cout << i << ": " << d[i] << endl;
    // }
    for (int i = 1;i <= n;i++)
    {
        int flag = 1;
        for (int y : g[i])
        {
            if ((d[i] == 1 && n % 2 == 1) || (d[y] > d[i] && (d[y] - d[i]) % 2 == 0) || (d[y] <= d[i] && d[y] % 2 == 0)) 
            {
                flag = 0;
                // cout << "y: " << y << "  dy: " << d[y] << endl;
                // cout << "i: " << i << "  di: " << d[i] << endl;
            }
        }
        if (flag) ans++;
    }
    cout << ans << endl;
    // cout << "************************************" << endl;

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