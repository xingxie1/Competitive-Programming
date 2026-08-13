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
    int n,m;
    cin >> n >> m;
    vt a(n),b(m);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < m;i++) cin >> b[i];
    vvt dp(n + 1,vt(m + 1));
    for (int i = n;i >= 0;i--)
    {
        for (int j = m;j >= 0;j--)
        {
            if (i == n && j == m) continue;
            if ((i + j) % 2 == 0) 
            {
                int res = 0;
                if (i < n) res = max(res,a[i] + dp[i + 1][j]);
                if (j < m) res = max(res,b[j] + dp[i][j + 1]);
                dp[i][j] = res;
            }
            else 
            {
                int res = INT_MAX;
                if (i < n) res = min(res,dp[i + 1][j]);
                if (j < m) res = min(res,dp[i][j + 1]);
                dp[i][j] = res;
            }
        }
    }
    cout << dp[0][0] << endl;
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