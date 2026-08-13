#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int mod = 998244353;
int MOD = (int)1e9+7;

const int MX = 110'001; // 根据题目数据范围修改

long long F[MX]; // F[i] = i!
long long INV_F[MX]; // INV_F[i] = i!^-1 = qpow(i!, MOD-2)

long long qpow(long long x, int n) {
    long long res = 1;
    for (; n; n /= 2) {
        if (n % 2) {
            res = res * x % mod;
        }
        x = x * x % mod;
    }
    return res;
}

auto init = [] {
    F[0] = 1;
    for (int i = 1; i < MX; i++) {
        F[i] = F[i - 1] * i % mod;
    }

    INV_F[MX - 1] = qpow(F[MX - 1], mod - 2);
    for (int i = MX - 1; i; i--) {
        INV_F[i - 1] = INV_F[i] * i % mod;
    }
    return 0;
}();

void solve()
{
    int n;
    cin >> n;
    vt a(n + 1);
    for (int i = 0;i < n + 1;i++) cin >> a[i];
    if (n == 1) 
    {
        cout << 1 << endl;
        return ;
    }
    ll s = 0;
    for (int x : a) s += x;
    int x = (s + n - 1) / n; 
    int d = s - (ll)(x - 1) * n; 

    int p = 0;
    for (int i = 1;i <= n;i++)
    {
        if (a[i] == x) p++;
        if (a[i] > x) 
        {
            cout << 0 << endl;
            return ;
        }
    }
    if (p > d || d < 0 || d > n) 
    {
        cout << 0 << endl;
        return;
    }
    ll ans = F[d] * F[n-p] % mod * INV_F[d-p] % mod;
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