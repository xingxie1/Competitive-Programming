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

ll comb(int m,int n)
{
    if (m < n) return 0;
    return 1LL * m * (m - 1) * (m - 2) / 6;
}
void solve()
{
    int n,m;
    cin >> n >> m;
    map<int,map<int,int>> g;
    for (int i = 0;i < m;i++) 
    {
        int u,v;
        cin >> u >> v;
        g[u][v]++;
        g[v][u]++;
    }
    for (int i = 1;i <= n;i++)
    {
        int cnt = n - 1 - g[i].size();
        cout << comb(cnt,3) << " ";
        // cout << cnt << " " << comb(cnt,3) << endl;
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