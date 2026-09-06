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
    int n;
    cin >> n;
    vvt edge;
    for (int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        edge.push_back({u,v});
    }
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int u = -1,v = -1;
    for (int i = 0;i < n - 1;i++)
    {
        int x = edge[i][0],y = edge[i][1];
        if (a[x] != a[y]) 
        {
            u = x;
            v = y;
            break;
        }
    }
    if (u == -1)
    {
        YES;
        cout << 1 << endl;
        return ;
    }
    auto check = [&](int x)
    {
        for (auto& e : edge)
        {
            int u = e[0],v = e[1];
            if (a[u] != a[v] && x != u && v != x) 
            {
                return false;
            }
        }
        return true;
    };
    if (check(u)) 
    {
        YES;
        cout << u + 1 << endl;
    }
    else if (check(v)) 
    {
        YES;
        cout << v + 1 << endl;
    }
    else NO;

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