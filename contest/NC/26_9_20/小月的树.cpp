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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vvt g(n);
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vvll dp(n,vll(3,INT_MAX / 2));
    auto dfs = [&](auto&& self,int u,int fa) -> void
    {   
        if (g[u].size() == 1 && fa != -1) 
        {
            dp[u][0] = 0;
            dp[u][1] = 1;
            dp[u][2] = INT_MAX / 2;
            return ;
        }
        ll s0 = 0,s1 = 1,s2 = 0;
        int f0 = 0,bad = 0;
        vpll a;
        for (int v : g[u])
        {
            if (v == fa) continue;
            self(self,v,u);
            ll val =INT_MAX / 2,sv = dp[v][1];
            if (s[u] == s[v])
            {
                s0 += dp[v][0];
                s2 += dp[v][0];
                val = dp[v][0];
                sv = min(sv,dp[v][2]);
            }
            else 
            {
                f0 = 1;
                bad++;
            }
            s1 += min(dp[v][0],dp[v][1]);
            a.push_back({val,sv});
        }
        dp[u][0] = f0 ? INT_MAX / 2 : s0;
        dp[u][1] = s1;
        dp[u][2] = INT_MAX / 2;
        if (bad == 0) 
        {
            for (auto& [x,y] : a)
            {
                dp[u][2] = min(dp[u][2],s2 - x + y);
            }
        }
        else if (bad == 1)
        {
            for (auto& [x,y] : a)
            {
                if (x == INT_MAX / 2);
                {
                    dp[u][2] = min(dp[u][2],s2 + y);
                }
            }
        }
    };
    dfs(dfs,0,-1);
    cout << min(dp[0][1],dp[0][2]) << endl;
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