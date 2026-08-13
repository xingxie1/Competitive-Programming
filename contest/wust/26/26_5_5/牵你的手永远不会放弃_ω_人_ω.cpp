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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    vvll dp(n + 1,vll(2));
    dp[0][1] = dp[1][1] = LLONG_MIN / 2;
    for (int i = 0;i < n;i++) 
    {
        ll mx1 = LLONG_MIN / 2,mx2 = LLONG_MIN / 2;
        if (dp[i][1] >= k) mx1 = dp[i][1] - k;
        if (dp[i][0] >= k) mx2 = dp[i][0] - k;
        dp[i + 1][0] = max(dp[i][0],mx1) + a[i];
        dp[i + 1][1] = max(dp[i][1],mx2) + b[i];
        // cout << dp[i + 1][0] << " " << dp[i + 1][1] << endl;
    }
    cout << max(dp[n][0],dp[n][1]) << endl;
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