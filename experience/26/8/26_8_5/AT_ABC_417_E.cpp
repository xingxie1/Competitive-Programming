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
    int n,m,st,ed;
    cin >> n >> m >> st >> ed;
    st--;ed--;
    vvt g(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (auto& e : g)
    {
        ranges::sort(e);
    }
    queue<int> q;
    q.push(st);
    vt used(n);
    used[st] = 1;
    vt pre(n,-1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : g[x])
        {
            if (used[y]) continue;
            vt vis(n);
            auto dfs = [&](auto&& self,int u) -> bool
            {
                if (u == ed) return true;
                int f = 0;
                for (int v : g[u])
                {
                    if (used[v] || vis[v]) continue;
                    vis[v] = 1;
                    f |= self(self,v);
                }
                return f;
            };
            used[y] = 1;
            if (dfs(dfs,y)) 
            {
                used[y] = 1;
                pre[y] = x;
                q.push(y);
                break;
            }
            used[y] = 0;
        }
    }
    int cur = ed;
    vt ans;
    while (cur != -1) 
    {
        ans.push_back(cur);
        cur = pre[cur];
    }
    ranges::reverse(ans);
    for (int x : ans) cout << x + 1 << " ";
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