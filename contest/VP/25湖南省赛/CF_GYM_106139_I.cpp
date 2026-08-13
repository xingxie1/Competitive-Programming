#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
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
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
const int MOD = 998244353;
//const int MOD = (int)1e9+7;


const int MX = 1001005;
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
    int n,m,a,b,c,d;
    cin >> n >> m >> a >> b >> c >> d;
    if (b > d) swap(b,d);
    if (a > c) swap(a,c);
    ll sum = comb(n + m,n);
    ll cnt = 0;
    for (int x = 0;x <= a;x++)
    {
        cnt += comb(x + d - 1,x) * comb(n + m - x - d,n - x) % MOD;
        cnt %= MOD;
    }
    ll cnt2 = 0;
    for (int x = 0;x <= c - 1;x++) 
    {
        cnt2 += comb(x + b,x) * comb(n - x + m - b - 1,n - x) % MOD;
        cnt2 %= MOD;
    }
    cnt += sum - cnt2;
    cnt += MOD;
    cout << cnt * qpow(sum,MOD - 2) % MOD << endl;
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