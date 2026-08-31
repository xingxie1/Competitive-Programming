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
    vvt g(n);
    vvt edge;
    vt deg(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
        edge.push_back({u,v});
    }
    vt ans;
    if (m == n * (n - 1) / 2) 
    {
        cout << 3 << endl;
        int f = 0;
        for (auto& e : edge)
        {
            if (e[0] == 0 || e[1] == 0)
            {
                if (!f) 
                {
                    f = 1;
                    ans.push_back(1);
                }
                else ans.push_back(2);
            }
            else ans.push_back(3);
        }
    }
    else 
    {
        cout << 2 << endl;
        int f = -1;
        for (auto& e : edge)
        {
            if (f == -1) 
            {
                if (deg[e[0]] < n - 1) 
                {
                    f = e[0];
                    ans.push_back(1);
                }
                else if (deg[e[1]] < n - 1)
                {
                    f = e[1];
                    ans.push_back(1);
                }
                else ans.push_back(2);
            }
            else 
            {
                if (e[0] == f || e[1] == f)
                {
                    ans.push_back(1);
                }
                else ans.push_back(2);
            }
        }
    }
    for (int x : ans) cout << x << " ";
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