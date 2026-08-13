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
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vvt> dp(n + 1,vvt(4,vt(2,INT_MAX / 2)));
    dp[1][0][1] = (s[0] != '1');
    dp[1][0][0] = (s[0] != '0');
    for (int i = 1;i < n;i++) 
    {
        if (s[i] == '0') 
        {
            dp[i + 1][0][0] = dp[i][0][0];
            dp[i + 1][0][1] = dp[i][0][1] + 1;
            dp[i + 1][1][0] = min(dp[i][0][1],dp[i][1][0]);
            dp[i + 1][1][1] = min(dp[i][0][0],dp[i][1][1]) + 1;35
            dp[i + 1][2][0] = min(dp[i][1][1],dp[i][2][0]);
            dp[i + 1][2][1] = min(dp[i][1][0],dp[i][2][1]) + 1;
            dp[i + 1][3][0] = min(dp[i][2][1],dp[i][3][0]);
            dp[i + 1][3][1] = min(dp[i][2][0],dp[i][3][1]) + 1;
        }
        else 
        {
            dp[i + 1][0][0] = dp[i][0][0] + 1;
            dp[i + 1][0][1] = dp[i][0][1];
            dp[i + 1][1][0] = min(dp[i][0][1],dp[i][1][0]) + 1;
            dp[i + 1][1][1] = min(dp[i][0][0],dp[i][1][1]);
            dp[i + 1][2][0] = min(dp[i][1][1],dp[i][2][0]) + 1;
            dp[i + 1][2][1] = min(dp[i][1][0],dp[i][2][1]);
            dp[i + 1][3][0] = min(dp[i][2][1],dp[i][3][0]) + 1;
            dp[i + 1][3][1] = min(dp[i][2][0],dp[i][3][1]);
        }
    }
    int ans = min(dp[n][3][0],dp[n][3][1]);
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