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
using vvpdd = vector<vector<pair<double,double>>>;
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
    int n,t,st,ed;
    cin >> n >> t >> st >> ed;
    st--;ed--;
    vvt a(n,vt(9));
    vvpdd g(4 * n);
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < 6;j++) cin >> a[i][j];
        cin >> a[i][8];
        auto f = [&](int x1,int y1,int x2,int y2,int x3,int y3)
        {
            int xx1 = x2 - x1;
            int yy1 = y2 - y1;
            int xx2 = x3 - x1;
            int yy2 = y3 - y1;
            if(xx1 * yy1 + xx2 * yy2 == 0)
            {
                return 1;
            }
            return 0;
        };
        if(f(a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5]))
        {
            int xx = a[i][2] + a[i][4];
            int yy = a[i][3] + a[i][5];
            a[i][6] = xx - a[i][0];
            a[i][7] = yy - a[i][1];
        }
        else
        {
            if(f(a[i][2],a[i][3],a[i][0],a[i][1],a[i][4],a[i][5]))
            {
                int xx = a[i][0] + a[i][4];
                int yy = a[i][1] + a[i][5];
                a[i][6] = xx - a[i][2];
                a[i][7] = yy - a[i][3];
            }
            else
            {
                int xx = a[i][0] + a[i][2];
                int yy = a[i][1] + a[i][3];
                a[i][6] = xx - a[i][4];
                a[i][7] = yy - a[i][5];
            }
        }
    }
    for(int i = 0 ; i < n ; i++)
    {
        for(int r = 0 ; r < 4 ; r++)
        {
            for(int j = i + 1; j < n ; j++)
            {
                for(int rj = 0 ; rj < 4 ; rj++)
                {
                    int dx = a[i][r * 2] - a[j][rj * 2];
                    int dy = a[i][r * 2 + 1] - a[j][rj * 2 + 1];
                    double d = sqrt((dx * dx) + (dy * dy));
                    g[i * 4 + r].push_back({j * 4 + rj,d * t});
                    g[j * 4 + rj].push_back({i * 4 + r,d * t});
                }
                
            }
        }
    }
    for (int i = 0;i < n;i++) 
    {
        int w = a[i][8];
        for (int j = 1;j <= 3;j++) 
        {
            int u = i * 4,v = i * 4 + j;
            int dx = a[i][0] - a[i][2 * j];
            int dy = a[i][1] - a[i][2 * j + 1];
            double d = sqrt((dx * dx) + (dy * dy));
            g[u].push_back({v,d * w});
            g[v].push_back({u,d * w});
        }
        for (int j = 2;j <= 3;j++) 
        {
            int u = i * 4 + 1,v = i * 4 + j;
            int dx = a[i][2] - a[i][2 * j];
            int dy = a[i][3] - a[i][2 * j + 1];
            double d = sqrt((dx * dx) + (dy * dy));
            g[u].push_back({v,d * w});
            g[v].push_back({u,d * w});
        }
        int u = i * 4 + 2,v = i * 4 + 3;
        int dx = a[i][4] - a[i][6];
        int dy = a[i][5] - a[i][7];
        double d = sqrt((dx * dx) + (dy * dy));
        g[u].push_back({v,d * w});
        g[v].push_back({u,d * w});
    }
    pqueue<pdd,vpdd,greater<>> pq;
    pq.push({0,st * 4});
    pq.push({0,st * 4 + 1});
    pq.push({0,st * 4 + 2});
    pq.push({0,st * 4 + 2});
    vd dis(4 * n,1e50);
    dis[st * 4] = 0;
    dis[st * 4 + 1] = 0;
    dis[st * 4 + 2] = 0;
    dis[st * 4 + 3] = 0;
    while (!pq.empty())
    {
        auto [d,x] = pq.top();
        pq.pop();
        if (d > dis[x]) continue;
        for (auto& [y,w] : g[x])
        {
            double nd = d + w;
            if (nd < dis[y])
            {
                dis[y] = nd;
                pq.push({nd,y});
            }
        }
    }
    cout << min({dis[ed * 4],dis[ed * 4 + 1],dis[ed * 4 + 2],dis[ed * 4 + 3]});
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(1);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}