#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define fi first
#define se second
using ll = long long;
using vt = vector<int>;
using vll = vector<ll>;

void solve()
{
    int n;
    cin >> n;
    vll a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    if (n == 1) 
    {
        cout << a[0] << endl;
        return ;
    }
    if (n == 2) 
    {
        ll ans = 2LL * a[0] + a[1];
        cout << ans << endl;
        return ;
    }
    ll ans = LLONG_MAX / 2;
    ll sum = 0;
    for (int i = 0;i < n - 1;i++)
    {
        ans = min(ans,sum * 2 + 1LL * (n - i - 1) * (a[i] + a[i + 1]) + a[i]);
        sum += a[i];
    }
    ans = min(ans,sum * 2 + a[n - 1]);
    sum = 0;
    for (int i = 0;i < n - 2;i++)
    {
        // cout << ans << " ";
        ans = min(ans,sum * 2 + 1LL * (n - i - 1) * (a[(n - i) % n] + a[(n - (i + 1)) % n]) + a[(n - i) % n]);
        // cout << ans << endl;
        sum += a[(n - i) % n];
        // cout << (n - i) % n << " " << (n - (i + 1)) % n << endl;
    }
    sum += a[2];
    ans = min(ans,sum * 2 + a[1]);
    cout << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int _ = 1;
    cin >> _;
    while (_--) solve();

}