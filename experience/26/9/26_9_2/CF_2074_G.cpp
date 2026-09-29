#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    a.insert(a.end(),a.begin(),a.end());
    vvll dp(2 * n,vll(2 * n));
    ll ans = 0;
    for (int i = 2 * n - 1;i >= 0;i--)
    {
        for (int j = i + 2;j < 2 * n;j++)
        {
            if (j > i + n - 1) break;
            for (int k = i;k < j;k++)
            {
                dp[i][j] = max(dp[i][j],dp[i][k] + dp[k + 1][j]);
                ans = max(ans,dp[i][j]);
            }
            for (int k = i + 1;k < j;k++)
            {
                dp[i][j] = max(dp[i][j],dp[i + 1][k - 1] + dp[k + 1][j - 1] + a[i] * a[j] * a[k]);
                ans = max(ans,dp[i][j]);
            }
        }
    }
    cout << ans << endl;
}   

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}