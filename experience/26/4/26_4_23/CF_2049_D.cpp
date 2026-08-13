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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
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
    ll n,m,k;
    cin >> n >> m >> k;
    vvt a(n,vt(m));
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) cin >> a[i][j];
    }
    vvll f(n + 1,vll(m + 1,LLONG_MAX / 2));
    vector<vvll> g(n + 1,vvll(m + 1,vll(m + 1,LLONG_MAX / 2)));
    g[0][0][1] = 0;
    f[0][1] = 0;
    for (int i = 0;i < n;i++)
    {
        for (int c = 0;c < m;c++)
        {
            for (int j = 0;j < m;j++)
            {
                g[i + 1][c][j + 1] = min(g[i + 1][c][j],f[i][j + 1])+ a[i][(j + c) % m];
                f[i + 1][j + 1] = min(f[i + 1][j + 1],g[i + 1][c][j + 1] + c * k);
            }
        }
    }
    cout << f[n][m] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}