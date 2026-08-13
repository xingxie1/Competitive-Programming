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
    vt a(n),b(n),c(n);
    for (int i = 0;i < n;i++) cin >> a[i] >> b[i] >> c[i];
    vvt dp(n + 1,vt(3));
    for (int i = 0;i < n;i++) 
    {
        dp[i + 1][0] = max(dp[i][1],dp[i][2]) + a[i];
        dp[i + 1][1] = max(dp[i][0],dp[i][2]) + b[i];
        dp[i + 1][2] = max(dp[i][1],dp[i][0]) + c[i];
    }
    cout << ranges::max(dp[n]) << endl;
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