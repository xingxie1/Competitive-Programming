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
    int n;
    cin >> n;
    vvt g(n);
    for(int i = 1;i < n;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    auto bfs = [&](int st)
    {
        queue<int> q;
        q.push(st);
        vt dis(n,-1);
        dis[st] = 0;
        while (!q.empty()) 
        {
            int x = q.front();
            q.pop();
            for (int y : g[x]) 
            {
                if (dis[y] != -1) continue;
                dis[y] = dis[x] + 1;
                q.push(y);
            }
        }
        int p = st;
        for (int i = 0;i < n;i++) 
        {
            if (dis[i] > dis[p]) p = i;
        }
        return pair<vt,int>(dis,p);
    };
    auto [tmp,s] = bfs(0);
    auto [d1,t] = bfs(s);
    auto [d2,tmp2] = bfs(t);

    int D = d1[t];
    vt cnt(n + 1);
    for (int i = 0;i < n;i++) 
    {
        int mx = max(d1[i],d2[i]);
        cnt[mx]++;
    }
    ll ans = 0;
    for (int k = 1;k <= n;k++) 
    {
        ans += cnt[k - 1];
        if (k <= D) cout << ans + 1 << " ";
        else cout << n << " ";
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