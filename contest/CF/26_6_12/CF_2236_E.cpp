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
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
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

class SparseTable {
    vector<vector<int>> st_min;
    vector<vector<int>> st_max;

public:
    // 时间复杂度 O(n * log n)
    SparseTable(const vector<int>& nums) {
        size_t n = nums.size();
        int w = bit_width(n);
        st_min.resize(w, vector<int>(n));
        st_max.resize(w, vector<int>(n));

        for (int j = 0; j < n; j++) {
            st_min[0][j] = nums[j];
            st_max[0][j] = nums[j];
        }

        for (int i = 1; i < w; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st_min[i][j] = min(st_min[i - 1][j], st_min[i - 1][j + (1 << (i - 1))]);
                st_max[i][j] = max(st_max[i - 1][j], st_max[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    int query_min(int l, int r) const {
        int k = bit_width((uint32_t) r - l) - 1;
        return min(st_min[k][l], st_min[k][r - (1 << k)]);
    }

    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    int query_max(int l, int r) const {
        int k = bit_width((uint32_t) r - l) - 1;
        return max(st_max[k][l], st_max[k][r - (1 << k)]);
    }
};

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
            treeMax[i] = neg_inf;
            treeMin[i] = 0;
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

        T res = neg_inf;

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

        T res = INT_MAX;

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

        T mn = 0;
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
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (n < 2) 
    {
        cout << 0 << endl;
        return ;
    }
    SparseTable st(a);
    int ans = 0;
    for (int len = 1;len <= n / 2;len++) 
    {
        int l = 0,r = 0;
        vpii b;
        vt cnt(n + 1);
        int cc = 0;
        // FenwickMinMax tr(n);
        while (r < n) 
        {
            // int x = tr.queryMin(a[r],a[r]);
            // tr.update(a[r],1 + x);
            cnt[a[r]]++;
            if (cnt[a[r]] == 1) cc++;
            if (r - l + 1 == len) 
            {
                int mx = st.query_max(l,l + len);
                int mn = st.query_min(l,l + len);
                // cout << tr.queryMin(mn,mx) << endl;
                if (mx - mn + 1 == len && cc == len) 
                {
                    b.push_back({mn,mx});
                }
                // int x = tr.queryMin(a[l],a[l]);
                // tr.update(a[l],x - 1);
                cnt[a[l]]--;
                if (cnt[a[l]] == 0) cc--;
                l++;
            }
            r++;
        }
        ranges::sort(b);
        for (int i = 0;i + 1 < b.size();i++) 
        {
            int j = ranges::lower_bound(b,pair{b[i].se + 1,-1}) - b.begin();
            if (j != b.size() && b[j].fi == b[i].se + 1) 
            {
                ans = len;
                break;
            }
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