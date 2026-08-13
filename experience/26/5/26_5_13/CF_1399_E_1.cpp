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

struct edges{
    int u,v,w,id;
};
struct tlll{
    ll x,w,c;
    bool operator < (const tlll& other) const
    {
        ll w2 = other.w,c2 = other.c;
        return w * c - w / 2 * c < w2 * c2 - w2 / 2 * c2;
    }
};  
void solve()
{
    ll n,s;
    cin >> n >> s;
    vvpii g(n);
    vector<edges> edge;
    map<ll,int> p;
    auto f = [&](int x, int y) {return 1LL * 1e6 * x + y;};
    for (int i = 1;i < n;i++) 
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        edge.push_back({u,v,w,i - 1});
        int x = min(u,v),y = max(u,v);
        p[f(x,y)] = i - 1;
    }
    vt cnt(n - 1);
    auto dfs = [&](auto&& self,int u,int fa) -> int
    {
        if (g[u].size() == 1 && fa != -1) return 1;
        int res = 0;
        for (auto& [v,w] : g[u])
        {
            if (v == fa) continue;
            int c = self(self,v,u);
            res += c;
            int x = min(u,v),y = max(u,v);
            int id = p[f(x,y)];
            cnt[id] += c;
        }
        return res;
    };
    dfs(dfs,0,-1);
    ll sum = 0;
    pqueue<tlll> pq;
    for (int i = 0;i < n - 1;i++)
    {
        ll x = 1LL * edge[i].w * cnt[i];
        sum += x;
        tlll tmp = {x,edge[i].w,cnt[i]};
        pq.push(tmp);
    }
    ll ans = 0;
    while (sum > s)
    {
        auto [x,w,c] = pq.top();
        pq.pop();
        sum -= x;
        w /= 2;
        x = 1LL * w * c; 
        sum += x;
        tlll tmp = {x,w,c};
        pq.push(tmp);
        ans++;
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