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
    ll n,k,mxb = 0;
    cin >> n >> k;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];

    vll suf(n + 1),pre(n + 1);
    for (int i = 0;i < n;i++)
    {
        pre[i + 1] = max(pre[i],0LL) + a[i];
    }
    for (int i = n - 1;i >= 0;i--)
    {
        suf[i] = max(suf[i + 1],0LL) + a[i];
    }
    ll ans = LLONG_MIN;
    if (k % 2 == 0) 
    {
        for (int i = 1;i <= n;i++) ans = max(ans,pre[i]);
    }
    else 
    {
        for (int i = 0;i < n;i++)
        {
            ans = max(ans,pre[i + 1] + suf[i] - a[i] + b[i]);
        }
    }
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