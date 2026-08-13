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

// 树状数组维护区间最大值和最小值
// 支持：单点赋值修改 + 区间最大/最小值查询
// 下标 1 到 n
template<typename T = int>
class FenwickMinMax {
    vector<T> a;
    vector<T> treeMax;
    vector<T> treeMin;
    int n;

    T inf = numeric_limits<T>::max();
    T neg_inf = numeric_limits<T>::lowest();

public:
    FenwickMinMax(int n) : n(n), a(n + 1), treeMax(n + 1), treeMin(n + 1) {
        for (int i = 0; i <= n; i++) {
            a[i] = 0;
            treeMax[i] = 0;
            treeMin[i] = inf;
        }
    }

    // 重新计算 treeMax[i] 和 treeMin[i] 维护的区间
    void pull(int i) {
        treeMax[i] = a[i];
        treeMin[i] = a[i];

        for (int len = 1; len < (i & -i); len <<= 1) {
            treeMax[i] = max(treeMax[i], treeMax[i - len]);
            treeMin[i] = min(treeMin[i], treeMin[i - len]);
        }
    }

    // a[i] 修改为 val
    // 1 <= i <= n
    // 时间复杂度 O(log^2 n)
    void update(int i, T val) {
        a[i] = val;

        for (; i <= n; i += i & -i) {
            pull(i);
        }
    }

    // 查询区间最大值 a[l] ~ a[r]
    // 1 <= l <= r <= n
    // 时间复杂度 O(log n)
    T queryMax(int l, int r) const {
        if (r < l) {
            return neg_inf;
        }

        T res = 0;

        while (r >= l) {
            res = max(res, a[r]);
            r--;

            while (r > 0 && r - (r & -r) + 1 >= l) {
                res = max(res, treeMax[r]);
                r -= r & -r;
            }
        }

        return res;
    }

    // 查询区间最小值 a[l] ~ a[r]
    // 1 <= l <= r <= n
    // 时间复杂度 O(log n)
    T queryMin(int l, int r) const {
        if (r < l) {
            return inf;
        }

        T res = inf;

        while (r >= l) {
            res = min(res, a[r]);
            r--;

            while (r > 0 && r - (r & -r) + 1 >= l) {
                res = min(res, treeMin[r]);
                r -= r & -r;
            }
        }

        return res;
    }

    // 同时查询区间最小值和最大值
    // 返回 {最小值, 最大值}
    pair<T, T> query(int l, int r) const {
        if (r < l) {
            return {inf, neg_inf};
        }

        T mn = inf;
        T mx = neg_inf;

        while (r >= l) {
            mn = min(mn, a[r]);
            mx = max(mx, a[r]);
            r--;

            while (r > 0 && r - (r & -r) + 1 >= l) {
                mn = min(mn, treeMin[r]);
                mx = max(mx, treeMax[r]);
                r -= r & -r;
            }
        }

        return {mn, mx};
    }
};
void solve()
{
    int n;
    cin >> n;
    vt a(n),h(n);
    for (int i = 0;i < n;i++) cin >> h[i];
    for (int i = 0;i < n;i++) cin >> a[i];
    vll dp(n);
    FenwickMinMax<ll> tr(n);
    for (int i = 0;i < n;i++) 
    {
        dp[i] = a[i] + tr.queryMax(1,h[i]);
        tr.update(h[i],dp[i]);
    }
    cout << ranges::max(dp) << endl;
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