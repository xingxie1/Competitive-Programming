#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
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
    int n,k;
    cin >> n >> k;
    vt a(n),c(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> c[i];
    k = min(k,12 * n);
    vt f(1e3 + 1,INT_MAX / 2); 
    f[1] = 0;
    for (int i = 1;i <= 1e3;i++) 
    {
        for (int j = 1;j <= i;j++) 
        {
            if (i + i / j <= 1e3) f[i + i / j] = min(f[i + i / j],f[i] + 1);
        }
    }
    for (int i = 0;i < n;i++) 
    {
        a[i] = f[a[i]];
    }

    vt dp(k + 1);
    for (int i = 0;i < n;i++) 
    {
        auto ndp = dp;
        for (int j = k;j >= a[i];j--) 
        {
            ndp[j] = max(ndp[j],dp[j - a[i]] + c[i]);
        }
        dp = ndp;
    }
    cout << dp[k] << endl;
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