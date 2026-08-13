#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

const int MX = 2000001;
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

void solve()
{
    int n;
    cin >> n;
    vvt g(n);
    for (int i = 1;i < n;i++) 
    {
        int u;
        cin >> u;
        u--;
        g[i].push_back(u);
        g[u].push_back(i);
    }
    vt c(n),d(n);
    for (int i = 0;i < n;i++) cin >> c[i];
    for (int i = 0;i < n;i++) cin >> d[i];
    vll sum(n),sumd(n);
    auto dfs1 = [&](auto&& self,int u,int fa) -> ll 
    {
        sum[u] += c[u];
        for (int v : g[u]) 
        {
            if (v == fa) continue;
            sum[u] += self(self,v,u);
        }
        return sum[u];
    };
    dfs1(dfs1,0,-1);
    auto dfs2 = [&](auto&& self,int u,int fa) -> ll 
    {
        sumd[u] += d[u];
        for (int v : g[u]) 
        {
            if (v == fa) continue;
            sumd[u] += self(self,v,u);
        }
        return sumd[u];
    };
    dfs2(dfs2,0,-1);
    auto dfs3 = [&](auto&& self,int u,int fa) -> ll
    {
        ll s = 1;
        for (int v : g[u]) 
        {
            if (v == fa) continue;
            s = s * self(self,v,u) % MOD;
        }
        s %= MOD;
        for (ll i = sum[u] - sumd[u] + d[u];i >= sum[u] - sumd[u] + 1;i--) 
        {
            if (i < 0) 
            {
                s = 0;
                break;
            }
            s = s * (i % MOD) % MOD;
        }
        s = s * INV_F[d[u]] % MOD;
        return s;
    };
    ll ans = dfs3(dfs3,0,-1);
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