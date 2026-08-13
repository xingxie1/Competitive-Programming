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
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    vvll dp(n,vll(n));
    for (int len = 1;len < n;len++)
    {
        for (int i = 0;i < n;i++)
        {
            int j = (i + len) % n;
            int ni = (i + 1) % n;
            int pj = (j - 1 + n) % n;
            ll dx = a[i].fi - a[j].fi;
            ll dy = a[i].se - a[j].se;
            dp[i][j] = max({dp[i][pj],dp[ni][j],dx * dx + dy * dy});
        }
    }
    ll ans = LLONG_MAX;
    auto line = [&](int i,int j,int k)
    {
        ll x1 = (ll)a[i].fi - a[j].fi;
        ll y1 = (ll)a[i].se - a[j].se;

        ll x2 = (ll)a[k].fi - a[j].fi;
        ll y2 = (ll)a[k].se - a[j].se;

        return x1 * y2 - x2 * y1 == 0;
    };

    for (int i = 0;i < n;i++)
    {
        for (int j = i + 1;j < n;j++)
        {
            if (i == j) continue;
            int pi = (i - 1 + n) % n;
            int ni = (i + 1) % n;
            if (line(pi,i,j)) continue;
            if (line(i,ni,j)) continue;
            ans = min(ans,dp[i][j] + dp[j][i]);
        }
    }
    cout << ans << endl;
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