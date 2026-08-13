#include <bits/stdc++.h>
#include <bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using i128 = __int128;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)1e9 + 7;
template <class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;


void solve() {
    int t,h,u; cin >> t >> h >> u;
    int ans = 0;
    int tu = min(t,u);
    ans += tu*4;
    t -= tu;
    u -= tu;

    if((t&1) && h>=1){
        ans += 5;
        t--,h--;
    }
    int tmp = t&1;
    t /= 2;
    int th = min(t,h);
    ans += th*7;
    t -= th;
    h -= th;
    t *= 2;
    t += tmp;

    if(t) ans += 2*(t)+1;
    ans += (h+u)*3;
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _ = 1;
    cin >> _;
    while (_--)
    {
        solve();
    }
    return 0;
}
/*
 *   /\_/\
 *  (= ._.)
 *  / >  \>
 */