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

pair<vector<int>, vector<int>> nearestGreater(vector<int>& nums) {
    int n = nums.size();
    // left[i] 是 nums[i] 左侧最近的严格大于 nums[i] 的数的下标，若不存在则为 -1
    vector<int> left(n);
    vector<int> st{-1}; // 哨兵
    for (int i = 0; i < n; i++) {
        int x = nums[i];
        while (st.size() > 1 && nums[st.back()] >= x) { // 如果求严格小于，改成 >=
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
        while (st.size() > 1 && nums[st.back()] >= x) {  // 如果求严格小于，改成 >=
            st.pop_back();
        }
        right[i] = st.back();
        st.push_back(i);
    }

    return {left, right};
}

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    auto [left,right] = nearestGreater(a);
    vt ans(n + 1);
    for (int i = 0;i < n;i++) 
    {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len],a[i]);
    }
    for (int i = n - 1;i >= 1;i--) 
    {
        ans[i] = max(ans[i],ans[i + 1]);
    }
    for (int i = 1;i <= n;i++) cout << ans[i] << " ";
    cout << endl;
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