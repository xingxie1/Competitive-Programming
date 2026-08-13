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

struct Edge
{
    int to;
    int id;
    ll w;
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vector<vector<Edge>> g(n);
    for (int i = 0;i < m;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back({v,i + 1,w});
        g[v].push_back({u,i + 1,w});
    }  
    int st;
    cin >> st;
    st--;
    vll dis(n,LLONG_MAX / 2);
    vll best(n,LLONG_MAX / 2);
    vt pre(n,-1);
    vt ans;
    dis[st] = 0;
    pqueue<pll,vpll,greater<>> pq;
    pq.push({0,st});
    while (!pq.empty()) 
    {
        auto [d,x] = pq.top();
        pq.pop();
        if (d > dis[x]) continue;
        for (auto e : g[x]) 
        {
            int y = e.to,id = e.id;
            ll w = e.w;
            ll nd = d + w;
            if (nd < dis[y]) 
            {
                dis[y] = nd;
                best[y] = w;
                pre[y] = id;
                pq.push({nd,y});
            }
            else if (nd == dis[y] && w < best[y]) 
            {
                best[y] = w;
                pre[y] = id;
            }
        }
    }
    ll sum = 0;
    for (int i = 0;i < n;i++) 
    {
        if (i == st) continue;
        sum += best[i];
        ans.push_back(pre[i]);
    }
    cout << sum << endl;
    for (int x : ans) cout << x << " ";
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