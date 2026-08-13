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
    int to,w,id;
};

void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<edge>> g(n);
    for (int i = 0;i < m;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u --;v--;
        g[u].push_back({v,w,i});
        g[v].push_back({u,w,i});
    }
    vll dis(n,LLONG_MAX / 2);
    dis[0] = 0;
    pqueue<trl,vector<trl>,greater<>> pq;
    pq.push({0,0,-1});
    vt ans;
    while (!pq.empty()) 
    {
        auto [d,x,id] = pq.top();
        pq.pop();
        if (d > dis[x]) continue;
        if (id != -1) ans.push_back(id + 1);
        if (ans.size() == n - 1) break;
        for (auto& [y,w,id1] : g[x]) 
        {
            ll nd = d + w;
            if (nd < dis[y]) 
            {
                pq.push({nd,y,id1});
                dis[y] = nd;
            }
        }
    }
    for (int x : ans) cout << x << " ";
    cout << endl;
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