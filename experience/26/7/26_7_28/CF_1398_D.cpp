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
    int R,G,B;
    cin >> R >> G >> B;
    vt r(R),g(G),b(B);
    for (int i = 0;i < R;i++) cin >> r[i];
    for (int i = 0;i < G;i++) cin >> g[i];
    for (int i = 0;i < B;i++) cin >> b[i];
    ranges::sort(r,{},[&](auto& x) {return -x;});
    ranges::sort(g,{},[&](auto& x) {return -x;});
    ranges::sort(b,{},[&](auto& x) {return -x;});
    vvvll dp(R + 1,vvll(G + 1,vll(B + 1)));
    auto dfs = [&](auto&& self,int i,int j,int k) -> ll
    {
        if (i == R && j == G && k == B) return 0LL;
        if ((i == R && j == G) || (i == R && k == B) || (j == G && k == B)) return 0LL;
        if (i == R) return dp[i][j][k] = g[j] * b[k] + self(self,i,j + 1,k + 1);
        if (j == G) return dp[i][j][k] = r[i] * b[k] + self(self,i + 1,j,k + 1);
        if (k == B) return dp[i][j][k] = r[i] * g[j] + self(self,i + 1,j + 1,k);
        if (dp[i][j][k]) return dp[i][j][k];
        ll &res = dp[i][j][k];
        res = max({res,r[i] * g[j] + self(self,i + 1,j + 1,k), r[i] * b[k] + self(self,i + 1,j,k + 1), g[j] * b[k] + self(self,i,j + 1,k + 1)});
        return res;
    };
    dfs(dfs,0,0,0);
    cout << dp[0][0][0] << endl;
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