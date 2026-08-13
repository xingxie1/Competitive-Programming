#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using i128 = __int128;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)5e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)998244353;
template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<int> a(n + 5);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i < k) sum += a[i];
    }
    vector<arr2> b(n + 5);//0 p q
    for (int i = 1; i <= n; i++) {
        b[i][0] = a[i] % p % q;
        b[i][1] = a[i] % q % p;
    }
    vector<int> pre0(n + 5), pre1(n + 5);
    for (int i = 1; i <= n; i++) {
        pre0[i] = pre0[i - 1] + b[i][0];
        pre1[i] = pre1[i - 1] + b[i][1];
    }
    int l = 1;
    int mx = 0, mm = 0;
    int ans = 1e18;
    vector<int> s(n + 5);
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + min(b[i][0], b[i][1]);
    }
    for (int i = k; i <= n; i++) {
        //mx = 0;
        sum += a[i];
        int x0 = pre0[i] - pre0[l - 1];
        int x1 = pre1[i] - pre1[l - 1];
        mm = min(x0, x1);
        // if (mx < sum - x0) {
        //     mx = sum - x0;
        //     mm = x0;
        // }
        // if (mx < sum - x1) {
        //     mx = sum - x1;
        //     mm = x1;
        // }
        ans = min(ans, mm + s[l - 1] + s[n] - s[i]);
        l++;
        sum -= a[l];
    }
    // int ans = mm;
    // for (int i = 1; i < ml; i++) {
    //     ans += min(b[i][0], b[i][1]);
    // }
    // for (int i = mr + 1; i <= n; i++) {
    //     ans += min(b[i][0], b[i][1]);
    // }
    cout << ans << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while(_--) {
        solve();
    }
    return 0;
}
/*
*   /\_/\
*  (= ._.)
*  / >  \>
*/