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

const int MX = 200001;
ll F[MX]; // F[i] = i!
ll INV_F[MX]; // INV_F[i] = i!^-1 = qpow(i!, MOD-2)

ll qpow(ll a, int b) 
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

auto init = [] 
{
    F[0] = 1;
    for (int i = 1; i < MX; i++) 
    {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--) 
    {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
}();

// 从 n 个数中选 m 个数的方案数
ll comb(int n, int m) 
{
    return m < 0 || m > n ? 0 : F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}
vector g(MX + 1,vector<int>());

ll dfs(int u,int parent)
{
    ll sum = 0;
    int deg = g[u].size();

    for (int v : g[u])
    {
        if (v == parent) continue;
        sum += dfs(v, u);
        sum %= MOD;
    }
    if (deg == 0) return 1;
    ll res = (1 + 1LL * sum * qpow(deg, MOD - 2) % MOD) % MOD;
    return res;
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1;i < n;i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll ans = dfs(1, -1);
    cout << ans << endl;
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