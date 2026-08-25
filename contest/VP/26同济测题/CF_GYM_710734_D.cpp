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
//计算Cnm % mod p
//p必须为质数
using i128 = __int128_t;

ll MOD;
vector<ll> fac, ifac;

// 快速幂
ll qpow(ll a, ll b)
{
    ll res = 1;

    while(b)
    {
        if(b & 1)
        {
            res = (i128)res * a % MOD;
        }

        a = (i128)a * a % MOD;
        b >>= 1;
    }

    return res;
}

// 预处理 0! 到 (p - 1)!
void init(ll p)
{

    fac.resize(p);
    ifac.resize(p);

    fac[0] = 1;

    for(int i = 1; i < p; i++)
    {
        fac[i] = (i128)fac[i - 1] * i % MOD;
    }

    // 费马小定理求逆元
    ifac[p - 1] = qpow(fac[p - 1], MOD - 2);

    for(int i = p - 1; i >= 1; i--)
    {
        ifac[i - 1] = (i128)ifac[i] * i % MOD;
    }
}

// 计算 C(n,m)，这里保证 n,m < p
ll C(ll n, ll m)
{
    if(m < 0 || m > n)
    {
        return 0;
    }

    return (i128)fac[n] * ifac[m] % MOD * ifac[n - m] % MOD;
}

// Lucas 定理
ll Lucas(ll n, ll m)
{
    if(m == 0)
    {
        return 1;
    }

    ll now = C(n % MOD, m % MOD);

    return (i128)now * Lucas(n / MOD, m / MOD) % MOD;
}

const int MX = 1000005;
ll F[MX]; // F[i] = i!
ll INV_F[MX]; // INV_F[i] = i!^-1 = qpow(i!, MOD-2)

auto INIT = [](int x) 
{
    F[0] = 1;
    for (int i = 1; i < MX; i++) 
    {
        F[i] = (i128)F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--) 
    {
        INV_F[i - 1] = (i128)INV_F[i] * i % MOD;
    }
    return 0;
};

// 从 n 个数中选 m 个数的方案数
ll comb(int n, int m) 
{
    return m < 0 || m > n ? 0 : (i128)F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}

void solve()
{
    ll a,b;
    cin >> a >> b >> MOD;
    if (MOD <= 1e6) 
    {
        // cout << "@@@" << endl;
        init(MOD);
        cout << Lucas(a - 1,b - 1) << endl;
    }
    else 
    {
        if (a < b) 
        {
            cout << 0 << endl;
            return ;
        }
        else if (a == b) 
        {
            cout << 1 << endl;
            return ;
        }
        if (a <= 1e6)
        {
            INIT(1);
            // cout << "!!!" << endl;
            cout << comb(a - 1,b - 1) % MOD;
            return ;
        }
        ll s1 = 1,s2 = 1;
        for (int i = 1;i <= b - 1;i++)
        {
            s1 = (i128)s1 * (a - i) % MOD;
            s2 = (i128)s2 * i % MOD;
        }
        ll ans = (i128)s1 * qpow(s2,MOD - 2) % MOD;
        cout << ans << endl;
    }
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