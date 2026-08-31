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
    int n;
    cin >> n;
    vvt a(n,vt(n));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < n;j++) cin >> a[i][j];
    }
    vvvt dp(n + 1,vvt(n + 1,vt(2,INT_MAX / 2)));
    dp[0][1][0] = 0;
    dp[0][1][1] = 0;
    int x = -1,y = -1;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < n;j++)
        {
            if (a[i][j] == 0)
            {
                x = i,y = j;
                dp[i + 1][j + 1][0] = INT_MAX / 2;
                dp[i + 1][j + 1][1] = INT_MAX / 2;
                continue;
            }
            int c2 = 0,c5 = 0;
            int x = a[i][j];
            while (x % 2 == 0) 
            {
                x /= 2;
                c2++;
            }
            while (x % 5 == 0) 
            {
                x /= 5;
                c5++;
            }
            dp[i + 1][j + 1][0] = min(dp[i][j + 1][0],dp[i + 1][j][0]) + c2;
            dp[i + 1][j + 1][1] = min(dp[i][j + 1][1],dp[i + 1][j][1]) + c5;
        }
    }
    if (x != -1 && min(dp[n][n][0],dp[n][n][1]))
    {
        cout << 1 << endl;
        for (int ii = 0;ii < x;ii++)
        {
            cout << 'D';
        }
        for (int jj = 0;jj < y;jj++)
        {
            cout << 'R';
        }
        for (int ii = x + 1;ii < n;ii++)
        {
            cout << 'D';
        }
        for (int jj = y + 1;jj < n;jj++)
        {
            cout << 'R';
        }
        return ;
    }
    cout << min(dp[n][n][0],dp[n][n][1]) << endl;
    int t = 0;
    if (dp[n][n][1] < dp[n][n][0]) t = 1;
    string ans;
    int i = n,j = n;
    while (i != 1 || j != 1)
    {
        vt cnt(2);
        int x = a[i - 1][j - 1];
        while (x % 2 == 0) 
        {
            x /= 2;
            cnt[0]++;
        }
        while (x % 5 == 0) 
        {
            x /= 5;
            cnt[1]++;
        }
        if (dp[i][j][t] == dp[i - 1][j][t] + cnt[t])
        {
            i = i - 1;
            ans += 'D';
        }
        else 
        {
            j = j - 1;
            ans += 'R';
        }
    }
    ranges::reverse(ans);
    cout << ans << endl;
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