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

int dp[31][31][51];
auto init = []
{
    for (int i = 1;i <= 30;i++) 
    {
        for (int j = 1;j <= 30;j++) 
        {
            for (int k = 1;k <= 50;k++) 
            {
                dp[i][j][k] = INT_MAX / 3;
            }
            dp[i][j][0] = 0;
            if (i * j <= 50) dp[i][j][i * j] = 0;
        }
    }
    for (int n = 1;n <= 30;n++)
    {
        for (int m = 1;m <= 30;m++)
        {
            for (int k = 1;k <= 50;k++)
            {
                if (k == n * m) continue;
                for (int i = 1;i < n;i++)
                {
                    for (int x = max(0,k - (n - i) * m);x <= min(k,i * m);x++)
                    {
                        dp[n][m][k] = min(dp[n][m][k],dp[i][m][x] + dp[n - i][m][k - x] + m * m);
                    }
                }
                for (int j = 1;j < m;j++)
                {
                    for (int x = max(0,k - (m - j) * n);x <= min(k,j * n);x++)
                    {
                        dp[n][m][k] = min(dp[n][m][k],dp[n][j][x] + dp[n][m - j][k - x] + n * n);
                    }
                }
            }
        }
    }
    return 0;
}();
void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    cout << dp[n][m][k] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}