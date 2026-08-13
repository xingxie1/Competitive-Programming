#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector<vector<int>> dp(n + 1,vector<int>(2));
    dp[0][0] = a[0];
    dp[1][1] = a[1];
    for (int i = 2;i < n;i++)
    {
        dp[i][0] = dp[i - 1][1] + a[i];
        dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + a[i];
    }
    cout << max(dp[n - 1][0],dp[n - 1][1]);
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