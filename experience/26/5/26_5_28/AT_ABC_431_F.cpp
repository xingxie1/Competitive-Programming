#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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

void solve()
{
    int n, d;
    cin >> n >> d;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ranges::sort(a);
    ll ans = 1;
    map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        auto j = ranges::lower_bound(a,a[i] - d) - a.begin();
        ans *= (i - j + 1);
        ans %= MOD;
        cnt[a[i]]++;
    }
    for (auto& [x,c] : cnt) 
    {
        ans *= INV_F[c];
        ans %= MOD;
    }
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