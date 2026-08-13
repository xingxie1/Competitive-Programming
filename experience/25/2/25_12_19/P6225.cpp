#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

// 模板来源 https://leetcode.cn/circle/discuss/mOr1u6/
// 根据题目用 FenwickTree<int> t(n) 或者 FenwickTree<long long> t(n) 初始化
template<typename T>
class FenwickTree {
    vector<T> tree;

public:
    // 使用下标 1 到 n
    FenwickTree(int n) : tree(n + 1) {}

    // a[i] 增加 val
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    void update(int i, T val) {
        for (; i < tree.size(); i += i & -i) {
            tree[i] ^= val;
        }
    }

    // 求前缀和 a[1] + ... + a[i]
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    T pre(int i) const {
        T res = 0;
        for (; i > 0; i &= i - 1) {
            res ^= tree[i];
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
        return pre(r) ^ pre(l - 1);
    }
};

void solve()
{
    int n,q;
    cin >> n >> q;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    FenwickTree<int> tree1(n),tree2(n);
    for (int i = 0;i < n;i++)
    {
        tree1.update(i + 1,0);
        tree2.update(i + 1,0);
        if (i % 2 == 0) tree1.update(i + 1,a[i]);
        else tree2.update(i + 1,a[i]);
    }
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i,j;
            cin >> i >> j;
            if (i % 2 == 1)
                tree1.update(i,a[i - 1] ^ j);
            else tree2.update(i,a[i - 1] ^ j);
            a[i - 1] = j;
        }
        else 
        {    
            int l,r;
            cin >> l >> r;
            if (l == r) cout << a[l - 1] << endl;
            else if ((r - l + 1) % 2 == 0) cout << 0 << endl;
            else 
            {
                if (l & 1) cout << tree1.query(l,r) << endl;
                else cout << tree2.query(l,r) << endl;;
            }
        }
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