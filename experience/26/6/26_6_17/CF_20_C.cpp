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
    int n,m;
    cin >> n >> m;
    vvpii g(n);
    set<pii> st;
    for (int i = 0;i < m;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        if (u > v) swap(u,v);
        if (u == v || st.contains({u,v})) continue;
        st.insert({u,v});
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    pqueue<pll,vpll,greater<>> pq;
    pq.push({0,0});
    vll dis(n,LLONG_MAX / 2);
    vt pre(n,-1);
    dis[0] = 0;
    while (!pq.empty()) 
    {
        auto [d,x] = pq.top();
        pq.pop();
        if (d > dis[x]) continue;
        for (auto& [y,w] : g[x])
        {
            ll nd = d + w;
            if (nd < dis[y]) 
            {
                dis[y] = nd;
                pre[y] = x;
                pq.push({nd,y});
            }
        }
    }
    if (dis[n - 1] == LLONG_MAX / 2) 
    {
        cout << -1 << endl;
        return ;
    }
    int cur = n - 1;
    vt ans;
    while (cur != -1)
    {
        ans.push_back(cur);
        cur = pre[cur];
    }
    ranges::reverse(ans);
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