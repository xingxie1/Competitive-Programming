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
    vvt g(n);
    for (int i = 1;i < n;i++)
    {
        int x;
        cin >> x;
        x--;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    vt dep(n);
    auto dfs = [&](auto&& self,int u,int fa) -> void
    {
        for (int v : g[u]) 
        {
            if (v == fa) continue;
            dep[v] = dep[u] + 1;
            self(self,v,u);
        }
    };
    dfs(dfs,0,-1);
    vt MN(n,INT_MAX / 2);
    auto dfs2 = [&](auto&& self,int u,int fa) -> int
    {
        if ((g[u].size() == 1 && fa != -1))
        {
            // cout << u << " " << dep[u] << endl;
            return MN[u] = dep[u];
        }
        if (g[u].size() == 2 - (fa == -1)) 
        {
            MN[u] = dep[u];
            for (int v : g[u]) 
            {
                if (v == fa) continue;
                self(self,v,u);
            }
            return MN[u];
        }
        else 
        {
            int mn = INT_MAX / 2;
            for (int v : g[u]) 
            {
                if (v == fa) continue;
                mn = min(mn,self(self,v,u));
            }
            return MN[u] = mn;
        }
    };
    dfs2(dfs2,0,-1);
    vt dp(n);
    auto dfs3 = [&](auto&& self,int u,int fa) -> int
    {
        for (int v : g[u]) 
        {
            if (v == fa) continue;
            dp[u] += self(self,v,u);
        }
        dp[u] += MN[u] - dep[u];
        return dp[u];
    };
    dfs3(dfs3,0,-1);
    // for (int i = 0;i < n;i++) 
    // {
    //     cout << dep[i] << " " << MN[i] << endl;
    // }
    // cout << endl;
    // for (int i = 0;i < n;i++) cout << dp[i] << " ";
    cout << dp[0] + n << endl;
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