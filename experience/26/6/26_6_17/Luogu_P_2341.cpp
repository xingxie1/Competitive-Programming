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

struct SCC {
    int n;
    int timer = 0;      // DFS 时间戳
    int sccCnt = 0;     // 强连通分量数量

    vector<vector<int>> g;

    vector<int> dfn;    // dfn[u]：u 第几个被 DFS 到，0 表示没访问过
    vector<int> low;    // low[u]：u 能追溯到的最小 dfn
    vector<int> stk;    // Tarjan 栈
    vector<int> inStk;  // inStk[u]：u 是否还在栈里

    vector<int> belong; // belong[u]：u 所在 SCC 编号，范围 [0, sccCnt)
    vector<int> siz;    // siz[id]：第 id 个 SCC 的点数

    SCC(int n) : n(n) {
        g.assign(n, {});
        dfn.assign(n, 0);
        low.assign(n, 0);
        inStk.assign(n, 0);
        belong.assign(n, -1);
    }

    void addEdge(int u, int v) {
        g[u].push_back(v);
    }

    void dfs(int u) {
        dfn[u] = low[u] = ++timer;
        stk.push_back(u);
        inStk[u] = 1;

        for (int v : g[u]) {
            if (!dfn[v]) {
                // 树边
                dfs(v);
                low[u] = min(low[u], low[v]);
            } else if (inStk[v]) {
                // v 还在栈里，说明 u 可以回到当前 SCC 里的某个祖先
                low[u] = min(low[u], dfn[v]);
            }
        }

        // 如果 low[u] == dfn[u]，说明 u 是一个 SCC 的根
        if (low[u] == dfn[u]) {
            int sz = 0;

            while (true) {
                int x = stk.back();
                stk.pop_back();
                inStk[x] = 0;

                belong[x] = sccCnt;
                sz++;

                if (x == u) break;
            }

            siz.push_back(sz);
            sccCnt++;
        }
    }

    int work() {
        for (int i = 0; i < n; i++) {
            if (!dfn[i]) {
                dfs(i);
            }
        }

        return sccCnt;
    }

    // 缩点建 DAG
    vector<vector<int>> buildDAG() {
        vector<vector<int>> dag(sccCnt);

        for (int u = 0; u < n; u++) {
            for (int v : g[u]) {
                int a = belong[u];
                int b = belong[v];

                // 同一个 SCC 内部的边不要
                if (a != b) {
                    dag[a].push_back(b);
                }
            }
        }

        // 去重，不去重通常也能做 DP，但去重更干净
        for (int i = 0; i < sccCnt; i++) {
            sort(dag[i].begin(), dag[i].end());
            dag[i].erase(unique(dag[i].begin(), dag[i].end()), dag[i].end());
        }

        return dag;
    }

    // 如果原图有点权，可以求每个 SCC 的权值和
    template<class T>
    vector<T> getSccWeight(const vector<T>& w) {
        vector<T> sum(sccCnt, 0);

        for (int u = 0; u < n; u++) {
            sum[belong[u]] += w[u];
        }

        return sum;
    }
};

void solve()
{
    int n,m;
    cin >> n >> m;
    SCC scc(n);
    for (int i = 0;i < m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--;v--;
        scc.addEdge(u,v);
    }
    scc.work();
    vvt g = scc.buildDAG();
    int cnt = scc.sccCnt;
    vt deg(cnt);
    for (int i = 0;i < cnt;i++) 
    {
        deg[i] += g[i].size();
    }
    int cc = 0,j = -1;
    for (int i = 0;i < cnt;i++) 
    {
        if (!deg[i]) 
        {
            cc++;
            j = i;
        }
    }
    if (cc == 1) 
    {
        cout << scc.siz[j] << endl;
    }
    else cout << 0 << endl;
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