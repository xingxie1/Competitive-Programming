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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    vt deg(n);
    vvt edges;
    for (int i = 0;i < m;i++) 
    {
        int u,v,t;
        cin >> t >> u >> v;
        u--;v--;
        edges.push_back({t,u,v});
        if (t == 1) 
        {
            g[u].push_back(v);
            deg[v]++;
        }
    }
    queue<int> q;
    for (int i = 0;i < n;i++) 
    {
        if (deg[i] == 0) q.push(i);
    }
    vt ord;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        ord.push_back(x);
        for (int y : g[x]) 
        {
            deg[y]--;
            if (!deg[y]) q.push(y);
        }
    }
    if (ord.size() != n) 
    {
        NO;
        return ;
    }
    vt pos(n);
    for (int i = 0;i < n;i++) 
    {
        pos[ord[i]] = i;
    }
    YES;
    for (auto& e : edges)
    {
        int t = e[0],u = e[1],v = e[2];
        if (t == 1 ) cout << u + 1 << " " << v + 1 << endl;
        else 
        {
            if (pos[u] > pos[v]) cout << v + 1 << " " << u + 1 << endl;
            else cout << u + 1 << " " << v + 1 << endl;
        }
    }
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