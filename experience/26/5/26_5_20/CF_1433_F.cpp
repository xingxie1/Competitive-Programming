#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
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
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vvt a(n,vt(m));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) cin >> a[i][j];
    }
    vvt b(n,vt(k,INT_MIN / 2));
    for (int i = 0;i < n;i++) 
    {
        vvt dp(m / 2 + 1,vt(k,INT_MIN / 2));
        dp[0][0] = 0;
        for (int x : a[i]) 
        {
            vvt ndp = dp;
            for (int s = 0;s < k;s++)
            {
                for (int l = 0;l < m / 2;l++)
                {
                    if (dp[l][s] < 0) continue;
                    ndp[l + 1][(s + x) % k] = max(ndp[l + 1][(s + x) % k], dp[l][s] + x);
                }
            }
            for (int l = 0;l < m / 2;l++)
            {
                for (int s = 0;s < k;s++)
                {
                    if (dp[l][s] < 0) continue;
                    ndp[l + 1][(s + x) % k] = max(ndp[l + 1][(s + x) % k], dp[l][s] + x);
                }
            }
            dp = ndp;
        }
        for (int j = 0;j <= m / 2;j++) 
        {
            for (int s = 0;s < k;s++) b[i][s] = max(b[i][s],dp[j][s]);
        }
    }
    vt dp(k,INT_MIN / 2);
    dp[0] = 0;
    for (int i = 0;i < n;i++) 
    {
        vt ndp(k,INT_MIN / 2);
        for (int s = 0;s < k;s++) 
        {
            if (dp[s] < 0) continue;
            for (int r = 0;r < k;r++) 
            {
                if (b[i][r] < 0) continue;
                int ns = (s + r) % k;
                ndp[ns] = max(ndp[ns],dp[s] + b[i][r]);
            }
        }
        dp = ndp;
    }
    cout << dp[0] << endl;

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