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
    ll n,k;
    cin >> n >> k;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvvll dp(n + 1,vvll(2,vll(2,3000000000000000053)));//i 当前,之前
    dp[0][0][0] = 0;
    for (int i = 0;i < n;i++) 
    {
        dp[i + 1][0][0] = gcd(dp[i][0][0],a[i]);
        dp[i + 1][1][0] = gcd(dp[i][0][0],a[i] + k);
        dp[i + 1][0][1] = max({gcd(dp[i][0][1],a[i]),gcd(dp[i][1][1],a[i]),gcd(dp[i][1][0],a[i])});
        dp[i + 1][1][1] = max(gcd(dp[i][1][1],a[i] + k),gcd(dp[i][1][0],a[i] + k));
    }
    cout << max({dp[n][0][0],dp[n][0][1],dp[n][1][0],dp[n][1][1]}) << endl;
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