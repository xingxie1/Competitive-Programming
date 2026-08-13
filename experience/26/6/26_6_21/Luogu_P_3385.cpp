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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
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
    for (int i = 0;i < m;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        if (w >= 0) 
        {
            g[u].push_back({v,w});
            g[v].push_back({u,w});
        }
        else 
        {
            g[u].push_back({v,w});
        }
    }
    auto spfa = [&]() 
    {
        queue<int> q;
        vll dis(n,LLONG_MAX / 2);
        vt cnt(n);
        vt inq(n);
        dis[0] = 0;
        inq[0] = 1;
        q.push(0);
        while (!q.empty()) 
        {
            int x = q.front();
            q.pop();
            inq[x] = 0;
            for (auto& [y,w] : g[x])
            {
                if (dis[y] > dis[x] + w) 
                {
                    cnt[y] = cnt[x] + 1;
                    if (cnt[y] >= n) return true;
                    dis[y] = dis[x] + w;
                    if (!inq[y]) 
                    {
                        inq[y] = 1;
                        q.push(y);
                    }
                }
            }
        }
        return false;
    };
    if (spfa()) YES;
    else NO;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}