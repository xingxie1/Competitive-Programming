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
// 根据题目用 FenwickTree<int> t(n) 或者 FenwickTree<long long> t(n) 初始化
template<typename T = int >
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

    // 找到最小的下标 pos，满足 a[1] + ... + a[pos] >= k
    // 要求树状数组中维护的是频率/个数，并且 k >= 1 且 k <= pre(n)
    // 时间复杂度 O(log n)
    int kth(T k) const {
        int pos = 0;
        int bit = 1;

        while ((bit << 1) < tree.size()) {
            bit <<= 1;
        }

        for (; bit; bit >>= 1) {
            int nxt = pos + bit;

            if (nxt < tree.size() && tree[nxt] < k) {
                pos = nxt;
                k -= tree[nxt];
            }
        }

        return pos + 1;
    }
};
void solve()
{
    int ac,dr;
    cin >> ac >> dr;
    int n;
    cin >> n;
    vt a(n),d(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> d[i];
    map<int,int> cnt;
    FenwickTree tr(5e6);
    for (int i = 0;i < n;i++) 
    {
        int x = a[i] - ac,y = d[i] - dr;
        int sum = max(x,0) + max(y,0) + 1;
        cnt[sum]++;
        tr.update(sum,1);
    }
    int m;
    cin >> m;
    while (m--)
    {
        int k,na,nd;
        cin >> k >> na >> nd;
        k--;
        int x = a[k] - ac,y = d[k] - dr;
        int sum = max(x,0) + max(y,0) + 1;
        cnt[sum]--;
        tr.update(sum,-1);
        a[k] = na;
        d[k] = nd;
        x = a[k] - ac,y = d[k] - dr;
        sum = max(x,0) + max(y,0) + 1;
        tr.update(sum,1);
        cnt[sum]++;
        int l = 0,r = 5e6;
        auto check = [&](int x)
        {
            return tr.pre(x - 1) + (cnt.count(x) ? cnt[x] : 0) >= x;
        };
        while (l + 1 < r)
        {
            int m = l + r >> 1;
            if (check(m)) l = m;
            else r = m;
        }
        // cout << l << " " << tr.pre(l - 1) << " " << cnt[l] << endl;
        cout << l << endl;
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