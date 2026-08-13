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
    int n,m;
    cin >> n >> m;
    vt a(n);
    for (int i = 1;i <= n;i++) cin >> a[i];
    vector<vector<int>> g(n + 1,vector<int>());
    for (int i = 0;i < m;i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    int ans = m;
    
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