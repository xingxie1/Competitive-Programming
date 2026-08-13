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
    int n,m;
    cin >> n >> m;
    vvt g(n);
    for (int i = 0;i < m;i++) 
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int w;
    cin >> w;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    auto get = [&](int d,int x)
    {
        return d * n + x;
    };
    int tot = n * w;
    vt color(tot);
    bool ok = false;
    auto dfs = [&](auto&& self,int id)
    {
        if (ok) return ;
        color[id] = 1;
        int d = id / n;
        int x = id % n;
        int nd = (d + 1) % w;
        auto go = [&](int y)
        {
            if (ok) return ;
            if (a[y][nd] == 'x') return ;
            int nid = get(nd,y);
            if (color[nid] == 1) 
            {
                ok = true;
                return ;
            }
            if (color[nid] == 0) 
            {
                self(self,nid);
            }
        };
        go(x);
        for (int y : g[x]) 
        {
            go(y);
            if (ok) return ;
        }
        color[id] = 2;
    };  
    for (int i = 0;i < n;i++) 
    {
        if (a[i][0] == 'x') continue;
        int id = i;
        if (color[id] == 0) dfs(dfs,id);
        if (ok) break;
    }
    if (ok) YES;
    else NO;
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