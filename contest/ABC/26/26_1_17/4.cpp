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
    int n,m,l,s,t;
    cin >> n >> m >> l >> s >> t;
    vector<vector<pair<int,int>>> g(n + 1,vector<pair<int,int>>());
    for (int i = 0;i < m;i++)
    {
        int u,v,c;
        cin >> u >> v >> c;
        pair<int,int> tmp = {v,c};
        g[u].push_back(tmp);
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