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
    string s;
    cin >> s;
    int n = s.size();
    vll dp(3);
    ll ans = 0;

    for (int i = 0;i < n;i++) 
    {
        auto ndp = dp;
        if (s[i] == 'a') 
        {
            ans += dp[1] + dp[2] + 1;
            ndp[0] += dp[1] + dp[2] + 1;
        }
        else if (s[i] == 'b') 
        {
            ans += dp[0] + dp[2] + 1;
            ndp[1] += dp[0] + dp[2] + 1;
        }
        else 
        {
            ans += dp[0] + dp[1] + 1;
            ndp[2] += dp[1] + dp[0] + 1;
        }
        ans %= MOD;
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