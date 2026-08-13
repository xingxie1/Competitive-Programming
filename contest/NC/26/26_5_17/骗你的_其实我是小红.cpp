#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll C2(ll x)
{
    return x * (x - 1) / 2;
}

void solve()
{
    ll l, r, k;
    cin >> l >> r >> k;

    ll n = r - l + 1;

    ll q = n / k;      // 每个模 k 的余数至少出现 q 次
    ll rem = n % k;    // 有 rem 个余数会多出现 1 次

    ll ans = rem * C2(q + 1) + (k - rem) * C2(q);

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}