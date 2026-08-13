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
// #define fi first
// #define se second
// #define umap unordered_map
// #define pqueue priority_queue
// #define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,K;
    cin >> n >> K;
    int x,y;
    cin >> x >> y;
    vvt a(n,vt(3));
    for (int i = 0;i < n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    int m = n - K;
    vvt d(m,vt(3));
    for (int i = K;i < n;i++)
    {
        d[i - K][0] = a[i][0];
        d[i - K][1] = a[i][1];
        d[i - K][2] = a[i][2];
    }
    ll ans = 1e16;
    // vvll dp(1005,vll(1005,1e16));
    ll dp[1005][1005];
    for (int i = 0;i <= x;i++) 
    {
        for (int j = 0;j <= y;j++) dp[i][j] = 1e16;
    }
    dp[0][0] = 0;
    for (int i = 0;i < m;i++)
    {
        for (int j = 0;j <= x;j++)
        {
            for (int k = 0;k <= y;k++)
            {
                if (j >= d[i][0]) 
                {
                    if (k >= d[i][1]) dp[j][k] = min(dp[j][k],dp[j - d[i][0]][k - d[i][1]] + d[i][2]);
                    else 
                    {
                        dp[j][k] = min(dp[j][k],dp[j - d[i][0]][0] + d[i][2]);
                    }
                }
                else 
                {
                    if (k < d[i][1]) dp[j][k] = min(dp[j][k],dp[0][0] + d[i][2]);
                    else dp[j][k] = min(dp[j][k],dp[0][k - d[i][1]] + d[i][2]);
                }
            }
        }
    }
    int mx = 1 << K;
    for (int b = 0;b <= mx;b++)
    {
        ll suma = 0,sumb = 0,sumc = 0;
        for (int i = 0;i < K;i++)
        {
            if (b >> i & 1) 
            {
                suma += a[i][0];
                sumb += a[i][1];
                sumc += a[i][2];
            }
        }
        int resa = x - suma,resb = y - sumb;
        if (resa <= 0 && resb <= 0) 
        {
            ans = min(ans,sumc);
            continue;
        }
        resa = max(resa,0);
        resb = max(resb,0);
        ans = min(ans,dp[resa][resb] + sumc);
    }
    if (ans == 1e16) 
    {
        cout << -1 << endl;
        return ;
    }
    cout << ans << endl;
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