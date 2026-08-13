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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt p(n,vt(n));
    while (k--)
    {
        int x,y,w;
        cin >> x >> y >> w;
        x--;y--;
        p[x][y] = w;
    }
    vvll dp(1 << n,vll(n));
    for (int s = 1;s < 1 << n;s <<= 1)
    {
        for (int i = 0;i < n;i++) dp[s][i] = a[i];
    }
    for (int s = 0;s < 1 << n;s++) 
    {
        for (int j = 0;j < n;j++) 
        {
            if (s >> j & 1) continue; 
            for (int last = 0;last < n;last++)
            {
                if (!(s >> last & 1)) continue;
                int x = p[last][j]; 
                dp[s | 1 << j][j] = max(dp[s | 1 << j][j],dp[s][last] + x + a[j]);
            }
        }
    }
    ll ans = 0;
    for (int s = 0;s < 1 << n;s++) 
    {
        if (popcount(1u * s) != m) continue;
        for (ll x : dp[s]) ans = max(ans,x);
    }
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