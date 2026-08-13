#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector dp(n+1,vector<int>(2,0));
    for (int i = 0;i < n;i++)
    {
        dp[i+1][1] = max(dp[i][0] + a[i],dp[i][1]);
        dp[i+1][0] = max(dp[i][0],dp[i][1]);
    }
    cout << max(dp[n][0],dp[n][1]);
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