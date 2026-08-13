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
    vector<T> a1;
    vector<T> a2;
    vector<T> treeMax;
    vector<T> treeMin;
    int n;

    T inf = numeric_limits<T>::max();
    T neg_inf = numeric_limits<T>::lowest();

public:
    FenwickMinMax(int n) : n(n), a1(n + 1), a2(n + 1), treeMax(n + 1), treeMin(n + 1) {
        for (int i = 0; i <= n; i++) {
            a1[i] = inf;
            a2[i] = -1;
            treeMax[i] = neg_inf;
            treeMin[i] = inf;
        }
    }

    // 重新计算 treeMax[i] 和 treeMin[i] 维护的区间
    void pull(int i) {
        treeMax[i] = a2[i];
        treeMin[i] = a1[i];

        for (int len = 1; len < (i & -i); len <<= 1) {
            treeMax[i] = max(treeMax[i], treeMax[i - len]);
            treeMin[i] = min(treeMin[i], treeMin[i - len]);
        }
    }

    // a[i] 修改为 val
    // 1 <= i <= n
    // 时间复杂度 O(log^2 n)
    void update(int i, T val) {
        a1[i] = val;
        a2[i] = val;

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
            res = max(res, a2[r]);
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
            res = min(res, a1[r]);
            r--;

            while (r > 0 && r - (r & -r) + 1 >= l) {
                res = min(res, treeMin[r]);
                r -= r & -r;
            }
        }

        return res;
    }

};
void solve()
{
    int n;
    cin >> n;
    vpii a(n);
    for (int i = 0;i < n;i++) cin >> a[i].fi,a[i].se = i;
    ranges::sort(a,{},[&](auto& b){return -b.fi;});
    vt tmp;
    for (auto [l,r] : a) tmp.push_back(l);
    ranges::sort(tmp);
    for (auto& [l,r] : a) l = ranges::lower_bound(tmp,l) - tmp.begin() + 1;
    FenwickMinMax tr1(n + 1),tr2(n + 1);//mn mx
    vt ans(n);
    for (int in = 0;in < n;in++) 
    {
        int j = in;
        while (j < n && a[j].fi == a[in].fi) 
        {
            auto [x,i] = a[j];
            int mn = tr1.queryMin(x,x);
            int mx = tr2.queryMax(x,x);
            tr1.update(x,min(mn,i));
            tr2.update(x,max(mx,i));
            // cout << x << " " << mx << endl;
            j++;
        }
        for (int k = in;k < j;k++) 
        {
            auto [x,i] = a[k];
            int j1 = tr1.queryMin(x,n);
            int j2 = tr2.queryMax(x,n);
            int mn = tr1.queryMin(x,x);
            int mx = tr2.queryMax(x,x);
            if (j1 == INT_MAX && j2 == -1) ans[i] = i;
            else if (j1 == INT_MAX) ans[i] = j2;
            else if (j2 == -1) ans[i] = j1;
            else if (abs(i - j1) >= abs(i - j2)) ans[i] = j1;
            else ans[i] = j2;
            // cout << x << " " << i << endl;
            // cout << j1 << " " << j2 << endl;
        }
        in = j - 1;
    }
    for (int x : ans) cout << x << " ";
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