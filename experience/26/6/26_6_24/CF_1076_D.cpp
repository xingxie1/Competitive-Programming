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

struct edge{
    int to,w,id;
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
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
    }
    vt ans;
    pqueue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<>> pq;
    pq.push({0,0,-1});
    vll dis(n,LLONG_MAX / 2);
    dis[0] = 0;
    while (!pq.empty()) 
    {
        if (ans.size() >= k) break;
        auto [d,x,id] = pq.top();
        pq.pop();
        if (d > dis[x]) continue;
        if (id >= 0) ans.push_back(id);
        for (auto& [y,w,i] : g[x]) 
        {
            ll nd = d + w;
            if (nd < dis[y]) 
            {
                dis[y] = nd;
                pq.push({nd,y,i});
            }
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) cout << x + 1 << " ";
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