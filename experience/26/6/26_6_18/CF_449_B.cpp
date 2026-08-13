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

struct edge
{
    int to;
    ll w;
    int type;
};
struct Node
{
    ll dist;
    int type;
    int u;
    bool operator > (const Node& other) const
    {
        if (dist != other.dist) return dist > other.dist;
        return type > other.type;
    }
};
void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vector<vector<edge>> g(n);
    for (int i = 0;i < m;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back({v,w,0});
        g[v].push_back({u,w,0});
    }
    for (int i = 0;i < k;i++) 
    {
        int y,w;
        cin >> y >> w;
        y--;
        g[0].push_back({y,w,1});
        g[y].push_back({0,w,1});
    }
    pqueue<Node,vector<Node>,greater<>> pq;
    pq.push({0,0,0});
    vll dis(n,LLONG_MAX / 2);
    vt vis(n);
    int cnt = 0;
    dis[0] = 0;
    while (!pq.empty())
    {
        auto [d,ty,x] = pq.top();
        pq.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        if (ty == 1) cnt++;
        for (auto& [y,w,ty1] : g[x]) 
        {
            ll nd = d + w;
            if (nd > dis[y]) continue;
            if (nd < dis[y]) 
            {
                pq.push({nd,ty1,y});
                dis[y] = nd;
            }
            else if (nd == dis[y] && ty1 == 0) pq.push({nd,ty1,y});
        }
    } 
    cout << k - cnt << endl;
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