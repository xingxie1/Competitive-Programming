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
    ll n,m,k;
    cin >> n >> m >> k;
    vvt g(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<pii> q;
    vvt dis(n,vt(2,INT_MAX / 2));
    dis[0][0] = 0;
    q.push({0,0});
    while (!q.empty())
    {
        auto [x,p] = q.front();
        q.pop();
        for (int y : g[x])
        {
            int nd = dis[x][p] + 1;
            if (nd < dis[y][p ^ 1]) 
            {
                dis[y][p ^ 1] = nd;
                q.push({y,p ^ 1});
            }
        }
    }
    for (int i = 0;i < n;i++)
    {
        if (dis[i][0] == 0 || dis[i][1] == 0) cout << 0 << " ";
        else if (dis[i][0] == INT_MAX / 2 && dis[i][1] == INT_MAX / 2) cout << -1 << " ";
        else 
        {
            ll ans = LLONG_MAX / 2;
            if (dis[i][0] != INT_MAX / 2) 
            {
                int d = (dis[i][0] + k - 1) / k;
                if (k % 2 && d % 2) d++;
                ans = d * k;
            }
            if (k % 2 && dis[i][1] != INT_MAX / 2)
            {
                int d = (dis[i][1] + k - 1) / k;
                if (d % 2 == 0) d++;
                ans = min(ans,1LL * d * k);
            }
            if (ans == LLONG_MAX / 2) cout << -1 << " ";
            else cout << ans << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}