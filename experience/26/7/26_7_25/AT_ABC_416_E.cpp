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
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;
const ll INF = 1LL << 60; 

void solve()
{
    int n,m;
    cin >> n >> m;
    vvll dis(n + 1,vll(n + 1,INF));
    for (int i = 0;i < m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        dis[u][v] = min(dis[u][v],1LL * w);
        dis[v][u] = min(dis[v][u],1LL * w);
    }
    ll k,T;
    cin >> k >> T;
    for (int i = 0;i < k;i++)
    {
        int x;
        cin >> x;
        x--;
        dis[x][n] = T;
        dis[n][x] = 0;
    }
    for (int i = 0;i <= n;i++)
    {
        dis[i][i] = 0;
    }
    for (int k = 0;k <= n;k++) 
    {
        for (int i = 0;i <= n;i++) 
        {
            for (int j = 0;j <= n;j++)
            {
                if (dis[i][k] < INF && dis[k][j] < INF) dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1) 
        {
            int x,y,w;
            cin >> x >> y >> w;
            x--;y--;
            auto ndis = dis;
            for (int i = 0;i <= n;i++)
            {
                for (int j = 0;j <= n;j++) 
                {
                    ndis[i][j] = min({ndis[i][j],dis[i][x] + w + dis[y][j],dis[i][y] + w + dis[x][j]});
                }
            }
            ndis[x][y] = min(dis[x][y],1LL * w);
            ndis[y][x] = min(dis[y][x],1LL * w);
            dis = ndis;
        }
        else if (op == 2) 
        {
            int x;
            cin >> x;
            x--;
            auto ndis = dis;
            for (int i = 0;i <= n;i++) 
            {
                for (int j = 0;j <= n;j++) 
                {
                    ndis[i][j] = min({ndis[i][j],dis[i][x] + T + dis[n][j],dis[i][n] + dis[x][j]});
                }
            }
            ndis[x][n] = T;
            ndis[n][x] = 0;
            dis = ndis;
        }
        else 
        {
            ll ans = 0;
            for (int i = 0;i < n;i++) 
            {
                for (int j = 0;j < n;j++) if (dis[i][j] < INF) ans += dis[i][j];
            }
            cout << ans << endl;
        }
    }
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