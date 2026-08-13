#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define endl '\n'

void solve()
{
    int n;
    ll c, d;
    cin >> n >> c >> d;
    vll a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = a.size();
    ll base = 1LL * (n - m) * c;
    ll ans = 1LL * n * c + d;
    for (int i = 0; i < m; i++)
    {
        ll x = a[i];
        ll del = 1LL * (m - i - 1) * c;
        ll add = 1LL * (x - (i + 1)) * d;
        ans = min(ans, base + del + add);
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_--) solve();

    return 0;
}