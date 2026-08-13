#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n, k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector<vector<vector<int>>> dp(n + 1,vector<vector<int>>(k + 2,vector<int>(2, INT_MIN / 2)));
    for (int i = 0;i <= k + 1;i++) dp[0][i][0] = 0;

    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j <= k;j++)
        {
            dp[i + 1][j + 1][0] = max(dp[i][j][1] + a[i],dp[i][j + 1][0]);
            dp[i + 1][j + 1][1] = max(dp[i][j + 1][1],dp[i][j + 1][0] - a[i]);
        }
    }
    int ans = dp[n][k + 1][0];
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