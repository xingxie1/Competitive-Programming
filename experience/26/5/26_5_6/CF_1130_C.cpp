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
    int n;
    cin >> n;
    int x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;y1--;x2--;y2--;
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt dd = {{-1,0},{1,0},{0,-1},{0,1}};
    UnionFind uf(n * n);
    auto getid = [&](int x,int y)
    {
        return x * n + y;
    };
    vvt vis(n,vt(n));
    auto bfs = [&](int x1,int y1)
    {
        queue<pii> q;
        q.push({x1,y1});
        vis[x1][y1] = 1;
        int sid = getid(x1,y1);
        while (!q.empty()) 
        {
            auto [x,y] = q.front();
            q.pop();
            for (int i = 0;i < 4;i++) 
            {
                int nx = x + dd[i][0],ny = y + dd[i][1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= n || a[nx][ny] == '1' || vis[nx][ny]) continue;
                int id = getid(nx,ny);
                vis[nx][ny] = 1;
                q.push({nx,ny});
                uf.merge(sid,id);
            }
        }
    };
    bfs(x1,y1);
    bfs(x2,y2);
    int id1 = getid(x1,y1);
    int id2 = getid(x2,y2);
    if (uf.is_same(id1,id2)) 
    {
        cout << 0 << endl;
        return ;
    }
    int ans = INT_MAX;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < n;j++) 
        {
            for (int i1 = 0;i1 < n;i1++)
            {
                for (int j1 = 0;j1 < n;j1++) 
                {
                    int id11 = getid(i,j);
                    int id22 = getid(i1,j1);
                    if (uf.is_same(id11,id1) && uf.is_same(id22,id2)) 
                    {
                        int dx = i - i1,dy = j - j1;
                        ans = min(ans,dx * dx + dy * dy);
                    }
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