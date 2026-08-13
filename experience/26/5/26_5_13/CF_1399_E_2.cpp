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
    int v,w,co;
};
struct node{
    ll w,c;
    ll val() const 
    {
        return (w - w / 2) * c;
    }
    bool operator < (const node& other) const
    {
        ll w2 = other.w,c2 = other.c;
        return w * c - w / 2 * c < w2 * c2 - w2 / 2 * c2;
    }
};  
void solve()
{
    ll n,s;
    cin >> n >> s;
    vector<vector<edges>> g(n);
    for (int i = 1;i < n;i++) 
    {
        int u,v,w,co;
        cin >> u >> v >> w >> co;
        u--;v--;
        g[u].push_back({v,w,co});
        g[v].push_back({u,w,co});
    }
    ll sum = 0;
    vector<node> e1,e2;
    auto dfs = [&](auto&& self,int u,int fa) -> int
    {
        if (g[u].size() == 1 && fa != -1) return 1;
        int res = 0;
        for (auto [v,w,co] : g[u])
        {
            if (v == fa) continue;
            int c = self(self,v,u);
            res += c;
            sum += 1LL * w * c;
            if (co == 1) e1.push_back({w,c});
            else e2.push_back({w,c});
        }
        return res;
    };
    dfs(dfs,0,-1);
    if (sum <= s) 
    {
        cout << 0 << endl;
        return ;
    }
    auto get = [&](vector<node>& e) 
    {
        pqueue<node> pq;
        for (auto& x : e) pq.push(x);
        vll res;
        res.push_back(0);
        while (!pq.empty()) 
        {
            auto cur = pq.top();
            pq.pop();
            ll d = cur.val();
            if (d == 0) break;
            res.push_back(res.back() + d);
            cur.w /= 2;
            pq.push(cur);
        }
        return res;
    };
    vll a = get(e1);
    vll b = get(e2);
    ll ans = LLONG_MAX / 2;
    ll need = sum - s;
    for (int i = 0;i < a.size();i++) 
    {
        ll rem = need - a[i];
        if (rem <= 0) 
        {
            ans = min(ans,1LL * i);
            continue;
        }
        auto it = ranges::lower_bound(b,rem);
        if (it == b.end()) continue;
        int j = it - b.begin();
        ans = min(ans,i + 2LL * j);
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