#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
// const int mod = 998244353;
// const int MOD = (int)1e9+7;

int MOD = 10007;
ll qpow(ll a, ll b,ll mod) 
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
void solve()
{
    ll k,m;
    cin >> k >> m;
    ll n_m = 0,n_p = 0;
    ll inv_9 = qpow(9,MOD - 2,MOD);
    for (int i = 0;i < k;i++) 
    {
        ll c,l;
        cin >> c >> l;
        ll p10p = qpow(10,l,MOD) % MOD;
        ll term_p = (p10p - 1 + MOD) % MOD;
        term_p = (term_p * inv_9) % MOD * c % MOD;
        n_p = (n_p * p10p % MOD + term_p) % MOD;
        ll p9 = 9 * m;
        ll p10_9m = qpow(10,l,p9);
        ll v = (p10_9m - 1 + p9) % p9;
        ll term_m = (v / 9) * c % m;
        n_m = (n_m * (p10_9m % m) % m + term_m) % m;
    }
    ll inv_m = qpow(m,MOD - 2,MOD);
    ll ans = (n_p - n_m % MOD + MOD) % MOD;
    ans = ans * inv_m % MOD;
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