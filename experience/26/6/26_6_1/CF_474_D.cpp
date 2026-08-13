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
//const int MOD = 998244353;
const int MOD = (int)1e9+7;

void solve()
{
    int t,k;
    cin >> t >> k;
    int n = 1e5;
    vll dp(n + 1);
    vll pre(n + 1);
    dp[0] = 1;
    for (int i = 1;i <= n;i++) 
    {
        dp[i] = dp[i - 1];
        if (i >= k) dp[i] += dp[i - k];
        dp[i] %= MOD;
        pre[i] = (pre[i - 1] + dp[i]) % MOD;
    }
    while (t--) 
    {
        int a,b;
        cin >> a >> b;
        cout << (pre[b] - pre[a - 1] + MOD) % MOD << endl;
    }
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