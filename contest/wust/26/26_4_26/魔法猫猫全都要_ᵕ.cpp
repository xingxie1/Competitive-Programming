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
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvll dp(n + 1,vll(k + 1,LLONG_MIN / 2));
    dp[0][0] = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = k;j >= 1;j--)
        {
            ll mx = LLONG_MIN / 2;
            for (int d = 0;d <= 5;d++)
            {
                if (i - d < 0) break;
                mx = max(mx,dp[i - d][j - 1]);
            }
            dp[i + 1][j] = mx + a[i];
        }
    }
    ll ans = LONG_MIN;
    for (int i = 0;i <= n;i++) 
    {
        ans = max(ans,dp[i][k]);
        // cout << dp[i][k] << endl;
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