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

// 对于每个右端点 i，计算所有子数组的或值，打印这些或值的分布范围（子数组左端点范围）
// 时间复杂度 O(nlogU)，其中 U = max(nums)
void logTrick(vector<int>& nums) {
    vector<pair<int, int>> gcd_left; // (子数组或值，最小左端点)
    for (int i = 0; i < nums.size(); i++) {
        int x = nums[i];
        // 计算以 i 为右端点的子数组或值
        for (auto& [gcd_val, _] : gcd_left) {
            gcd_val = gcd(gcd_val,x); // 根据题目修改
        }
        // x 单独一个数作为子数组
        gcd_left.emplace_back(x, i);

        // 原地去重（相同或值只保留最左边的）
        int m = 1;
        for (int j = 1; j < gcd_left.size(); j++) {
            if (gcd_left[j].first != gcd_left[j - 1].first) {
                gcd_left[m++] = gcd_left[j];
            }
        }
        gcd_left.resize(m);

        cout << i << " " << x << endl;
        for (int k = 0; k < m; k++) {
            auto [gcd_val, left] = gcd_left[k];
            int right = k + 1 < m ? gcd_left[k + 1].second - 1 : i;
            // 对于左端点在 [left, right]，右端点为 i 的子数组，OR 值都是 or_val
            cout << left << " " << right << " " << gcd_val << endl;
        }
    }
}

void solve()
{
    int n,q;
    cin >> n >> q;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvt qs(q);
    for (int i = 0;i < q;i++) 
    {
        int l,r;
        cin >> l >> r;
        l--;r--;
        qs[i] = {l,r,i};
    }
    sort(qs.begin(),qs.end(),[&](auto& a,auto& b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    int i = 0;
    vll ans(q);
    vpll gcd_left;
    for (auto& t : qs) 
    {
        int l = t[0],r = t[1],id = t[2];
        while (i <= r)
        {
            ll x = a[i];
            for (auto& [gcd_val, _] : gcd_left) 
            {
                gcd_val = gcd(gcd_val,x);
            }
            int m = 1;
            gcd_left.emplace_back(x, i);
            for (int j = 1; j < gcd_left.size(); j++) 
            {
                if (gcd_left[j].first != gcd_left[j - 1].first) 
                {
                    gcd_left[m++] = gcd_left[j];
                }
            }
            gcd_left.resize(m);
            i++;
        }
        for (int k = 0; k < gcd_left.size(); k++) 
        {
            auto [gcd_val, left] = gcd_left[k];
            int right = k + 1 < gcd_left.size() ? gcd_left[k + 1].second - 1 : i - 1;
            // 对于左端点在 [left, right]，右端点为 i 的子数组，OR 值都是 or_val
            if (l >= left && l <= right) 
            {
                ans[id] = gcd_left.size() - k;
                break;
            }
        }
    }
    for (ll x : ans) cout << x << endl;
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