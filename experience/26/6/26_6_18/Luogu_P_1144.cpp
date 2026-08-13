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

int MOD = 100003;
void solve()
{
    int n,m;
    cin >> n >> m;
    vvt g(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        if (u == v) continue;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vt dis(n,INT_MAX / 2);
    vt cnt(n);
    cnt[0] = 1;
    dis[0] = 0;
    pqueue<pii,vpii,greater<>> pq;
    pq.push({0,0});
    while (!pq.empty()) 
    {
        auto [d,x] = pq.top();
        pq.pop();
        if (d > dis[x]) continue;
        for (int y : g[x]) 
        {
            int nd = d + 1;
            if (nd < dis[y]) 
            {
                dis[y] = nd;
                pq.push({nd,y});
                cnt[y] = cnt[x] % MOD;
            }
            else if (nd == dis[y]) 
            {
                cnt[y] += cnt[x];
                cnt[y] %= MOD;
            }
        }
    }
    for (int x : cnt) cout << x << endl;
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