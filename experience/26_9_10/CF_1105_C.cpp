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
const int MOD = (int)1e9+7;

void solve()
{
    int n,l,r;
    cin >> n >> l >> r;
    ll c0 = r / 3 - (l - 1) / 3;
    ll c1 = (r + 2) / 3 - (l + 1) / 3;
    ll c2 = (r + 1) / 3 - l / 3;
    vll dp(3);
    dp[0] = 1;
    for (int i = 0;i < n;i++)
    {
        vll ndp = dp;
        ndp[0] = (dp[0] * c0 % MOD + dp[1] * c2 % MOD + dp[2] * c1 % MOD) % MOD;
        ndp[1] = (dp[0] * c1 % MOD + dp[1] * c0 % MOD + dp[2] * c2 % MOD) % MOD;
        ndp[2] = (dp[0] * c2 % MOD + dp[1] * c1 % MOD + dp[2] * c0 % MOD) % MOD;
        dp = ndp;
    }
    cout << dp[0] << endl;
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