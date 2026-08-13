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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m,d;
    cin >> n >> m >> d;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vector dp(n,vvll(m,vll(2)));
    vt pre(m + 1);
    for (int i = 0;i < m;i++) 
    {
        if (a[0][i] == 'X') 
        {
            dp[0][i][0] = 1;
            pre[i + 1] = pre[i] + 1;
        }
        else pre[i + 1] = pre[i];
    }
    for (int i = 0;i < m;i++) 
    {
        int r = min(m - 1,i + d);
        int l = max(0,i - d);
        ll sum = (pre[r + 1] - pre[l] - dp[0][i][0]) % MOD;
        if (a[0][i] == 'X') dp[0][i][1] = sum;
    }

    for (int i = 1;i < n;i++) 
    {
        vll pre(m + 1);
        for (int j = 0;j < m;j++) 
        {
            pre[j + 1] = (pre[j] + dp[i - 1][j][0] + dp[i - 1][j][1]) % MOD;
        }
        for (int j = 0;j < m;j++)
        {
            int dd = sqrt(d * d - 1);
            int r = min(m - 1,j + dd);
            int l = max(0,j - dd);
            ll sum = ((pre[r + 1] - pre[l]) % MOD + MOD) % MOD;
            if (a[i][j] == 'X') dp[i][j][0] = sum;
        }
        for (int j = 0;j <= m;j++) pre[j] = 0;
        for (int j = 0;j < m;j++) 
        {
            pre[j + 1] = (pre[j] + dp[i][j][0]) % MOD;
        }
        for (int j = 0;j < m;j++) 
        {
            int r = min(m - 1,j + d);
            int l = max(0,j - d);
            ll sum = ((pre[r + 1] - pre[l] - dp[i][j][0]) % MOD + MOD) % MOD;
            if (a[i][j] == 'X') dp[i][j][1] = sum;
        }
    }

    ll ans = 0;
    for (int j = 0;j < m;j++) 
    {
        ans = (ans + dp[n - 1][j][0] + dp[n - 1][j][1]) % MOD;
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