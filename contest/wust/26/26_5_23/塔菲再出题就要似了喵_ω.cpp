#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt g(32);
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < 31;j++) 
        {
            if (a[i] >> j & 1) 
            {
                g[j].push_back(i);
            }
        }
    }
    vll dis(n + 32,LLONG_MAX);
    dis[0] = 0;
    pqueue<pll,vpll,greater<>> pq;
    pq.push({0,0});
    while (!pq.empty())
    {
        auto [d,x] = pq.top();
        pq.pop();
        if (d > dis[x]) continue;
        if (x < n) 
        {
            for (int j = 0;j < 31;j++) 
            {
                if (a[x] >> j & 1) 
                {
                    int y = j + n;
                    ll nd = d + a[x];
                    if (nd < dis[y]) 
                    {
                        dis[y] = nd;
                        pq.push({nd,y});
                    }

                }
            }
        }
        else 
        {
            int j = x - n;
            for (int y : g[j]) 
            {
                ll nd = d + a[y];
                if (nd < dis[y]) 
                {
                    dis[y] = nd;
                    pq.push({nd,y});
                }
            }
        }
    }
    for (int i = 0;i < n;i++) 
    {
        ll x = dis[i];
        if (x == LLONG_MAX) cout << -1 << " ";
        else cout << x << " ";
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