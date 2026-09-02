#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

void solve()
{
    int n = 10;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    ll ans = 0;
    for (int i = 0;i < n;i += 2) 
    {
        ans += a[i] * a[i + 1];
    }
    ans /= 5;
    int x,y;
    cin >> x >> y;
    ans *= x;
    ans /= y;
    cout << ans << endl;
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    // cin >> _;
    while (_--) solve();
}