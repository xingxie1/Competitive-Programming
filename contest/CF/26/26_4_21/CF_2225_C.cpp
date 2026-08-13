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
    vector<string> a(2);
    cin >> a[0] >> a[1];
    vvt dp(n,vt(2,INT_MAX / 2));
    if (a[0][0] == a[1][0]) dp[0][0] = 0;
    else dp[0][0] = 1;
    if (n > 1) dp[1][1] = (a[0][0] != a[0][1]) + (a[1][0] != a[1][1]);
    for (int i = 1;i < n;i++)
    {
        if (a[0][i] == a[1][i]) 
        {
            dp[i][0] = min(dp[i - 1][0],dp[i - 1][1]);
        }
        else dp[i][0] = min(dp[i - 1][0],dp[i - 1][1]) + 1;
        if (i >= 2) 
        {
            int cnt = 0;
            if (a[0][i] != a[0][i - 1]) cnt++;
            if (a[1][i] != a[1][i - 1]) cnt++;
            dp[i][1] = min(dp[i - 2][0],dp[i - 2][1]) + cnt;
        }
    }
    cout << min(dp[n - 1][0],dp[n - 1][1]) << endl;
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