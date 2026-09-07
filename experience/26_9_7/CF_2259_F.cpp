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
    int n;
    cin >> n;
    vt a(n + 1);
    FenwickTree tr(3 * n);
    for (int i = 1;i <= n;i++) 
    {
        int x;
        cin >> x;
        tr.update(i + n,x);
    }
    int L = n + 1,R = 2 * n;
    string s;
    cin >> s;
    ll ans = 0;
    for (int i = n + 1;i <= 2 * n;i++)
    {
        if (tr.query(i,i))
        {
            ans += 2 * n - i - tr.query(i + 1,2 * n);
        }
    }
    cout << ans << " ";
    if (tr.query(n + 1,2 * n) == 0) 
    {
        for (char c : s) 
        {
            cout << ans << " ";
        }
        cout << endl;
        return ;
    }
    auto l1 = [&]() 
    {
        int l = L - 1,r = R + 1;
        while (l + 1 < r)
        {
            int m = l + r >> 1;
            if (tr.query(L,m)) r = m;
            else l = m;
        }
        return r;
    };
    auto r0 = [&]()
    {
        int l = L - 1,r = R + 1;
        while (l + 1 < r)
        {
            int m = l + r >> 1;
            if (tr.query(m,R) == R - m + 1) r = m;
            else l = m;
        }
        return l;
    };
    for (char c : s)
    {
        if (ans == 0) 
        {
            cout << 0 << " ";
            continue;
        }
        if (c == '1')
        {
            int l = l1();
            // cout << l << " " << R << " " << tr.query(l + 1,R) << endl;
            ans -= R - l - tr.query(l + 1,R);
            tr.update(l,-1);
            int x = tr.query(R + 1,R + 1);
            tr.update(R + 1,1 - x);
            L++;
            R++;
        }
        else 
        {
            int r = r0();
            ans -= tr.query(L,r);
            tr.update(r,1);
            L--;
            R--;
            int x = tr.query(L,L);
            tr.update(L,-x);
        }
        cout << ans << " ";
        // for (int i = 1;i <= 3 * n;i++) cout << tr.query(i,i) << " ";
        // cout << endl;
        // for (int i = 1;i <= 3 * n;i++) cout << i << " ";
        // cout << endl;
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