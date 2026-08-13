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
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
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
    int n;
    cin >> n;
    vvt g(n);
    for (int i = 1;i < n;i++) 
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto dfs = [&](auto&& self,int u,int fa) -> tuple<int,int,int>
    {
        int mnc = INT_MAX;
        int a = 1,b = 0,c = 0;
        for (int v : g[u])
        {
            if (v == fa) continue;
            auto [la,lb,lc] = self(self,v,u);
            a += min(la,lb);
            b += min(la,lc);
            mnc = min(mnc,la - lc);
        }
        // cout << u << endl;
        // cout << a << " " << b << " " << c << endl;
        if (a == 1 && b == 0 && c == 0) return {1,0,INT_MAX / 2};
        c = b + max(0,mnc);
        return {a,b,c};
    };
    auto [a,b,c] = dfs(dfs,0,-1);
    cout << min(a,c) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}