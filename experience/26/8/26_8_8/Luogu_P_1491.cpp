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
    int n,m;
    cin >> n >> m;
    vector<vector<pdd>> g(n);
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        int dx = a[u].fi - a[v].fi;
        int dy = a[u].se - a[v].se;
        double d = sqrt(dx * dx + dy * dy);
        g[u].push_back({v,d});
        g[v].push_back({u,d});
    }
    vt pre(n,-1);
    auto dij = [&](int bu,int bv,int f)
    {
        pqueue<pdd,vpdd,greater<>> pq;
        pq.push({0,0});
        vd dis(n,INT_MAX / 2);
        dis[0] = 0;
        while (!pq.empty())
        {
            auto [d,x] = pq.top();
            pq.pop();
            if (d > dis[x]) continue;
            for (auto& [y,w] : g[x])
            {
                if ((x == bu && y == bv) || (x == bv && y == bu)) continue;
                double nd = d + w;
                if (nd < dis[y])
                {
                    dis[y] = nd;
                    pq.push({nd,y});
                    if (f) pre[y] = x;
                }
            }
        }
        return dis;
    };
    vd dis = dij(-1,-1,1); 
    if (dis[n - 1] == INT_MAX / 2) 
    {
        cout << -1 << endl;
        return ;
    }
    double ans = INT_MAX / 2;
    for (int v = n - 1;v != 0;v = pre[v])
    {
        int u = pre[v];
        vd nd = dij(u,v,0);
        ans = min(ans,nd[n - 1]);
    }
    if (ans == INT_MAX / 2) cout << -1 << endl;
    else cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(2);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}