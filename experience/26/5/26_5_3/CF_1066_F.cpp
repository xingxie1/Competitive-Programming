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
    vpll a(n + 1);
    a[0] = {0,0};
    for (int i = 1;i <= n;i++) cin >> a[i].fi >> a[i].se;
    ranges::sort(a,{},[&](auto& c) {
        return pair{max(c.fi,c.se),pair{c.fi,-c.se}};
    });
    ll ans = 0;
    vvpll b(2);
    b[0].push_back({0,0});
    b[1].push_back({0,0});
    for (int i = 1;i <= n;i++) 
    {
        int j = i;
        while (j <= n && max(a[j].fi,a[j].se) == max(a[i].fi,a[i].se)) j++;
        for (int k = i;k < j - 1;k++)
        {
            ans += abs(a[k + 1].fi - a[k].fi) + abs(a[k + 1].se - a[k].se);
            // cout << a[k].fi << " " << a[k].se << " " << a[k + 1].fi << " " << a[k + 1].se << endl;
            // cout << abs(a[k + 1].fi - a[k].fi) + abs(a[k + 1].se - a[k].se) << endl;
        }
        b[0].push_back({a[i].fi,a[i].se});
        b[1].push_back({a[j - 1].fi,a[j - 1].se});
        i = j - 1;
    }
    int m = b[0].size();
    vvll dp(2,vll(m,LLONG_MAX / 2));
    // cout << m << " " << ans << endl;
    dp[0][0] = dp[1][0] = 0;
    for (int i = 1;i < m;i++) 
    {
        dp[0][i] = min(dp[0][i - 1] + abs(b[0][i].fi - b[1][i - 1].fi) + abs(b[0][i].se - b[1][i - 1].se), dp[1][i - 1] + abs(b[0][i].fi - b[0][i - 1].fi) + abs(b[0][i].se - b[0][i - 1].se));
        dp[1][i] = min(dp[0][i - 1] + abs(b[1][i].fi - b[1][i - 1].fi) + abs(b[1][i].se - b[1][i - 1].se), dp[1][i - 1] + abs(b[1][i].fi - b[0][i - 1].fi) + abs(b[1][i].se - b[0][i - 1].se));
        // cout << dp[0][i] << " " << dp[1][i] << endl;
    }
    cout << ans + min(dp[0][m - 1],dp[1][m - 1]) << endl;


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