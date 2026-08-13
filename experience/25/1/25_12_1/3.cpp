#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using vt = vector<int>;
using vll = vector<long long>;
#define fi first
#define se second
int mod = 998244353;
int MOD = (int)1e9+7;

void solve()
{
    int n;
    cin >> n;
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vll pre(n + 1),suf(n + 1);
    for (int i = 0;i < n;i++)
    {
        if (a[i] >= 0) pre[i + 1] = pre[i] + a[i];
        else pre[i + 1] = pre[i];
    }
    for (int i = n - 1;i >= 0;i--)
    {
        if (a[i] < 0) suf[i] = suf[i + 1] - a[i];
        else suf[i] =  suf[i + 1];
    }
    ll ans = 0;
    for (int i = 0;i < n;i++)
    {
        ans = max(ans,pre[i + 1] + suf[i]);
    }
    cout << ans << endl;
    // cout << suf[0] << endl;
    // cout << pre[0] << endl;
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