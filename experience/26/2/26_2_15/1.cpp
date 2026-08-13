#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vvt = vector<vector<int>>;
using vll = vector<long long>;
using vvll = vector<vector<long long>>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
#define endl '\n'
const int mod = 998244353;
const int MOD = (int)1e9+7;

// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
// 根据题目用 FenwickTree<int> t(n) 或者 FenwickTree<long long> t(n) 初始化
template<typename T = int >
class FenwickTree {
    vector<T> tree;

public:
    // 使用下标 1 到 n
    FenwickTree(int n) : tree(n + 1,-1) {}

    // a[i] 增加 val
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    void update(int i, T val) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] += val;
        }
    }

    // 求前缀和 a[1] + ... + a[i]
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    T pre(int i) const {
        T res = 0;
        for (; i > 0; i &= i - 1) {
            res += tree[i];
        }
        return res;
    }

    // 求区间和 a[l] + ... + a[r]
    // 1 <= l <= r <= n
    // 时间复杂度 O(log n)
    T query(int l, int r) const {
        if (r < l) {
            return 0;
        }
        return pre(r) - pre(l - 1);
    }
};
void solve()
{
    int n, m;
    cin >> n >> m;
    vpii b(m);
    for (int i = 0;i < m;i++) cin >> b[i].fi >> b[i].se;
    int q;
    cin >> q;
    vt c(q);
    for (int i = 0;i < q;i++) cin >> c[i];

    auto check = [&](int x)
    {
        vt a(n,-1);
        for (int i = 0;i < x;i++)
        {
            a[c[i] - 1] = 1;
        }
        vll pre(n + 1);
        for (int i = 0;i < n;i++) pre[i + 1] = pre[i] + a[i];
        for (auto& [L,R] : b)
        {
            // cout << "L : " << L << " R : " << R << endl;
            // cout << pre[R] - pre[L - 1] << endl;
            if (pre[R] - pre[L - 1] > 0) return 1;
        }
        return 0;
    };
    int l = -1,r = q + 1;
    while (l + 1 < r)
    {
        int m = l + (r - l) / 2;
        if (check(m)) r = m;
        else l = m;
    }
    if (r < q + 1) cout << r << endl;
    else cout << -1 << endl;
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