#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

void solve()
{
    int n;
    cin >> n;
    vt a(n), c(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> c[i];
    long long ans = 0;
    vector dp(n,vector<int>(2));
    for (int i = 1;i < n ;i++)
    {
        if (a[i - 1] > a[i])
        {
            dp[i][1] = dp[i - 1][0] + c[i];
            dp[i][0] = dp[i - 1][1];
        }
        else 
        {
            dp[i][0] = dp[i][1] = min(dp[i - 1][0],dp[i - 1][1]);
        }
        
    }
    cout << min (dp[n - 1][0],dp[n - 1][1]) << endl;
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