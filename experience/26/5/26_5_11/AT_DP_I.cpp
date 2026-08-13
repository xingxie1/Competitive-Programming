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
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector dp(n + 1,vector<double>(n + 1));
    dp[0][0] = 1.0;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j <= i;j++) 
        {
            dp[i + 1][j + 1] += dp[i][j] * a[i]; 
            dp[i + 1][j]     += dp[i][j] * (1 - a[i]);
        }
    }
    double ans = 0.0;
    for (int j = n;j > n / 2;j--) 
    {
        ans += dp[n][j];
    }
    cout << fixed << setprecision(10);
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