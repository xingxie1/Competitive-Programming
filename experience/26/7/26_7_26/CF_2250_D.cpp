#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

const int MX = 1000005;
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
    vt a(n),c(n + 1);
    for (int i = 0;i < n - 1;i++) 
    {
        cin >> a[i];
        c[a[i]]++;
    }
    if (c[n] || !c[n - 1]) 
    {
        cout << 0 << endl;
        return ;
    }
    vt vis(n + 1);
    int i = 0;
    vis[a[0]] = 1;
    while (i < n - 2 && a[i] <= a[i + 1]) 
    {
        vis[a[i + 1]] = 1;
        i++;
    }

    for (int j = i;j < n - 2;j++)
    {
        if (a[j] < a[j + 1] || vis[a[j + 1]]) 
        {
            cout << 0 << endl;
            return ;
        }
    }
    ll ans = 2;
    int s = 0;
    for (int x = 1;x < n;x++)
    {
        if (c[x] > 0) 
        {
            int res = x - s - 1;
            int need = c[x] - 1;
            if (res < need)
            {
                cout << 0 << endl;
                return ;
            }
            for (int j = 0;j < need;j++) ans = ans * (res - j) % MOD;
            s += c[x];
        }
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}