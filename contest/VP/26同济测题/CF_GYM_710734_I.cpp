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
    ll n,m,k;
    cin >> n >> m >> k;
    vvt a(n,vt(n,-1));
    for (int i = 0;i < m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        a[u][v] = max(w,a[u][v]);
        a[v][u] = max(w,a[v][u]);
    }
    vll dp(1 << n,-1);
    for (int i = 0;i < n;i++) dp[1 << i] = 0;
    for (int mask = 1;mask < 1 << n;mask++)
    {
        if (dp[mask] == -1) continue;
        for (int i = 0;i < n;i++) 
        {
            if (!(mask >> i & 1)) continue;
            for (int j = 0;j < n;j++)
            {
                if ((mask >> j & 1) || i == j) continue;
                if (a[i][j] == -1) continue;
                dp[mask | 1 << j] = max(dp[mask | 1 << j],dp[mask] + a[i][j]);
            }
        }
    }
    int ans = INT_MAX;
    for (int mask = 0;mask < 1 << n;mask++)
    {
        if (dp[mask] >= k) ans = min(ans,popcount(1u * mask));
    }
    if (ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;


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