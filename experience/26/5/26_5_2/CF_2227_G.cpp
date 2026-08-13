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
};
void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll pre(n + 1);
    for (int i = 0;i < n;i++) 
    {
        if (i % 2 == 0) pre[i + 1] = pre[i] + a[i];
        else pre[i + 1] = pre[i] - a[i];
    }
    vll tmp = pre;
    ranges::sort(tmp);
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    int m = tmp.size();
    for (ll& x : pre) 
    {
        auto j = ranges::lower_bound(tmp,x) - tmp.begin() + 1;
        x = j; 
    }
    FenwickTree even(m),odd(m);
    even.update(pre[0],1);
    ll ans = 0;
    int cnt_odd = 0;
    for (int j = 1;j <= n;j++)
    {
        int id = pre[j];
        if (j % 2) 
        {
            ans += even.pre(id - 1);
            odd.update(id,1);
            cnt_odd++;
        }
        else 
        {
            ans += cnt_odd - odd.pre(id);
            even.update(id,1);
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