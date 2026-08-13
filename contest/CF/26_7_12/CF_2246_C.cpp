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
//const int MOD = 998244353;
const int MOD = (int)1e9+7;

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
    int n;
    cin >> n;
    vt a(n);
    map<int,int> cnt;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 0;
    ll sum = 1;
    for (auto& [x,c] : cnt)
    {
        sum = sum * qpow(2,c - 1) % MOD;
    }
    ans = sum;
    // cout << ans << endl;
    if (cnt.count(-1)) 
    {
        sum = sum * qpow(qpow(2,cnt[-1] - 1),MOD - 2) % MOD;
        // cout << sum << endl;
        ll sss = qpow(2,cnt[-1] - 1);
        for (auto& [x,c] : cnt) 
        {
            if (cnt.count(x + 1)) 
            {
                ll qc1 = qpow(2,cnt[x] - 1),qc2 = qpow(2,cnt[x + 1] - 1);
                ll nsum = sum * qpow(qc1,MOD - 2) % MOD * qpow(qc2,MOD - 2) % MOD;
                // cout << nsum << endl;
                ll c1 = cnt[x] - 1,c2 = cnt[x + 1] - 1;
                // if (c1 > 0 && c2 > 0) nsum = nsum * qpow(2,c1 - 1) % MOD * qpow(2,c2 - 1) % MOD;
                nsum = nsum * qpow(2,cnt[x] - 1) % MOD * qpow(2,cnt[x + 1] - 1) % MOD;
                // cout << nsum << endl;
                nsum = nsum * sss % MOD;
                ans = (ans + nsum) % MOD;
                // cout << "x : " << x << "  nsum : " << nsum << endl;
                // cout << "ans : " << ans << endl;
            }
        }
    }
    cout << ans << endl;
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