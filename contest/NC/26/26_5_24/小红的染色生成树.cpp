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

// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
class UnionFind {
    vector<int> fa; // 代表元
    vector<int> sz; // 集合大小

public:
    int cc; // 连通块个数

    UnionFind(int n) : fa(n), sz(n, 1), cc(n) {
        // 一开始有 n 个集合 {0}, {1}, ..., {n-1}
        // 集合 i 的代表元是自己，大小为 1
        ranges::iota(fa, 0); // iota(fa.begin(), fa.end(), 0);
    }

    // 返回 x 所在集合的代表元
    // 同时做路径压缩，也就是把 x 所在集合中的所有元素的 fa 都改成代表元
    int find(int x) {
        // 如果 fa[x] == x，则表示 x 是代表元
        if (fa[x] != x) {
            fa[x] = find(fa[x]); // fa 改成代表元
        }
        return fa[x];
    }

    // 判断 x 和 y 是否在同一个集合
    bool is_same(int x, int y) {
        // 如果 x 的代表元和 y 的代表元相同，那么 x 和 y 就在同一个集合
        // 这就是代表元的作用：用来快速判断两个元素是否在同一个集合
        return find(x) == find(y);
    }

    // 把 from 所在集合合并到 to 所在集合中
    // 返回是否合并成功
    bool merge(int from, int to) {
        int x = find(from), y = find(to);
        if (x == y) { // from 和 to 在同一个集合，不做合并
            return false;
        }
        fa[x] = y; // 合并集合。修改后就可以认为 from 和 to 在同一个集合了
        sz[y] += sz[x]; // 更新集合大小（注意集合大小保存在代表元上）
        // 无需更新 sz[x]，因为我们不用 sz[x] 而是用 sz[find(x)] 获取集合大小，但 find(x) == y，我们不会再访问 sz[x]
        cc--; // 成功合并，连通块个数减一
        return true;
    }

    // 返回 x 所在集合的大小
    int get_size(int x) {
        return sz[find(x)]; // 集合大小保存在代表元上
    }
};
void solve()
{
    int n,m;
    cin >> n >> m;
    vvt edge;
    for (int i = 0;i < m;i++) 
    {
        int u,v, w;
        cin >> u >> v >> w;
        u--;v--;
        edge.push_back({u,v,w});
    }
    auto f = [&](int t1,int t2)
    {
        UnionFind uf(n);
        vpii ans;
        int f0 = 0,f1 = 0;
        for (int i = 0;i < edge.size();i++)
        {
            auto e = edge[i];
            int u = e[0],v = e[1],w = e[2];
            if ((w == t1 || w == t2) && !uf.is_same(u,v)) 
            {
                uf.merge(u,v);
                if (w == t1) f0 = 1;
                if (w == t2) f1 = 1;
                ans.push_back({u,v});
                break;
            }
        }
        for (int i = 0;i < m;i++) 
        {
            auto e = edge[i];
            int u = e[0],v = e[1],w = e[2];
            if (f0)
            {
                if (w == t2 && !uf.is_same(u,v)) 
                {
                    uf.merge(u,v);
                    ans.push_back({u,v});
                    f1 = 1;
                    break;
                }
            }
            else if (f1)
            {
                if (w == t1 && !uf.is_same(u,v))
                {
                    uf.merge(u,v);
                    ans.push_back({u,v});
                    f0 = 1;
                    break;
                }
            }
        }
        for (int i = 0;i < edge.size();i++)
        {
            auto e = edge[i];
            int u = e[0],v = e[1],w = e[2];
            if ((w == t1 || w == t2) && !uf.is_same(u,v)) 
            {
                uf.merge(u,v);
                if (w == t1) f0 = 1;
                if (w == t2) f1 = 1;
                ans.push_back({u,v});
            }
        }
        vpii t;
        if (uf.cc == 1 && f0 && f1) return ans;
        return t;
    };
    vpii ans = f(0,1);
    if (ans.size()) 
    {
        for (auto& [x,y] : ans) cout << x + 1 << " " << y + 1 << endl;
        return ;
    }
    ans = f(0,2);
    if (ans.size()) 
    {
        for (auto& [x,y] : ans) cout << x + 1 << " " << y + 1 << endl;
        return ;
    }
    ans = f(1,2);
    if (ans.size()) 
    {
        for (auto& [x,y] : ans) cout << x + 1 << " " << y + 1 << endl;
        return ;
    }
    cout << -1 << endl;
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