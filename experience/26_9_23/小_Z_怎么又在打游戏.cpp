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

const int MX = 101;
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

ll comb(int n, int m)
{
    ll fz = 1;
    for (int i = 0;i < m;i++)
    {
        fz = fz * (n - i) % MOD;
    }
    return fz * INV_F[m] % MOD;
}

void solve()
{
    int n;
    cin >> n;
    vt l(n),h(n),op(n);
    for (int i = 0;i < n;i++) cin >> l[i] >> h[i] >> op[i];
    vll dp(101);
    for (int j = 1;j <= h[0];j++) dp[j] = 1;
    for (int i = 0;i < n;i++)
    {
        vll C(101),ndp(101);
        for (int d = 0; d <= 100; d++)
        {
            C[d] = comb(l[i] - 1 + d,d);
        }
        if (op[i] == 0)
        {
            for (int j = h[i];j >= 1;j--)
            {
                for (int j2 = h[i];j2 >= j;j2--)
                {
                    ll x = C[j2 - j] * dp[j2] % MOD;
                    ndp[j] = (ndp[j] + x) % MOD;
                }
            }
        }
        else 
        {
            for (int j = 1;j <= h[i];j++)
            {
                for (int j2 = 1;j2 <= j;j2++)
                {
                    ll x = C[j - j2] * dp[j2] % MOD;
                    ndp[j] = (ndp[j] + x) % MOD;
                }
            }
        }
        dp = ndp;
    }
    ll ans = 0;
    for (int j = 1;j <= h[n - 1];j++) ans = (ans + dp[j]) % MOD;
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
