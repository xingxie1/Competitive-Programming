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

void print_i128(i128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }

    if (x < 0) {
        cout << '-';
        x = -x;
    }

    string s;

    while (x > 0) {
        s.push_back(char('0' + x % 10));
        x /= 10;
    }

    reverse(s.begin(), s.end());
    cout << s;
}

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    map<int,int> cc;
    for (int i = 0;i < n;i++) 
    {
        cin >> a[i];
    }
    vt tmp = a;
    ranges::sort(tmp);
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    int m = tmp.size();
    FenwickTree<ll> cnt(m),sum(m);
    i128 ans = 0;
    for (int i = 0;i < n;i++)
    {
        int x = a[i];
        int id = ranges::lower_bound(tmp,x) - tmp.begin() + 1;
        int c = cnt.pre(id - 1) + cnt.query(id + 1,m);
        ll  s = sum.pre(id - 1) + sum.query(id + 1,m);
        ans += (i128)c * x - s;
        if (cc.count(x + 1) && c) ans += cc[x + 1];
        if (cc.count(x - 1) && c) ans -= cc[x - 1];
        cnt.update(id,1);
        sum.update(id,x);
        cc[x]++;
    }
    print_i128(ans);
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