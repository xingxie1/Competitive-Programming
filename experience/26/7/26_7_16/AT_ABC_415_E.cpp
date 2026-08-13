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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vvt a(n,vt(m));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) cin >> a[i][j];
    }
    int k = n + m - 1;
    vt p(k);
    for (int i = 0;i < k;i++) cin >> p[i];
    ll l = -1,r = LLONG_MAX / 2;
    auto check = [&](ll x) 
    {
        vvll dp(n + 1,vll(m + 1,LLONG_MIN / 2));
        dp[0][1] = x;
        dp[1][0] = x;
        for (int i = 0;i < n;i++) 
        {
            for (int j = 0;j < m;j++)
            {
                if (dp[i + 1][j] + a[i][j] - p[i + j] >= 0) dp[i + 1][j + 1] = max(dp[i + 1][j + 1],dp[i + 1][j] + a[i][j] - p[i + j]);
                if (dp[i][j + 1] + a[i][j] - p[i + j] >= 0) dp[i + 1][j + 1] = max(dp[i + 1][j + 1],dp[i][j + 1] + a[i][j] - p[i + j]);
            }
        }
        return dp[n][m] >= 0;
    };
    while (l + 1 < r) 
    {
        ll m = l + (r - l) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    cout << r << endl;
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