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
const int MOD = 998244353;
//const int MOD = (int)1e9+7;

const int MX = 300001;
ll F[MX];     // F[i] = i!
ll INV_F[MX]; // INV_F[i] = i!^-1 = qpow(i!, MOD-2)

ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

auto init = []
{
    F[0] = 1;
    for (int i = 1; i < MX; i++)
    {
        F[i] = F[i - 1] * i % MOD;
    }

    INV_F[MX - 1] = qpow(F[MX - 1], MOD - 2);
    for (int i = MX - 1; i; i--)
    {
        INV_F[i - 1] = INV_F[i] * i % MOD;
    }
    return 0;
}();

// 从 n 个数中选 m 个数的方案数
ll comb(int n, int m)
{
    return m < 0 || m > n ? 0 : F[n] * INV_F[m] % MOD * INV_F[n - m] % MOD;
}


// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
class UnionFind
{
    vector<int> fa; // 代表元
    vector<int> sz; // 集合大小
    vector<int> cnt; // 边数

public:
    int cc; // 连通块个数
    ll ans;

    UnionFind(int n) : fa(n), sz(n, 1), cc(n), cnt(n), ans(1)
    {
        // 一开始有 n 个集合 {0}, {1}, ..., {n-1}
        // 集合 i 的代表元是自己，大小为 1
        ranges::iota(fa, 0); // iota(fa.begin(), fa.end(), 0);
    }

    // 返回 x 所在集合的代表元
    // 同时做路径压缩，也就是把 x 所在集合中的所有元素的 fa 都改成代表元
    int find(int x)
    {
        // 如果 fa[x] == x，则表示 x 是代表元
        if (fa[x] != x)
        {
            fa[x] = find(fa[x]); // fa 改成代表元
        }
        return fa[x];
    }

    // 判断 x 和 y 是否在同一个集合
    bool is_same(int x, int y)
    {
        // 如果 x 的代表元和 y 的代表元相同，那么 x 和 y 就在同一个集合
        // 这就是代表元的作用：用来快速判断两个元素是否在同一个集合
        return find(x) == find(y);
    }

    // 把 from 所在集合合并到 to 所在集合中
    // 返回是否合并成功
    bool merge(int from, int to)
    {
        int x = find(from), y = find(to);
        if (x == y)
        { // from 和 to 在同一个集合，不做合并
            if (cnt[x] == sz[x] - 1) 
            {
                ans = ans * qpow(sz[x],MOD - 2) % MOD * 2 % MOD;
            }
            else ans = 0;
            cnt[x]++;
            return false;
        }
        if (cnt[x] == sz[x] - 1 && cnt[y] == sz[y] - 1)
        {
            ans = ans * qpow(sz[x], MOD - 2) % MOD * qpow(sz[y], MOD - 2) % MOD * (sz[x] + sz[y]) % MOD;
        }
        else if (cnt[x] == sz[x] - 1 && cnt[y] == sz[y])
        {
            ans = ans * qpow(sz[x], MOD - 2) % MOD;
        }
        else if (cnt[x] == sz[x] && cnt[y] == sz[y] - 1)
        {
            ans = ans * qpow(sz[y], MOD - 2) % MOD;
        }
        else if (cnt[x] == sz[x] && cnt[y] == sz[y])
        {
            ans = 0;
        }

        fa[x] = y;      // 合并集合。修改后就可以认为 from 和 to 在同一个集合了
        sz[y] += sz[x]; // 更新集合大小（注意集合大小保存在代表元上）
        cnt[y] += cnt[x] + 1;
        // 无需更新 sz[x]，因为我们不用 sz[x] 而是用 sz[find(x)] 获取集合大小，但 find(x) == y，我们不会再访问 sz[x]
        cc--; // 成功合并，连通块个数减一
        return true;
    }

    // 返回 x 所在集合的大小
    int get_size(int x)
    {
        return sz[find(x)]; // 集合大小保存在代表元上
    }
};

void solve()
{
    int n;
    cin >> n;
    vpii a(n);
    vt tmp;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i].fi >> a[i].se;
        tmp.push_back(a[i].fi);
        tmp.push_back(a[i].se);
    }
    ranges::sort(tmp);
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    int m = tmp.size();
    UnionFind uf(m);
    for (auto& [x,y] : a)
    {
        x = ranges::lower_bound(tmp, x) - tmp.begin();
        y = ranges::lower_bound(tmp, y) - tmp.begin();
        uf.merge(x,y);
        cout << uf.ans << " ";
    }
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