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
    vvll f(n + 1,vll(m + 1,LLONG_MIN / 2)),g(n + 1,vll(m + 1,LLONG_MIN / 2));
    f[0][1] = 0;
    g[n][m - 1] = 0;
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++)
        {
            f[i + 1][j + 1] = max(f[i][j + 1],f[i + 1][j]) + a[i][j];
        }
    }
    for (int i = n - 1;i >= 0;i--)
    {
        for (int j = m - 1;j >= 0;j--)
        {
            g[i][j] = max(g[i][j + 1],g[i + 1][j]) + a[i][j];
        }
    }
    ll ans = LLONG_MAX;
    for (int i = 0;i < n;i++)
    {
        vll sum1(m + 1),sum2(m),suf(m + 1,LLONG_MIN / 2);
        for (int j = 0;j < m;j++) 
        {
            sum1[j] = f[i + 1][j + 1] + g[i + 1][j]; 
            sum2[j] = f[i][j + 1] + g[i][j];
        }
        for (int j = m - 1;j >= 0;j--) suf[j] = max(suf[j + 1],sum2[j]);
        for (int j = 0;j < m;j++)
        {
            ll s1 = f[i + 1][j + 1] + g[i][j] - 3LL * a[i][j];
            ll s2 = LLONG_MIN / 2;
            if (j) s2 = sum1[j - 1];
            ll s3 = LLONG_MIN / 2;
            if (j < m - 1) s3 = suf[j + 1];
            ans = min(ans,max({s1,s2,s3}));
            sum1[j + 1] = max(sum1[j],sum1[j + 1]);
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