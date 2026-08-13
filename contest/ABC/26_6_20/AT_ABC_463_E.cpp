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

void solve()
{
    int n,m,y;
    cin >> n >> m >> y;
    vvpii g(n + 1);
    for (int i = 0;i < m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    vt a(n + 1);
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) 
    {
        g[i].push_back({0,y / 2 + a[i]});
        g[0].push_back({i,y - y / 2 + a[i]});
    }
    vll dis(n + 1,LLONG_MAX / 2);
    dis[1] = 0;
    pqueue<pll,vpll,greater<>> pq;
    pq.push({0,1});
    while (!pq.empty()) 
    {
        auto [d,x] = pq.top();
        pq.pop();
        if (d > dis[x]) continue;
        for (auto& [y,w] : g[x]) 
        {
            ll nd = w + d;
            if (nd < dis[y]) 
            {
                dis[y] = nd;
                pq.push({nd,y});
            }
        }
    }
    for (int i = 2;i <= n;i++) cout << dis[i] << " ";
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