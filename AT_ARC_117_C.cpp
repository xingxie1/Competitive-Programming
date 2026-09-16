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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

const int MOD = 3;
const int MX = 200001;
ll F[MX]; // F[i] = i!
ll INV_F[MX]; // INV_F[i] = i!^-1 = qpow(i!, MOD-2)

ll qpow(ll a, ll b) 
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

auto init = [](ll p)
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
};

// 从 n 个数中选 m 个数的方案数
ll comb(int n, int m) 
{
    return m < 0 || m > n ? 0 : F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}

//卡特兰数
ll Catalan(ll n)
{
    return (comb(2 * n, n) - comb(2 * n, n - 1) + MOD) % MOD;
}

// 广义卡特兰数
// 路径从 (0,0) 到 (m,n)
// 始终满足 y <= x + k
ll CatalanGeneral(ll n, ll m, ll k)
{
    if (n > m + k) return 0;

    return (comb(n + m, n) - comb(n + m, n - k - 1) + MOD) % MOD;
}

// Lucas 定理
ll C_lucas(ll n,ll  k)
{
    if (k < 0 || k > n) return 0;
    return F[n] * INV_F[k] % MOD * INV_F[n - k] % MOD;
}
ll lucas(ll n, ll k)
{
    if (k == 0) return 1;

    return C_lucas(n % MOD, k % MOD) * lucas(n / MOD, k / MOD) % MOD;
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char,int> p;
    p['B'] = 0;
    p['W'] = 1;
    p['R'] = 2;
    ll ans = 0;
    for (int i = 0;i < n;i++)
    {
        char c = s[i];
        ans += p[c] * lucas(n - 1,i);
        ans %= 3;
    }
    if ((n - 1) & 1) ans = (-ans + 3) % 3;
    if (ans == 0) cout << "B" << endl;
    else if (ans == 1) cout << "W" << endl;
    else cout << "R" << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}