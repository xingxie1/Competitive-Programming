#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
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
    int n,x;
    cin >> n >> x;
    vvt a(n,vt(3));
    for (int i = 0;i < n;i++) cin >> a[i][0] >> a[i][1] >> a[i][2];
    vector<vector<double>> dp((1 << n) ,vector<double>(x + 1));
    for (int m = 0;m <= x;m++)
    {
        for (int mask = 0;mask < (1 << n);mask++)
        {
            for (int t = mask;t;t &= t - 1)
            {
                int j = __builtin_ctz(1u * t);
                if (a[j][1] > m) continue;
                int s = a[j][0],c = a[j][1];
                double p = 1.0 * a[j][2] / 100.0;
                dp[mask][m] = max((1 - p) * dp[mask][m - c] + p * (dp[mask ^ (1 << j)][m - c] + s), dp[mask][m]);
            }
        }
    }
    cout << fixed << setprecision(10);
    cout << dp[(1 << n) - 1][x] << endl;
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