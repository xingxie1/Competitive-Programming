#include<bits/stdc++.h>
using namespace std;
using vt = vector<int>;
using vll = vector<long long>;

int mod = (int)1e9+7;
void solve()
{
    int n;
    cin >> n;
    vt a(n),b(n),ans(495);
    for (int i = 0;i < n;i++) cin >> a[i],a[i] %= 495;
    for (int i = 0;i < n;i++) cin >> b[i],b[i] %= 495;
    vector dp(n + 1,vector<vector<int>> (n + 1,vector<int>(495,0)));
    dp[0][0][0] = 1;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;i < n;j++)
        {
            for (int k = 0;k < 495;k++)
            {
                if (a[j] <= k)
                    dp[i+1][j+1][k] = dp[i+1][j][k - a[j]];
            }
        }
    }
    vector dp2 (n + 1,vector<vector<int>> (n + 1,vector<int>(495,0)));
    dp2[0][0][0] = 1;
    for (int i = 0;i <= n;i++)
    {
        for (int j = 0;i <= n;j++)
        {
            for (int k = 0;k < 495;k++)
            {
                if (b[j] <= k)
                    dp2[i+1][j+1][k] = dp2[i+1][j][k-b[j]];
            }
        }
    }
    for (int i = 0;i <= n;i++)
    {
        for (int j = 0;j <= i;j++)
        {
            for (int k = 0;k < 495;k++)
            {
                for (int l = 0;l < 495;l++)
                {
                    int x = k + l;
                    x %= 495;
                    ans[x] += 1LL * (dp[n][i][k] * dp2[n][j][l]) % mod;
                    ans[x] %= mod;
                }
            }
        }
    }
    for (int i = 0;i < 495;i++)
    {
        cout << ans[i] << " ";
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