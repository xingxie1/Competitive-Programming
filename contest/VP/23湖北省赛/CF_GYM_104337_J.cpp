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

pair<vector<int>, vector<int>> nearestGreater(vector<ll>& nums) {
    int n = nums.size();
    // left[i] 是 nums[i] 左侧最近的严格大于 nums[i] 的数的下标，若不存在则为 -1
    vector<int> left(n);
    vector<int> st{-1}; // 哨兵
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        while (st.size() > 1 && nums[st.back()] <= x) { // 如果求严格小于，改成 >=
            st.pop_back();
        }
        left[i] = st.back();
        st.push_back(i);
    }

    // right[i] 是 nums[i] 右侧最近的严格大于 nums[i] 的数的下标，若不存在则为 n
    vector<int> right(n);
    st = {n}; // 哨兵
    for (int i = n - 1; i >= 0; i--) {
        int x = nums[i];
        while (st.size() > 1 && nums[st.back()] <= x) {
            st.pop_back();
        }
        right[i] = st.back();
        st.push_back(i);
    }

    return {left, right};
}

class SparseTable {
    vector<vector<ll>> st_min;
    vector<vector<ll>> st_max;

public:
    // 时间复杂度 O(n * log n)
    SparseTable(const vector<ll>& nums) {
        size_t n = nums.size();
        int w = bit_width(1ull * n);
        st_min.resize(w, vector<ll>(n));
        st_max.resize(w, vector<ll>(n));

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
        int k = bit_width((uint64_t) r - l) - 1;
        return min(st_min[k][l], st_min[k][r - (1 << k)]);
    }

    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    int query_max(int l, int r) const {
        int k = bit_width((uint64_t) r - l) - 1;
        return max(st_max[k][l], st_max[k][r - (1 << k)]);
    }
};

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll pre(n + 1),ppre(n + 1);
    for (int i = 0;i < n;i++) 
    {
        pre[i + 1] = pre[i] + a[i];
        ppre[i + 1] = ppre[i] + pre[i + 1];
    }
    SparseTable st(ppre);
    
    // for (int x : pre) cout << x << " ";
    // cout << endl;
    // for (int x : ppre) cout << x << " ";
    // cout << endl;
    
    if (pre[n] < 0) 
    {
        cout << -1 << endl;
        return ;
    }
    auto [L,R] = nearestGreater(pre);
    int ans = n;
    ll sum = 0;
    for (int i = 1;i <= n;i++)
    {
        int ni = R[i];
        // cout << i << " " << ni << endl;
        ll d = st.query_min(i,ni);
        // cout << ni << " " << i << " " << ppre[ni] << " " << ppre[i] << endl;
        // cout << "d : " << d << endl;

        if (sum + d >= 0)
        {
            sum += d;
        }
        else 
        {
            if (pre[i] < 0) 
            {
                cout << -1 << endl;
                return ;
            }
            ll t = (-d - sum +  pre[i] - 1) / pre[i];
            ans += t;
            sum += t * pre[i];
            sum += d;
            // cout << ans << endl;
        }
        i = ni - 1;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}