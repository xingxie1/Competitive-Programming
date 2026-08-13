#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using arr2 = array<int, 2>;
using arr3 = array<int, 3>;
const int N = (int)2e5 + 9;
const int M = (int)1e5 + 9;
const int mod = (int)998244353;
ll ksm(ll a, ll b, ll m=mod) {a %= m;ll res = 1;while (b > 0) {if (b & 1) res = res * a % m;a = a * a % m;b >>= 1;}return res;}
int exgcd(int a,int b,int &x,int &y){if(b==0){x=1,y=0;return a;}int d=exgcd(b,a%b,x,y);int z=x;x=y;y=z-y*(a/b);return d;}
int inv(int a,int p){int x,y;exgcd(a,p,x,y);return (x%p+p)%p;}
template<class T>
using ordered_set = tree<
    T,
    null_type,
    less<T>,
    rb_tree_tag,
    tree_order_statistics_node_update>;

void solve() {
    int n, k;
    cin >> n >> k;
    string x, y;
    cin >> x >> y;
    string z = "";
    int cntx = 0, cnty = 0, cntz = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] == '1') cntx++;
        if (y[i] == '1') cnty++;
        if (x[i] == y[i]) z += '0';
        else {
            z += '1';
            cntz++;
        }
    }
    int yv = ((1ll << k) + 1) % 3;
    int cnt = ((1ll << k) + 1) / 3;
    int ans = 0;
    auto cal = [&](int num) -> int {
        return num * (n - num);
    };
    if (yv == 0) {
        ans += (cal(cntx) + cal(cnty) + cal(cntz)) * cnt;
    }
    else {
        ans += (cal(cntx) + cal(cnty) + cal(cntz)) * cnt + cal(cntx) + cal(cnty);
    }
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