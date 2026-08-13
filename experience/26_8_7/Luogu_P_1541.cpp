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
    vll a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    vt cnt(5);
    for (int i = 0;i < m;i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    vector dp(cnt[1] + 1,vector(cnt[2] + 1,vector(cnt[3] + 1,vector<ll>(cnt[4] + 1))));
    dp[0][0][0][0] = a[1];
    for (int c1 = 0;c1 <= cnt[1];c1++)
    {
        for (int c2 = 0;c2 <= cnt[2];c2++)
        {
            for (int c3 = 0;c3 <= cnt[3];c3++)
            {
                for (int c4 = 0;c4 <= cnt[4];c4++)
                {
                    int cur = c1 + 2 * c2 + 3 * c3 + 4 * c4 + 1;
                    if (c1 > 0) dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4],a[cur] + dp[c1 - 1][c2][c3][c4]);
                    if (c2 > 0) dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4],a[cur] + dp[c1][c2 - 1][c3][c4]);
                    if (c3 > 0) dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4],a[cur] + dp[c1][c2][c3 - 1][c4]);
                    if (c4 > 0) dp[c1][c2][c3][c4] = max(dp[c1][c2][c3][c4],a[cur] + dp[c1][c2][c3][c4 - 1]);
                }
            }
        }
    }
    cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << endl;
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