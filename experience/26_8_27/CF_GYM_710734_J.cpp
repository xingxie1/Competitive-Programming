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

struct EBCC {
    struct Edge {
        int to;
        int id;
    };

    int n;
    int timer = 0;
    int edgeCnt = 0;
    int bccCnt = 0;

    vector<vector<Edge>> g;
    vector<pair<int,int>> edges;

    vector<int> dfn;
    vector<int> low;

    // isBridge[id]：第 id 条边是否为桥
    vector<int> isBridge;

    // belong[u]：u 属于哪个 e-BCC，范围 [0,bccCnt)
    vector<int> belong;

    // siz[id]：第 id 个 e-BCC 的点数
    vector<int> siz;

    // comps[id]：第 id 个 e-BCC 中的所有点
    vector<vector<int>> comps;

    EBCC(int n) : n(n) {
        g.assign(n, {});
        dfn.assign(n, 0);
        low.assign(n, 0);
        belong.assign(n, -1);
    }

    void addEdge(int u, int v) {
        int id = edgeCnt++;

        edges.push_back({u, v});

        g[u].push_back({v, id});
        g[v].push_back({u, id});
    }

    // Tarjan 求桥
    void dfsBridge(int u, int faEdge) {
        dfn[u] = low[u] = ++timer;

        for (auto [v, id] : g[u]) {
            if (!dfn[v]) {
                dfsBridge(v, id);

                low[u] = min(low[u], low[v]);

                // v 的子树无法绕回 u 或 u 的祖先
                if (low[v] > dfn[u]) {
                    isBridge[id] = 1;
                }
            }
            else if (id != faEdge) {
                // 返祖边
                low[u] = min(low[u], dfn[v]);
            }
        }
    }

    // 删除所有桥以后跑连通块
    void dfsBCC(int u, int id) {
        belong[u] = id;
        comps[id].push_back(u);
        siz[id]++;

        for (auto [v, eid] : g[u]) {
            if (isBridge[eid]) {
                continue;
            }

            if (belong[v] == -1) {
                dfsBCC(v, id);
            }
        }
    }

    int work() {
        isBridge.assign(edgeCnt, 0);

        // 1. 求桥
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) {
                dfsBridge(i, -1);
            }
        }

        // 2. 删除桥后求连通块
        for (int i = 0; i < n; i++) {
            if (belong[i] == -1) {
                comps.push_back({});
                siz.push_back(0);

                dfsBCC(i, bccCnt);

                bccCnt++;
            }
        }

        return bccCnt;
    }

    // e-BCC 缩点
    // 原图连通 -> 得到一棵 bridge tree
    // 原图不连通 -> 得到 bridge forest
    vector<vector<int>> buildTree() {
        vector<vector<int>> tree(bccCnt);

        for (int id = 0; id < edgeCnt; id++) {
            if (!isBridge[id]) {
                continue;
            }

            auto [u, v] = edges[id];

            int a = belong[u];
            int b = belong[v];

            tree[a].push_back(b);
            tree[b].push_back(a);
        }

        return tree;
    }

    int bridgeCount() {
        return count(isBridge.begin(), isBridge.end(), 1);
    }

    vector<int> getBridges() {
        vector<int> res;

        for (int i = 0; i < edgeCnt; i++) {
            if (isBridge[i]) {
                res.push_back(i);
            }
        }

        return res;
    }
};

void solve()
{
    int n,m;
    cin >> n >> m;
    vvt e(n);
    EBCC ebcc(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        ebcc.addEdge(u,v);
    }
    int k = ebcc.work();
    int bridgecnt = ebcc.bridgeCount();
    if (bridgecnt == 0)
    {
        cout << 0 << " " << 1LL * n * (n - 1) / 2 << endl;
        return ;
    }
    auto g = ebcc.buildTree();
    vll dis(k),cnt(k);
    int mx = -1;
    ll ways = 0;
    auto dfs = [&](auto&& self,int u,int fa) -> void
    {
        dis[u] = 0;
        cnt[u] = ebcc.siz[u];
        for (int v : g[u])
        {
            if (v == fa) continue;
            self(self,v,u);
            int len = dis[u] + dis[v] + 1;
            ll cur = cnt[u] * cnt[v];
            if (len > mx)
            {
                mx = len;
                ways = cur;
            }
            else if (len == mx) ways += cur;
            int nd = dis[v] + 1;
            if (nd > dis[u])
            {
                dis[u] = nd;
                cnt[u] = cnt[v];
            }
            else if (nd == dis[u]) 
            {
                cnt[u] += cnt[v];
            }
        }
    };
    dfs(dfs,0,-1);
    cout << bridgecnt - mx << " " << ways << endl;

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