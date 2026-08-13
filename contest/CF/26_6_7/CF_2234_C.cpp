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
    int n;
    cin >> n;
    vector<int> a(2 * n + 5);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = n + 1; i <= 2 * n; i++) {
        a[i] = a[i - n];
    }
    for (int i = 1; i <= n; i++) {
        int l = i, r = i + n - 1;

        vector<int> pre(2 * n + 5), suf(2 * n + 5); 
        for (int j = l; j <= r; j++) {
            pre[j] = max(pre[j - 1], a[j]);
        }
        for (int j = r; j >= l; j--) {
            suf[j] = max(suf[j + 1], a[j]);
        }
        int ans = 0;
        for (int j = l; j < r; j++) {
            ans += min(pre[j], suf[j + 1]);
        }

        // for (int j = l; j <= r; j++) {
        //     cout << pre[j] << " ";
        // }
        // cout << "   6666\n";
        // for (int j = r; j >= l; j--) {
        //     cout << suf[j] << " ";
        // }
        // cout << "\n";

        cout << ans << " ";
    }
    cout << "\n";
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