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
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
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
        for (int j = 1;j <= m;j++) 
        {
            for (int k = 0;k < j;k++)
            {
                dp[i + 1][j] = max(dp[i + 1][j],dp[i][k] + a[i][j - 1]);
            }
        }
    }
    cout << ranges::max(dp[n]) << endl;
    vt ans;
    int last = m;
    int mx = dp[n][m - 1];
    for (int i = n;i >= 1;i--)
    {
        int mxj = last;
        for (int j = last;j >= 1;j--)
        {
            if (dp[i][j] > dp[i][mxj]) 
            {
                mxj = j;
            }
        }
        last = mxj - 1;
        ans.push_back(mxj);
    }
    ranges::reverse(ans);
    for (int x : ans) cout << x << " ";
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}