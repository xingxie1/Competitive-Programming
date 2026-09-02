#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using i128 = __int128_t;

void solve()
{
    int m,n,k,s;
    cin >> m >> n >> k >> s;
    n += m;
    vector<long double> a(n);
    vector<long double> pre(n + 1),pre2(n + 1);
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
    }
    ranges::sort(a);
    for (int i = 0;i < n;i++) 
    {
        pre[i + 1] = pre[i] + a[i];
        pre2[i + 1] = pre2[i] + a[i] * a[i];
    }
    vector dp(n + 1,vector<long double>(k + 1,1e100));
    dp[0][0] = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < i;j++)
        {
            int cnt = i - j + 1;
            long double sx = pre[i + 1] - pre[j];
            long double sx2 = pre2[i + 1] - pre2[j];
            long double xx = sx / cnt;
            for (int c = 0;c < k;c++)
            {
                dp[i + 1][c + 1] = min(dp[i + 1][c + 1],dp[j][c] + sx2 + cnt * xx * xx - 2 * xx * sx);
            }
        }
    }
    cout << fixed << setprecision(15);
    cout << dp[n][k] + (s / 2.0) * (s / 2.0) * n << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}