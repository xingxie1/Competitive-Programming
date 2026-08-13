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
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vector<string> a(n),b(n);
    vt c(n);
    for (int i = 0;i < n;i++) cin >> c[i];
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) 
    {
        string s = a[i];
        ranges::reverse(s);
        b[i] = s;
    }
    vvll dp(n + 1,vll(2,LLONG_MAX / 2));
    dp[0][0] = dp[0][1] = 0;
    dp[1][0] = 0;
    dp[1][1] = c[0];
    for (int i = 1;i < n;i++) 
    {   
        if (a[i] >= b[i - 1]) dp[i + 1][0] = min(dp[i + 1][0],dp[i][1]);
        if (a[i] >= a[i - 1]) dp[i + 1][0] = min(dp[i + 1][0],dp[i][0]);
        if (b[i] >= b[i - 1]) dp[i + 1][1] = min(dp[i + 1][1],dp[i][1] + c[i]);
        if (b[i] >= a[i - 1]) dp[i + 1][1] = min(dp[i + 1][1],dp[i][0] + c[i]);
    }
    ll ans = min(dp[n][0],dp[n][1]);
    if (ans >= LLONG_MAX / 2) cout << -1 << endl;
    else cout << ans << endl;
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