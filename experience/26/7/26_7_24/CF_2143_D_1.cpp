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
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
const int MOD = (int)1e9+7;

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
            tree[i] = (tree[i] + val) % MOD;
        }
    }

    // 求前缀和 a[1] + ... + a[i]
    // 1 <= i <= n
    // 时间复杂度 O(log n)
    T pre(int i) const {
        T res = 0;
        for (; i > 0; i &= i - 1) {
            res = (res + tree[i]) % MOD;
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
        return ((pre(r) - pre(l - 1)) % MOD + MOD) % MOD;
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

long long qpow(long long a,long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ret;
}

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    int mx = ranges::max(a);
    vvll dp(mx + 1,vll(mx + 1));
    dp[0][0] = 1;
    for (int i = 0;i < n;i++)    
    {
        auto ndp = dp;
        for (int x = 0;x <= mx;x++)
        {
            for (int j = 0;j <= mx;j++)
            {
                if (a[i] >= x) ndp[a[i]][j] = (ndp[a[i]][j] + dp[x][j]) % MOD;
                else if (a[i] >= j) ndp[x][a[i]] = (ndp[x][a[i]] + dp[x][j]) % MOD;
            }
        }
        dp = ndp;
    }
    ll ans = 0;
    for (int i = 0;i <= mx;i++) 
    {
        for (int j = 0;j <= mx;j++) ans = (ans + dp[i][j]) % MOD;
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