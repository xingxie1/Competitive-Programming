#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    vector<string> a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int N = n * m;
    UnionFind uf(N);
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            if (a[i][j] == '.') continue;
            if (i + 1 < n && a[i + 1][j] == '#') uf.merge(i * m + j,(i + 1) * m + j);
            if (i + 1 < n && a[i + 1][j] == '#') uf.merge(i * m + j,(i + 1) * m + j);
            if (j - 1 >= 0 && a[i][j - 1] == '#') uf.merge(i * m + j,i * m + j - 1);
            if (j + 1 < m && a[i][j + 1] == '#') uf.merge(i * m + j,i * m + j + 1);
        }
    }
    vvt b(n,vt(m));
    int ans = 0;
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < m;j++) 
        {
            b[i][j] = uf.get_size(i * m + j);
            ans = max(ans,b[i][j]);
        }
    }
    //看错题了 艹ccccc
    
    for (int i = 0;i < n;i++)
    {
        for (int j = 0;j < m;j++) 
        {
            if (a[i][j] == '#') continue;
            int s = 1;
            if (i + 1 < n) 
            {
                s += b[i + 1][j];
                if (i - 1 >= 0 && !uf.is_same(i * m + j,(i - 1) * m + j)) s += b[i - 1][j];
                if (j - 1 >= 0 && !uf.is_same(i * m + j - 1,i * m + j) && (i - 1 < 0 || !uf.is_same((i - 1) * m + j,i * m + j))) s += b[i][j - 1];
                if (j + 1 <  m && !uf.is_same(i * m + j,i * m + j + 1) && (j - 1 < 0 || !uf.is_same(i * m + j - 1,i * m + j)) && (i - 1 < 0 || !uf.is_same((i - 1) * m + j,i * m + j))) s += b[i][j + 1];
            }
            else if (i - 1 >= 0) 
            {
                s += b[i - 1][j];
                if (i + 1 < n && !uf.is_same(i * m + j,(i + 1) * m + j)) s += b[i + 1][j];
                if (j - 1 >= 0 && !uf.is_same(i * m + j - 1,i * m + j) && (i + 1 >= n || !uf.is_same((i + 1) * m + j,i * m + j))) s += b[i][j - 1];
                if (j + 1 <  m && !uf.is_same(i * m + j,i * m + j + 1) && (j - 1 < 0 || !uf.is_same(i * m + j - 1,i * m + j)) && (i + 1 >= n || !uf.is_same((i + 1) * m + j,i * m + j))) s += b[i][j + 1];
            }
            else if (j - 1 >= 0) 
            {
                s += b[i][j - 1];
                if (j + 1 < m && !uf.is_same(i * m + j,i * m + j + 1)) s += b[i][j + 1];
                if (i - 1 >= 0 && !uf.is_same((i - 1) * m + j,i * m + j) && (j + 1 >= m || !uf.is_same(i * m + j,i * m + j + 1))) s += b[i - 1][j];
                if (i + 1 < n && !uf.is_same((i + 1) * m + j,i * m + j) && (i - 1 < 0 || !uf.is_same((i - 1) * m + j,i * m + j)) && (j + 1 >= m || !uf.is_same(i * m + j,i * m + j + 1))) s += b[i + 1][j];
            }
            else if (j + 1 < m) 
            {
                s += b[i][j + 1];
                if (j - 1 >= 0 && !uf.is_same(i * m + j,i * m + j - 1)) s += b[i][j - 1];
                if (i - 1 >= 0 && !uf.is_same((i - 1) * m + j,i * m + j) && (j - 1 < 0 || !uf.is_same(i * m + j,i * m + j - 1))) s += b[i - 1][j];
                if (i + 1 < n && !uf.is_same((i + 1) * m + j,i * m + j) && (i - 1 < 0 || !uf.is_same((i - 1) * m + j,i * m + j)) && (j - 1 < 0 || !uf.is_same(i * m + j,i * m + j - 1))) s += b[i + 1][j];
            }
            ans = max(ans,s);
        }
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