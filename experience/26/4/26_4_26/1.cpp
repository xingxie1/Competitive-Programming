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

template <typename T>
class SparseTable {
    vector<vector<T>> st_and;
    vector<vector<T>> st_or; 

public:
    // 时间复杂度 O(n * log n)
    SparseTable(const vector<T>& nums) {
        size_t n = nums.size();
        int w = bit_width(n);
        st_and.resize(w, vector<T>(n));
        st_or.resize(w, vector<T>(n));

        for (int j = 0; j < n; j++) {
            st_and[0][j] = nums[j];
            st_or[0][j] = nums[j];
        }

        for (int i = 1; i < w; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st_and[i][j] = st_and[i - 1][j] & st_and[i - 1][j + (1 << (i - 1))];
                st_or[i][j] = st_or[i - 1][j] | st_or[i - 1][j + (1 << (i - 1))];
            }
        }
    }

    // 查询区间按位与 (&)
    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    T query_and(int l, int r) const {
        int k = bit_width((uint32_t) (r - l)) - 1;
        return st_and[k][l] & st_and[k][r - (1 << k)];
    }

    // 查询区间按位或 (|)
    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    T query_or(int l, int r) const {
        int k = bit_width((uint32_t) (r - l)) - 1;
        // 两段区间重叠不影响按位或的结果
        return st_or[k][l] | st_or[k][r - (1 << k)];
    }
};
void solve()
{
    int n,q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    SparseTable<ll> st(a);
    while (q--)
    {
        int l,r;
        cin >> l >> r;
        l--;
        r--;
        cout << st.query_and(l,r + 1) << endl;
    }
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