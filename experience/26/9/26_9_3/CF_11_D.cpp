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
    vvt a(n,vt(n));
    for (int i = 0;i < m;i++)
    {
        int x,y;
        cin >> x >> y;
        x--;y--;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    vvll dp(1 << n,vll(n));
    for (int i = 0;i < n;i++) dp[1 << i][i] = 1;
    ll ans = 0;
    for (int mask = 1;mask < 1 << n;mask++)
    {
        int s = 0;
        while (!(mask >> s & 1)) s++;
        for (int i = s;i < n;i++)
        {
            if (!(mask >> i & 1)) continue;
            if (!dp[mask][i]) continue;
            if (popcount(1u * mask) >= 3 && a[i][s])
            {
                ans += dp[mask][i];
            }
            for (int j = s + 1;j < n;j++)
            {
                if (mask >> j & 1) continue;
                if (!a[i][j]) continue;
                dp[mask | 1 << j][j] += dp[mask][i];
            }
        }
    }
    ans /= 2;
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