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
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,k,c;
    cin >> n >> k >> c;
    vvt g(n);
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vt h(n);
    ll ans = 0;
    auto dfs = [&](auto&& self,int u,int fa)
    {
        if (g[u].size() == 1 && fa != -1) return 0;
        int mx1 = 0,mx2 = 0;
        for (int v : g[u])
        {
            if (v == fa) continue;
            h[v] = h[u] + 1;
            ans = max(ans,1LL * k * h[v]);
            int x = self(self,v,u) + 1;
            if (x > mx1)
            {
                mx2 = mx1;
                mx1 = x;
            }
            else if (x > mx2) mx2 = x;
        }
        ans = max(ans,-1LL * (h[u] + min(mx1,mx2)) * c + 1LL * k * (mx1 + mx2));
        // cout << u << " " << mx1 << " " << mx2 << endl;
        return max(mx1,mx2);
    };
    dfs(dfs,0,-1);
    cout << ans << endl;
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