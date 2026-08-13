#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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

void solve()
{
    int n;
    cin >> n;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi >> a[i].se;
    map<int,vt> px,py;
    for (int i = 0;i < n;i++)
    {
        px[a[i].se].push_back({a[i].fi});
        py[a[i].fi].push_back({a[i].se});
    }
    ll ans = 0;
    for (auto& [y,g] : px)
    {
        int m = g.size();
        for (int i = 0;i < m;i++) 
        {
            for (int j = i + 1;j < m;j++) 
            {
                int x1 = g[i],x2 = g[j];
                if ((x1 + x2) % 2) continue;
                if (py.count((x1 + x2) / 2)) 
                {
                    for (int x : py[(x1 + x2) / 2]) if (x != y) ans++;
                }
            }
        }
    }
    for (auto& [x,g] : py)
    {
        int m = g.size();
        for (int i = 0;i < m;i++) 
        {
            for (int j = i + 1;j < m;j++) 
            {
                int x1 = g[i],x2 = g[j];
                if ((x1 + x2) % 2) continue;
                if (px.count((x1 + x2) / 2)) 
                {
                    for (int y : px[(x1 + x2) / 2]) if (x != y) ans++;
                }
            }
        }
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