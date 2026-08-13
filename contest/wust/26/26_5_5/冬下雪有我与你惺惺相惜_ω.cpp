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
    vvt dp(n + 1,vt(m + 1,INT_MIN / 2));
    dp[0][0] = 0;
    for (int i = 0;i < n;i++) 
    {
        int mx = INT_MIN;
        for (int j = 0;j < i;j++) 
        {
            mx = max(mx,dp[i][j]);
        }
        for (int j = i;j < m;j++) 
        {
            mx = max(mx,dp[i][j]);
            dp[i + 1][j + 1] = mx + a[i][j];
        }
    }
    int ans = INT_MIN;
    for (int x : dp[n]) ans = max(ans,x);
    cout << ans << endl;
    vt b;
    int last = m + 1;
    for (int i = n;i >= 1;i--) 
    {
        int mxj = last - 1;
        for (int j = last - 1;j >= 1;j--) 
        {
            if (dp[i][j] >= dp[i][mxj]) mxj = j; 
        }
        b.push_back(mxj);
        last = mxj;
    }
    ranges::reverse(b);
    for (int x : b) cout << x << " ";
    cout << endl;
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