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
    vvvt g(n);
    for (int i = 0;i < m;i++)
    {
        int u,v,d,r;
        cin >> u >> v >> d >> r;
        u--;v--;
        g[u].push_back({v,d,r});
    }
    vpll dis(n,{LLONG_MAX / 2,LLONG_MAX / 2});
    dis[0] = {0,0};
    pqueue<trl,vtrl,greater<>> pq;
    pq.push({0,0,0});
    while (!pq.empty())
    {
        auto [d1,d2,x] = pq.top();
        pq.pop();
        if (x == n - 1)
        {
            cout << d1 << " " << d2 << endl;
            return ;
        }
        if (pair{d1,d2} > dis[x]) continue;
        for (auto& f : g[x])
        {
            int y = f[0],d = f[1],r = f[2];
            ll nd1 = d1 + d;
            ll nd2 = d2 + r;
            if (pair{nd1,nd2} < dis[y]) 
            {
                dis[y] = pair{nd1,nd2};
                pq.push({nd1,nd2,y});
            }
        }
    }
    cout << "-1 -1" << endl;
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