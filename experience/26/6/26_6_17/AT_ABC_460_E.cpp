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


void solve()
{
    ll N,M;
    cin >> N >> M;
    i128 n = N;
    ll ans = 0;
    ll pow10_mod = 1;
    vector<i128> p10(20);
    p10[0] = 1;
    for (int i = 1; i <= 19; i++) {
        p10[i] = p10[i - 1] * 10;
    }
    auto mod128 = [&](i128 x) -> ll
    {
        return (ll)(x % MOD);
    };
    for (int d = 1;d <= 19;d++) 
    {
        pow10_mod = (i128)pow10_mod * 10 % M;
        i128 L = p10[d - 1];
        i128 R = min(n,p10[d] - 1);
        if (L > R ) continue;
        i128 cnty = R - L + 1;
        ll A =(pow10_mod - 1 + M) % M;
        ll g = gcd(M,A);
        ll cntx = N / (M / g);
        ans = (ans + mod128(cnty) * (cntx % MOD)) % MOD;
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