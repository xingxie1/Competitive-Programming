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
const int MOD = (int)1e9+7;

void solve()
{
    int n,k;
    cin >> n >> k;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll dp(k + 1);
    dp[0] = 1;
    for (int i = 0;i < n;i++) 
    {
        vll pre(k + 1);
        pre[0] = dp[0];
        for (int j = 0;j < k;j++) pre[j + 1] = (pre[j] + dp[j + 1]) % MOD;
        for (int j = 0;j <= k;j++) 
        {
            dp[j] = pre[j];
            if (j - a[i] - 1 >= 0) dp[j] = (dp[j] - pre[j - a[i] - 1] + MOD) % MOD; 
        }
    }
    cout << dp[k] << endl;
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