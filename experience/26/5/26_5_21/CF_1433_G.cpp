#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
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
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m,k;
    cin >> n >> m >> k;
    vvt qs(k,vt(2));
    vvt edge(m,vt(2));
    vvpii g(n);
    for (int i = 0;i < m;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        edge[i] = {u,v};
    }
    for (int i = 0;i < k;i++) cin >> qs[i][0] >> qs[i][1],qs[i][0]--,qs[i][1]--;
    vvt dis(n,vt(n,INT_MAX / 2));
    for (int i = 0;i < n;i++)
    {
        pqueue<pii,vpii,greater<>> pq;
        pq.push({0,i});
        dis[i][i] = 0;
        while (!pq.empty()) 
        {
            auto [d,x] = pq.top();
            pq.pop();
            if (dis[i][x] < d) continue;
            for (auto [y,w] : g[x]) 
            {
                int nd = w + d;
                if (dis[i][y] > nd) 
                {
                    dis[i][y] = nd;
                    pq.push({nd,y});
                }
            }
        }
    }
    ll ans = LLONG_MAX;
    for (auto& e : edge) 
    {
        int u = e[0],v = e[1];
        ll sum = 0;
        for (auto& q : qs) 
        {
            int a = q[0],b = q[1];
            sum += min({dis[a][b],dis[a][u] + dis[v][b],dis[a][v] + dis[u][b]});
        }
        ans = min(ans,sum);
    }
    cout << ans << endl;
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