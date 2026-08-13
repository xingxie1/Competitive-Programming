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
    int n;
    cin >> n;
    vvt a(n,vt(n));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < n;j++) cin >> a[i][j];
    }
    vll dp(1 << n);
    dp[0] = 1;
    for (int mask = 0;mask < (1 << n);mask++)
    {
        int i = popcount(1u * mask);
        if (i >= n) continue;
        for (int j = 0;j < n;j++) 
        {
            if (a[i][j] && !(mask >> j & 1)) 
            {
                dp[mask | 1 << j] = (dp[mask | 1 << j] + dp[mask]) % MOD;
            }
        }
    }
    cout << dp[(1 << n) - 1] << endl;
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