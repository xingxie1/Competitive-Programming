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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    a.insert(a.end(),a.begin(),a.end());
    vll pre(2 * n + 1);
    for (int i = 0;i < 2 * n;i++) pre[i + 1] = pre[i] + a[i];
    vvll f(2 * n,vll(2 * n,INT_MAX / 2));
    vvll g(2 * n,vll(2 * n));
    for (int i = 2 * n - 1;i >= 0;i--)
    {
        f[i][i] = 0;
        g[i][i] = 0;
        for (int j = i + 1;j < 2 * n;j++)
        {
            if (j - i + 1 > n) break;
            for (int k = i;k < j;k++)
            {
                f[i][j] = min(f[i][j],f[i][k] + f[k + 1][j]+ pre[j + 1] - pre[i]);
                g[i][j] = max(g[i][j],g[i][k] + g[k + 1][j]+ pre[j + 1] - pre[i]);
            }
        }
    }
    ll mn = LLONG_MAX,mx = 0;
    for (int i = 0;i < n;i++) 
    {
        mn = min(mn,f[i][i + n - 1]);
        mx = max(mx,g[i][i + n - 1]);
    }
    cout << mn << endl;
    cout << mx << endl;
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