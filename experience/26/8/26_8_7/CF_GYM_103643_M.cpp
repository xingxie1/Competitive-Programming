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
    int n,m,q;
    cin >> n >> m >> q;
    vll deg(n,n - 1);
    vvt edge(m);
    vvt g(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        deg[u]--;
        deg[v]--;
        g[u].push_back(v);
        g[v].push_back(u);
        edge[i] = {u,v};
    }
    map<int,set<int>> p;
    for (int i = 0;i < n;i++)
    {
        if (deg[i] > 3) continue;
        for (int j = 0;j < n;j++) p[i].insert(j);
        for (int j : g[i]) p[i].erase(j);
    }
    while (q--)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        int ans = 0;
        for (auto& [x,st] : p)
        {
            if (x == u || x == v) continue;
            int cnt = deg[x];
            // cout << cnt << endl;
            if (st.contains(u)) cnt--;
            if (st.contains(v)) cnt--;
            if (cnt <= 1) ans++;
        }
        cout << ans << endl;
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}