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
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
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

template <typename T>
class SparseTable {
    vector<vector<T>> st_gcd;

public:
    // 时间复杂度 O(n * log n)
    SparseTable(const vector<T>& nums) {
        size_t n = nums.size();
        int w = bit_width(n);
        st_gcd.resize(w, vector<T>(n));

        // 长度为 1 的区间
        for (int j = 0; j < n; j++) {
            st_gcd[0][j] = nums[j];
        }

        // st_gcd[i][j] 表示从 j 开始，长度为 2^i 的区间 gcd
        for (int i = 1; i < w; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                st_gcd[i][j] = gcd(
                    st_gcd[i - 1][j],
                    st_gcd[i - 1][j + (1 << (i - 1))]
                );
            }
        }
    }

    // 查询区间 gcd
    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    T query_gcd(int l, int r) const {
        int k = bit_width((uint32_t)(r - l)) - 1;

        // gcd 满足可重复贡献性质：
        // 两段区间可以重叠，不影响 gcd 的结果
        return gcd(st_gcd[k][l], st_gcd[k][r - (1 << k)]);
    }
};
void solve()
{
    ll n, k;
    cin >> n >> k;
    vll a(n),diff(n),suf(n + 1);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = n - 1;i >= 0;i--) suf[i] = gcd(suf[i + 1],a[i]);
    for (int i = 0;i < n - 1;i++) diff[i] = abs(a[i] - a[i + 1]);
    SparseTable st(diff);
    ll g = 0;
    ll ans = 0;
    for (int i = 0;i < n;i++) 
    {
        if (gcd(g,a[i]) != g) 
        {
            ans = max(ans,gcd(g,suf[i]));
            ans = max(ans,gcd(g,gcd(a[i] + k,suf[i + 1])));
            if (i + 1 < n) 
            {
                ll g1 = gcd(a[i] + k,a[i + 1] + k);
                ans = max(ans,gcd(g,gcd(g1,suf[i + 2])));
            }
            for (int r = i + 2;r < n;r++) 
            {
                ll g1 = st.query_gcd(i,r);
                ll g2 = suf[r + 1];
                ans = max(ans,gcd(g1,gcd(g2,gcd(a[r] + k,g))));
            }
        }   
        g = gcd(a[i],g);
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