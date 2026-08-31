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
    vvpii g(n);
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    vt a(n);
    int ans = 0;
    auto dfs = [&](auto&& self,int u,int fa,int cnt) -> void
    {
        if (g[u].size() == 1 && fa != -1)
        {
            ans = max(ans,cnt);
            return ;
        }
        for (auto&[v,w] : g[u])
        {
            if (v == fa) continue;
            a[v] = w;
            self(self,v,u,(a[u] > a[v]) + cnt);
        }
    };
    dfs(dfs,0,-1,0);
    cout << ans + 1 << endl;
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