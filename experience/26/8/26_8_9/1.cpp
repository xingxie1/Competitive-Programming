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

class SparseTable {
    vector<vector<ll>> st_min;
    vector<vector<ll>> st_max;

public:
    // 时间复杂度 O(n * log n)
    SparseTable(const vector<ll>& nums) {
        size_t n = nums.size();
        // int w = __bit_width(1u * n);
        int w = 0,N = n;
        while (N) 
        {
            w++;
            N /= 2;
        }
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
    ll query_min(int l, int r) const {
        // int k = __bit_width((uint32_t) r - l) - 1;
        int k = 0,N = r - l;
        while (N) 
        {
            k++;
            N /= 2;
        }
        k--;
        return min(st_min[k][l], st_min[k][r - (1 << k)]);
    }

    // [l, r) 左闭右开，下标从 0 开始
    // 必须保证 l < r
    // 时间复杂度 O(1)
    // ll query_max(int l, int r) const {
    //     // int k = __bit_width((uint32_t) r - l) - 1;
    //     int k = 30;
    //     return max(st_max[k][l], st_max[k][r - (1 << k)]);
    // }
};


void solve()
{
    int n;
    cin >> n;
    vll a(n + 1);
    map<int,vt> pos;
    for (int i = 1;i <= n;i++) 
    {
        cin >> a[i];
        pos[a[i]].push_back(i);
    }
    vll suf(n + 2),pre(n + 2);
    ll ans = LLONG_MAX / 2;
    ll mns = LLONG_MAX / 2;
    ll mnp = LLONG_MAX / 2;
    for (int i = 1;i <= n;i++)
    {
        pre[i] = a[i] * i;
        suf[i] = a[i] * (n - i + 1);
        mns = min(mns,suf[i]);
        ans = min(ans,mns + pre[i]);
        // cout << pre[i] << " " << suf[i] << endl;
    }
    // cout << ans << endl;
    int l = 1,r = 1;
    map<int,int> cnt;
    mnp = LLONG_MAX / 2;
    mns = LLONG_MAX / 2;
    SparseTable stp(pre);
    while (r <= n)
    {
        cnt[a[r]]++;
        while (cnt[a[r]] > 1) 
        {
            cnt[a[l++]]--;
        }
        ans = min(ans,stp.query_min(l - 1,r + 1) + suf[r + 1]);
        r++;
    }
    // cout << ans << endl;
    int mnR = n + 1,mxL = 0;
    for (auto& [x,t] : pos)
    {
        if (t.size() == 1) continue;
        int m = t.size();
        mnR = min(mnR,t[1]);
        mxL = max(mxL,t[m - 2]);
    }
    // cout << mxL << " " << mnR << endl;
    for (int i = 1;i <= mnR;i++) 
    {
        ans = min(ans,suf[i]);
    }
    for (int i = mxL;i <= n;i++)
    {
        ans = min(ans,pre[i]);
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