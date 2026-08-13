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


void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vll dp(3);
    ll ans = 0;
    for (char c : s) 
    {
        int x = c - '0';
        if (x % 2 == 0) 
        {
            x %= 3;
            ans = (ans + dp[(3 - x) % 3]) % MOD;
            if (x == 0) ans = (ans + 1) % MOD;
        }
        x %= 3;
        auto ndp = dp;
        ndp[x] += dp[0];
        ndp[(x + 1) % 3] += dp[1];
        ndp[(x + 2) % 3] += dp[2];
        ndp[x] ++;
        dp = ndp;
        dp[0] %= MOD;
        dp[1] %= MOD;
        dp[2] %= MOD;
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