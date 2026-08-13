#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
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
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    ll n,m,k;
    cin >> n >> m >> k;
    vt a(m),x(n),y(n),z(n),d(n);
    for (int i = 0;i < m;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> x[i] >> y[i] >> z[i];
    for (int i = 0;i < n;i++) 
    {
        k -= y[i];
        d[i] = z[i] - y[i];
    }
    ranges::sort(a);
    vt idx(n);
    ranges::iota(idx,0);
    ranges::sort(idx,{},[&](int i){return x[i];});
    int j = 0;
    pqueue<pii> pq;
    int ans = 0;
    vt vis(n);
    for (int xx : a)
    {
        while (j < n && x[idx[j]] <= xx) 
        {
            pq.push({d[idx[j]],idx[j]});
            j++;
        }
        if (pq.size()) 
        {
            auto [mx,id] = pq.top();
            pq.pop();
            vis[id] = 1;
            ans++;
        }
    }
    vt b;
    for (int i = 0;i < n;i++) 
    {
        if (!vis[i]) 
        {
            b.push_back(d[i]);
        }
    }
    ranges::sort(b);
    for (int x : b)
    {
        if (k >= x) 
        {
            k -= x;
            ans++;
        }
        else break;
    }
    cout << ans << endl;

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