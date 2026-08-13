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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;
int MOD;

ll qpow(ll a,ll b)
{
    ll r = 1;
    while (b)
    {
        if (b & 1) r = a * r % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return r % MOD;
}
void solve()
{
    ll a,b,c,d;
    cin >> a >> b >> c >> d >> MOD;
    a %= MOD;
    b %= MOD;
    c = c * d;
    ll ans = qpow(a,c) * qpow(b,c) % MOD;
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