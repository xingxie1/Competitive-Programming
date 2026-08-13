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
    int t;
    cin >> t;
    vvt b(n,vt(m,INT_MAX));
    while (t--)
    {
        int x,y,v;
        cin >> x >> y >> v;
        x--,y--;
        b[x][y] = v;
    }
    vvt dp(n + 1,vt(m + 1,INT_MIN / 2));
    dp[0][1] = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            if (i + j < b[i][j]) dp[i + 1][j + 1] = max(dp[i + 1][j],dp[i][j + 1]) + a[i][j];
            else dp[i + 1][j + 1] = INT_MIN / 2;
        }
    }
    int ans = 0;
    for (int i = 0;i <= n;i++) 
    {
        for (int x : dp[i]) 
        {
            ans = max(ans,x);
            // cout << x << " ";
        }
        // cout << endl;
    }
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