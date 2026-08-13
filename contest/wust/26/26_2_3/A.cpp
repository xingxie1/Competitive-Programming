#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
using pii = pair<int,int>;
using vpii = vector<pair<int,int>>;
#define fi first
#define se second
#define umap unordered_map
#define pqueue priority_queue
int MOD = 998244353;
// int MOD = (int)1e9+7;

ll qpow(ll a, int b) 
{
    ll res = 1;
    while (b)
    {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

vt p(7);
ll f(int x)
{
    ll ret = 1;
    if (x == 0)
    {
        ret = 1LL * p[0] * p[1] * p[2] * (100 - p[3]) * p[4] * p[5] * p[6] % MOD;
    }
    else if (x == 1)
    {
        ret = 1LL * (100 - p[0]) * (100 - p[1]) * p[2] * (100 - p[3]) * (100 - p[4]) * p[5] * (100 - p[6]) % MOD;
    }
    else if (x == 2)
    {
        ret = 1LL * p[0] * (100 - p[1]) * p[2] * p[3] * p[4] * (100 - p[5]) * p[6] % MOD;
    }
    else if (x == 3)
    {
        ret = 1LL * p[0] * (100 - p[1]) * p[2] * p[3] * (100 - p[4]) * p[5] * p[6] % MOD;
    }
    else if (x == 4)
    {
        ret = 1LL * (100 - p[0]) * p[1] * p[2] * p[3] * (100 - p[4]) * p[5] * (100 - p[6]) % MOD;
    }
    else if (x == 5)
    {
        ret = 1LL * p[0] * p[1] * (100 - p[2]) * p[3] * (100 - p[4]) * p[5] * p[6] % MOD;
    }
    else if (x == 6)
    {
        ret = 1LL * p[0] * p[1] * (100 - p[2]) * p[3] * p[4] * p[5] * p[6] % MOD;
    }
    else if (x == 7)
    {
        ret = 1LL * p[0] * (100 - p[1]) * p[2] * (100 - p[3]) * (100 - p[4]) * p[5] * (100 - p[6]) % MOD;
    }
    else if (x == 8)
    {
        ret = 1LL * p[0] * p[1] * p[2] * p[3] * p[4] * p[5] * p[6] % MOD;
    }
    else if (x == 9)
    {
        ret = 1LL * p[0] * p[1] * p[2] * p[3] * (100 - p[4]) * p[5] * p[6] % MOD;
    }
    ll m7 = qpow(100,7);
    return 1LL * ret * qpow(m7,MOD - 2) % MOD;
}
void solve()
{
    int c;
    cin >> c;
    for (int i = 0;i < 7;i++) cin >> p[i];
    ll ans = 0;
    for (int t = 0;t <= c;t++)
    {
        int t1 = t,t2 = c - t;
        vt a,b;
        int cnt = 4;
        while (cnt--)
        {
            a.push_back(t1 % 10);
            t1 /= 10;
            b.push_back(t2 % 10);
            t2 /= 10;
        }
        ll tmp = 1;
        for (int i = 0;i < 4;i++)
        {
            tmp = 1LL * tmp * f(a[i]) % MOD;
            tmp = 1LL * tmp * f(b[i]) % MOD;
        }
        ans = (ans + tmp) % MOD;
    }
    cout << ans << '\n';
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